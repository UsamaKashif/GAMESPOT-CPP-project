#include<iostream>
#include<stdlib.h>
#include<string>
#include <windows.h>>
using namespace std;

char square[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};


char wonBy_ticTacToe;



void reset_sqaures () {
    square[0] = '1';
    square[1] = '2';
    square[2] = '3';
    square[3] = '4';
    square[4] = '5';
    square[5] = '6';
    square[6] = '7';
    square[7] = '8';
    square[8] = '9';
}

int checkwin()
{

    if (square[0] == square[1] && square[1] == square[2])
        return 1;

    else if (square[3] == square[4] && square[4] == square[5])
        return 1;

    else if (square[6] == square[7] && square[7] == square[8])
        return 1;

    else if (square[0] == square[3] && square[3] == square[6])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[0] == square[4] && square[4] == square[8])
        return 1;

    else if (square[2] == square[4] && square[4] == square[6])
        return 1;

    else if (square[0] != '1' && square[1] != '2' && square[2] != '3'
             && square[3] != '4' && square[4] != '5' && square[5] != '6'
             && square[6] != '7' && square[7] != '8' && square[8] != '9')
        return 0;

    else
        return -1;
}

void board_tictactoe()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}


bool tictactoe ()
{
    cout << "=======================================" << endl;
    cout << "               WELCOME " << endl;
    cout << "=======================================" << endl;
    char x;

    cout << " Press A to start " << endl;
    cout << " Press B for instructions " << endl;
    cout << " Please make your choice : ";
    cin >> x;

    if (x == 'a' || x == 'A')
    {
        int player = 1, i, choice;

        char mark;
        do
        {
            board_tictactoe();
            player = (player % 2) ? 1 : 2;

            cout << "Player " << player << ", enter a number:  ";
            cin >> choice;

            mark = (player == 1) ? 'X' : 'O';

            if (choice == 1 && square[0] == '1')

                square[0] = mark;
            else if (choice == 2 && square[1] == '2')

                square[1] = mark;
            else if (choice == 3 && square[2] == '3')

                square[2] = mark;
            else if (choice == 4 && square[3] == '4')

                square[3] = mark;
            else if (choice == 5 && square[4] == '5')

                square[4] = mark;
            else if (choice == 6 && square[5] == '6')

                square[5] = mark;
            else if (choice == 7 && square[6] == '7')

                square[6] = mark;
            else if (choice == 8 && square[7] == '8')

                square[7] = mark;
            else if (choice == 9 && square[8] == '9')

                square[8] = mark;
            else
            {
                cout << "Invalid move ";

                player--;
            }
            i = checkwin();

            player++;
        }
        while (i == -1);
        board_tictactoe();
        if (i == 1)
        {
            cout << "==>\aPlayer " << --player << " win " << endl;
            if (player == 1)
            {
                wonBy_ticTacToe = 'U';
            }
            else
            {
                wonBy_ticTacToe = 'O';
            }
        }
        else
        {
            cout << "==>\aGame draw" << endl;
        }
    }

    else if (x == 'b' || x == 'B')
    {
        cout << " The game is so simple but tricky. The only thing is that you have to focus on your opponent's turn. " << endl;
        cout << " There are no rules. The person who completes first pair of 3 symbols (X or O) in diagonal, horizontal or vertical line will win the match. " << endl;
    }

    else if (x == 'c' || x == 'C')
    {

    }

    cout << endl;
    cout << "=======================================" << endl;
    cout << "               THANKYOU " << endl;
    cout << "=======================================" << endl;


    if (wonBy_ticTacToe == 'U')
    {
        Sleep(3000);
        reset_sqaures();
        return true;
    }
    else
    {
        Sleep(3000);
        reset_sqaures();
        return false;
    }
}

