#include <iostream>

int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char current_player = 'X';
    int total_moves = 0;
    bool game_won = false;

    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "Rules: the winner is the one who gets 3 in a row vertically or horizontally.\n\n";

    while(total_moves < 9 && !game_won) {
        std::cout << "  1   2   3\n";
        for(int i = 0; i < 3; ++i) {
            std::cout << i+1 << " ";
            for(int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if(j < 2) std::cout << " | ";
            }
            std::cout << "\n";
            if(i < 2) std::cout << "  ---------\n";
        }
        std::cout << "\n";
        
        int row, col;
        std::cout << "The player's turn " << current_player << ". Enter a row and column (from 1 to 3 separated by a space):";
        std::cin >> row >> col;

        int r = row - 1;
        int c = col - 1;

        if(r < 0 || r > 2 || c < 0 || c > 2) {
            std::cout << "Mistake! The coordinates should be from 1 to 3. Try again.\n\n";
            continue;
        }

        if(board[r][c] != ' ') {
            std::cout << "Mistake! This cell is already occupied. Try again.\n\n";
            continue;
        }

        board[r][c] = current_player;
        total_moves++;

        for(int i = 0; i < 3; ++i) {
            if(board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player){
                game_won = true;
            }
            if(board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player) {
                game_won = true;
            }

        }

        if(game_won) {
            std::cout << "\nFinal field:\n";
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    std::cout << board[i][j] << (j < 2 ? " | " : "");
                }
                std::cout << "\n" << (i < 2 ? "---------\n" : "");
            }
            std::cout << "Congratulations! Player " << current_player << " won!";
        } else if(total_moves == 9) {
            std::cout << "It's a draw! There are no empty cells left.\n";
        } else {
            if(current_player == 'X') current_player = 'O';
            else current_player = 'X';
        }

    }

    return 0;
}