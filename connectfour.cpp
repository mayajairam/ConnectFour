#include <iostream>
using namespace std;

bool won(char arr[6][7], char y);
bool h_win(char arr[6][7], char y);
bool v_win(char arr[6][7], char y);
bool d_win(char arr[6][7], char y);
void drop(char arr[6][7], int col, int count);
void printboard(char arr[6][7]);

int count = 0;
char board[6][7] = {
    {'_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_'}
};

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

int main() {
    int column;
    printboard(board);
    do {
        cout << "Choose a column: \n";
        cin >> column;
        drop(board, column, count);
        count += 1;
        printboard(board);
    } while (won(board, 'X') == false && won(board, 'O') == false);

    if (won(board, 'X'))
        cout << "Player 1 won!\n";
    if (won(board, 'O'))
        cout << "Player 2 won!\n";
}

bool won(char arr[6][7], char y) {
    if (h_win(arr, y) || v_win(arr, y) || d_win(arr, y)) {
        return true;
    }
    return false;
}

bool h_win(char arr[6][7], char y) {
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 4; c++) {
            if (arr[r][c] == y &&
                arr[r][c] == arr[r][c + 1] &&
                arr[r][c + 1] == arr[r][c + 2] &&
                arr[r][c + 2] == arr[r][c + 3]) {
                return true;
            }
        }
    }
    return false;
}

bool v_win(char arr[6][7], char y) {
    for (int c = 0; c < 7; c++) {
        for (int r = 0; r < 3; r++) {
            if (arr[r][c] == y &&
                arr[r][c] == arr[r + 1][c] &&
                arr[r + 1][c] == arr[r + 2][c] &&
                arr[r + 2][c] == arr[r + 3][c]) {
                return true;
            }
        }
    }
    return false;
}

bool d_win(char arr[6][7], char y) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            if (arr[r][c] == y &&
                arr[r][c] == arr[r + 1][c + 1] &&
                arr[r + 1][c + 1] == arr[r + 2][c + 2] &&
                arr[r + 2][c + 2] == arr[r + 3][c + 3]) {
                return true;
            }
        }
    }
    for (int r = 0; r < 3; r++) {
        for (int c = 6; c >= 3; c--) {
            if (arr[r][c] == y &&
                arr[r][c] == arr[r + 1][c - 1] &&
                arr[r + 1][c - 1] == arr[r + 2][c - 2] &&
                arr[r + 2][c - 2] == arr[r + 3][c - 3]) {
                return true;
            }
        }
    }
    return false;
}

void drop(char arr[6][7], int col, int count) {
    char y = (count % 2 == 0) ? 'X' : 'O';
    for (int r = 5; r >= 0; r--) {
        if (arr[r][col] == '_') {
            arr[r][col] = y;
            return;
        }
    }
}

void printboard(char arr[6][7]) {
    // Clear the screen
    cout << "\033[2J\033[1;1H";
    cout << "\t\t\tWelcome to Connect Four!\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (j == 0) {
                cout << "\t\t\t\t";
            }
            if (arr[i][j] == 'X') {
                cout << RED << arr[i][j] << RESET;
            } else if (arr[i][j] == 'O') {
                cout << YELLOW << arr[i][j] << RESET;
            } else {
                cout << arr[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << "\t\t\t\t0 1 2 3 4 5 6\n";
}
