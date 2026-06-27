#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>


std::string readQuestion(int sector) {
    std::string filename = "question" + std::to_string(sector + 1) + ".txt";
    std::ifstream ifs(filename);
    if (!ifs.is_open()) return "Error: Question file not found (" + filename + ")";

    std::string text, line;
    while (std::getline(ifs, line)) {
        text += line + "\n";
    }
    return text;
}

std::string readAnswer(int sector) {
    std::string filename = "answer" + std::to_string(sector + 1) + ".txt";
    std::ifstream ifs(filename);
    if (!ifs.is_open()) return "";

    std::string ans;
    ifs >> ans;
    return ans;
}

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    std::vector<bool> played(13, false); 
    int currentSector{0};               
    int playerPoints{0};
    int viewerPoints{0};

    cout << "=== Welcome to 'What? Where? When?' ===" << endl << endl;

  
    while (playerPoints < 6 && viewerPoints < 6) {
        cout << "--- CURRENT SCORE ---" << endl;
        cout << "Experts: " << playerPoints << " | Viewers: " << viewerPoints << endl << endl;

        int offset;
        cout << "Spin the wheel! Enter offset: ";
        if (!(cin >> offset)) break;

        
   
        currentSector = (currentSector + (offset % 13) + 13) % 13;


        while (played[currentSector]) {
            currentSector = (currentSector + 1) % 13;
        }


        played[currentSector] = true;
        cout << "Active sector: " << (currentSector + 1) << endl << endl;

  
        cout << "QUESTION:" << endl;
        cout << readQuestion(currentSector) << endl;

   
        std::string playerAnswer;
        cout << "Your answer: ";
        cin >> playerAnswer;

        std::string correctAnswer = readAnswer(currentSector);

        for (char &c : playerAnswer) c = std::tolower(c);
        for (char &c : correctAnswer) c = std::tolower(c);

     
        if (!correctAnswer.empty() && playerAnswer == correctAnswer) {
            cout << endl << "CORRECT! Point to the Experts!" << endl;
            playerPoints++;
        } else {
            cout << endl << "WRONG! Correct answer was: " << readAnswer(currentSector) << endl;
            cout << "Point to the Viewers!" << endl;
            viewerPoints++;
        }
        cout << "========================================" << endl << endl;
    }

  
    cout << "=== GAME OVER ===" << endl;
    if (playerPoints == 6) {
        cout << "Congratulations! The Experts won the game!" << endl;
    } else {
        cout << "The Viewers won the game! Better luck next time." << endl;
    }

    return 0;
}
