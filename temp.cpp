#include <iostream>
using namespace std;

void myPrintBoard(char matrix[3][3]) {
  system("cls");
    cout << "\n\n\t\t ==========$$Akash-Game-Zone$$=================== ";
    cout << " \n\n\t\t__________$$_TIC__TOK__TOE_$$_________________\n\n";
    cout << "       |       |       " << endl;
    cout << "   " << matrix[0][0] << "   |   " << matrix[0][1] << "   |   " << matrix[0][2] << "   " << endl;
    cout << "_______|_______|_______ " << endl;
    cout << "       |       |       " << endl;
    cout << "   " << matrix[1][0] << "   |   " << matrix[1][1] << "   |   " << matrix[1][2] << "   " << endl;
    cout << "_______|_______|_______ " << endl;
    cout << "       |       |       " << endl;
    cout << "   " << matrix[2][0] << "   |   " << matrix[2][1] << "   |   " << matrix[2][2] << "   " << endl;
    cout << "       |       |       " << endl;
}

bool checkWin(char matrix[3][3], char player) { 
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player) ||
            (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player)) {
            return true;
        }
    }
    if ((matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) ||
        (matrix[2][0] == player && matrix[1][1] == player && matrix[0][2] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(char matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != 'X' && matrix[i][j] != '0') {
                return false;
            }
        }
    }
    return true;
}


int main() {
    char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    string Player1, Player2, whoX;

    cout << "\n\n\t\t ==========$$Akash-Game-Zone$$=================== ";
    cout << " \n\n\t\t__________$$_TIC__TOK__TOE_$$_________________\n\n";
    cout << "Enter first Player name : \t";
    cin >> Player1;
    cout << "Enter Second Player name : \t";
    cin >> Player2;
    cout << "\n\n\t\tWe have two choices for you. Choose one ('X' or '0') \n\n";
    cout << "Who will choose '0', Enter your name : \t";
    cin >> whoX;
    
    string playerX = (whoX == Player1) ? Player1 : Player2;
    string playerO = (whoX == Player1) ? Player2 : Player1;

    int digit, i = 1;
    char myCurrentPlayer = 'X';
    
    while (true) {
        myPrintBoard(matrix);

        if (i % 2 == 0) {
            cout << playerX << " (" << myCurrentPlayer << ")\nPlease enter a number between 1 and 9: ";
        } else {
            cout << playerO << " (" << myCurrentPlayer << ")\nPlease enter a number between 1 and 9: ";
        }
        
        cin >> digit;
        
        if (digit < 1 || digit > 9) {
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            continue;
        }
        
        int row = (digit - 1) / 3;
        int col = (digit - 1) % 3;
        
        if (matrix[row][col] == 'X' || matrix[row][col] == '0') {
            cout << "It is already filled. Choose another.\n" << endl;
            continue;
        }
        
        matrix[row][col] = myCurrentPlayer;
        
        if (checkWin(matrix, myCurrentPlayer)) {
            myPrintBoard(matrix);
            cout << "\n\n##-----------## 🎊Congratulation🎊  ##-----------------##\n\n";
            cout << "---------------You completed the match------------------\n";
            cout << "----------------Winner is " << (myCurrentPlayer == 'X' ? playerX : playerO) << "-------------" << endl;
            cout << "-----------------Thank you for playing the Game------------------" << endl;
            cout << "-----------------You both gave a nice performance------------------" << endl;
            cout << "@@@@@@@@@@ ";
            break;
        }

         if (checkDraw(matrix)) {
            myPrintBoard(matrix);
            cout << "\n\n##-----------## 🚀 It's a Draw! 🚀 ##-----------------##\n\n";
            cout << "---------------No more moves possible------------------\n";
            cout << "-----------------Thank you for playing the Game------------------" << endl;
            cout << "-----------------You both gave a nice performance------------------" << endl;
            cout << "@@@@@@@@@@ ";
            break;
        }
        
        myCurrentPlayer = (myCurrentPlayer == 'X') ? '0' : 'X';
        i++;
    }

    return 0;
}
