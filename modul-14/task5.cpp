#include <iostream>

const int SIZE = 12;

void initBubbleWrap(bool wrap[SIZE][SIZE]) 
{
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) 
            wrap[i][j] = true;
    }
}

int printBubbleWrap(bool wrap[SIZE][SIZE])
{
    int remaining_bubbles = 0;

    std::cout << "   ";
    for(int j = 1; j <= SIZE; ++j)
        std::cout << j << (j < 10 ? "  " : " ");
    std::cout << "\n";
    
    for(int i = 0; i < SIZE; ++i)  {
        std::cout << i+1 << (i+1 < 10 ? "  " : " ");
    
        for(int j = 0; j < SIZE; ++j) {
            if(wrap[i][j]) {
                std::cout << "O  ";
                remaining_bubbles++;
            } else {
                std::cout << "X  ";
            }
        }
        std::cout << "\n";
    } 

    std::cout << "\nRemaining bubbles: " << remaining_bubbles << "\n\n";
    return remaining_bubbles;
    
}
bool isOutOfRange(int i, int rangeBottom = 0, int rangeTop = SIZE)
{
    return (i < rangeBottom || i >= rangeTop);
}
enum cor {start, end};
int coords(int a, int b, cor c)
{
    if(c == start) return (a < b ? a : b);
    return (a > b ? a : b);
}

void popRegion(bool wrap[SIZE][SIZE], int r1, int c1, int r2, int c2) 
{
   if(isOutOfRange(r1) || isOutOfRange(c1) || isOutOfRange(r2) || isOutOfRange(c2)) {
        std::cout << "Error! Coordinates are out of range (1-12). Try again!\n\n";
        return;
    }

    int start_row = coords(r1, r2, start);
    int end_row = coords(r1, r2, end);
    int start_col = coords(c1, c2, start);
    int end_col = coords(c1, c2, end);

    for(int i = start_row; i <= end_row; ++i) {
        for(int j = start_col; j <= end_col; ++j) {
            if(wrap[i][j]) {
                wrap[i][j] = false;
                std::cout << "POP! ";
            }
        }
    }
    std::cout << "\n\n";
}

int main() {
    bool bubble_wrap[SIZE][SIZE];
    
    
    initBubbleWrap(bubble_wrap);
    
    std::cout << "--- Welcome to Bubble Wrap Simulator! ---\n\n";

    while (printBubbleWrap(bubble_wrap) > 0) {
        int r1, c1, r2, c2;
        std::cout << "Enter start coordinates (row and column from 1 to 12): ";
        std::cin >> r1 >> c1;
        std::cout << "Enter end coordinates (row and column from 1 to 12): ";
        std::cin >> r2 >> c2;

        popRegion(bubble_wrap, r1 - 1, c1 - 1, r2 - 1, c2 - 1);
    }

    std::cout << "All bubbles are popped! The bubble wrap is completely spent. Goodbye!\n";
    return 0;
}