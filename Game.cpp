// C++ program to run Tic-Tac-Toe game (only works on windows systems)
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int not_repeated(int arr[9], int key, int upto); // To check the repeatition of position
int differentname(char name[], char aname[]);    // To check the difference in names of players (not case sensitive)
void table(char position[]);                     // To print tic tac toe table

int main()
{
    int old_positions[9], loop, winner = 5, i, player_num, new_position;
    char position[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}, pawn[2], player[2][10], strposition[10];
    system("cls");
    cout << "\n\n               WELCOME TO TIC-TAC-TOE\n\n"
         << endl;
    cout << "Instructions to play the game :-" << endl; // Instructions of the game
    cout << "1. Player 1 gets to choose between X and O.\n2. Choose the position in which you want to place your pawn." << endl;
    cout << "3. Positions are indicated by numbers as below.\n4. First player to complete consecutive pawns either verticaly, horizontaly or diagonaly wins." << endl;
    table(position);
    cout << "\n\n";
    system("pause");
    system("cls");

    for (i = 0; i < 2; i++) // Taking the names of players
        for (loop = 0; loop != 1;)
        {
            cout << "Enter player " << i + 1 << " name : ";
            cin >> player[i];
            if (i == 0)
                loop = 1;
            else
            {
                if (differentname(player[0], player[1]))
                    loop = 1;
                else
                    cout << "\n\nNames of both players cannot be same. Try again!!\n\n"
                         << endl;
            }
        }
    cout << "\n\n"
         << endl;

    system("pause");
    system("cls");

    for (loop = 0; loop != 1;) // To take the choice of pawn of player 1
    {
        cout << player[0] << " : Choose Your pawn X or O" << endl;
        cin >> position[0];

        switch (position[0])
        {
        case 'x':
        case 'X':
            pawn[0] = 'X';
            pawn[1] = 'O';
            loop = 1;
            break;
        case 'o':
        case 'O':
            pawn[1] = 'X';
            pawn[0] = 'O';
            loop = 1;
            break;
        default:
            cout << "Not a valid input try again!\n\n";
        }
    }
    cout << "\n\n";
    for (loop = 0; loop < 2; loop++) // To display the pawns of respective players
        cout << "Pawn of " << player[loop] << " is " << pawn[loop] << endl;
    cout << "\n\n"
         << endl;

    system("pause");
    system("cls");

    cout << "              LET'S BEGIN THE GAME" << endl; // Actual game begins here
    for (loop = 0; loop < 10; loop++)                     // Filling the tables with spaces
        position[loop] = ' ';

    for (i = 0; i < 9; i++)
    {
        table(position);
        player_num = i % 2;
        {
            for (loop = 0; loop != 1;) // Taking the position in which the player wants to place their pawn
            {
                cout << player[player_num] << " : "; // Position is taken as string
                cin >> strposition;
                if (strlen(strposition) > 1)
                    new_position = 0;
                else
                    new_position = strposition[0] - '0';
                if (new_position < 1 || new_position > 9)
                {
                    cout << "Wrong input!! try again\n\n";
                    continue;
                }
                if (not_repeated(old_positions, new_position, i)) // Checking the repeatition of the position
                {
                    old_positions[i] = new_position;
                    position[old_positions[i]] = pawn[player_num];
                    loop = 1;
                }
                else
                    cout << "Repeatation of the position is not allowed try again\n"
                         << endl;
            }
        }

        if (i >= 4)
        {
            for (loop = 1; loop < 4; loop++) // Checking matching pawn column-wise
                if (position[loop] == position[loop + 3] && position[loop] == position[loop + 6])
                    for (player_num = 0; player_num < 2; player_num++)
                        if (position[loop] == pawn[player_num])
                            winner = player_num;

            for (loop = 1; loop < 8; loop += 3) // Checking matching pawn row-wise
                if (position[loop] == position[loop + 1] && position[loop] == position[loop + 2])
                    for (player_num = 0; player_num < 2; player_num++)
                        if (position[loop] == pawn[player_num])
                            winner = player_num;

            if (position[1] == position[5] && position[1] == position[9]) // Checking matching pawn \ diagonal-wise
                for (player_num = 0; player_num < 2; player_num++)
                    if (position[5] == pawn[player_num])
                        winner = player_num;

            if (position[3] == position[5] && position[3] == position[7]) // Checking matching pawn / diagonal-wise
                for (player_num = 0; player_num < 2; player_num++)
                    if (position[5] == pawn[player_num])
                        winner = player_num;

            if (winner == 1 || winner == 0) // Showing the winner
            {
                system("cls");
                table(position);
                cout << "\n\n                CONGRATULATIONS!! " << player[winner] << " YOU ARE THE WINNER!!\n\n"
                     << endl;
                cout << "\n\n"
                     << endl;
                system("pause");
                system("cls");

                return 0;
            }
        }
        system("cls");
    }
    cout << "                     GAME OVER NOBODY WON\n\n\n"
         << endl;
    cout << "\n\n"
         << endl;
    system("pause");
    system("cls");

    return 0;
}

int differentname(char name[], char aname[])
{
    if (strlen(name) != strlen(aname))
        return 1;
    else
        for (int i = 0; i < strlen(name); i++)
        {
            if (isalpha(name[i]))
            {
                if (toupper(name[i]) != toupper(aname[i]))
                    return 1;
            }
            else if (name[i] != aname[i])
                return 1;
        }
    return 0;
}

void table(char position[])
{
    cout << " _________________ " << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << position[1] << "  |  " << position[2] << "  |  " << position[3] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << position[4] << "  |  " << position[5] << "  |  " << position[6] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << position[7] << "  |  " << position[8] << "  |  " << position[9] << "  |" << endl;
    cout << "|_____|_____|_____|\n\n"
         << endl;
}

int not_repeated(int arr[9], int key, int upto)
{
    for (int i = 0; i < upto; i++)
        if (arr[i] == key)
            return 0;
    return 1;
}
