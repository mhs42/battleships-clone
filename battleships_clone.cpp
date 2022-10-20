#include <iostream>
#include <stdlib.h>

using namespace std;

void printContinue();
void clearScreen();
void printTypeError();
void printSizes();
void printGrid(char arr[][10]);
void printPlacement(int r, int c);
void placeShips(char gridS[][10]);
void playerTurn(char gridP[][10], char gridS[][10], char gridSS[][10], int &finalcounter,
                 int &counter1, int &counter2, int &counter3, int &counter4, int &counter5);
void sinkShip (char grid[][10], char gridS[][10], char z);

int main()
{
    // Introduction and Instructions
    cout << "Welcome to Battleships!" << endl;
    cout << "\nInstructions are as follows:" << endl;
    cout << "\tYou and your opponent each have 5 ships." << endl;
    cout << "\tBoth of you are required to bomb and sink all of the other\'s ships." << endl;
    cout << "\tBe careful and think wisely though; you only get one bomb per turn!" << endl;
    cout << "\tGood luck and have fun :D" << endl;
    printContinue();
    clearScreen();

    // Initialisation
    char gridS1[10][10], gridS2[10][10], gridP1[10][10], gridP2[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            gridS1[i][j] = '0';
            gridS2[i][j] = '0';
            gridP1[i][j] = '0';
            gridP2[i][j] = '0';
        }
    }

    char choice, choices[5], placed1[5];
    for (int i = 0; i < 5; i++)
    {
        placed1[i] = '0';
        choices[i] = static_cast<char>(i+49);
    }

    // Selection
    cout << "It is now Player 1\'s turn. Player 2 must look away." << endl;
    placeShips(gridS1);
    printContinue();
    clearScreen();
    cout << "It is now Player 2\'s turn. Player 1 must look away." << endl;
    placeShips(gridS2);
    printContinue();
    clearScreen();

    // Game
    int final_counter1 = 0, final_counter2 = 0;
    int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0;
    int counter6 = 0, counter7 = 0, counter8 = 0, counter9 = 0, counter10 = 0;
    cout << "Player 1 Turn\n";
    do
    {
        playerTurn(gridP1, gridS2, gridS1, final_counter1, counter1,
                    counter2, counter3, counter4, counter5);
        if (final_counter1 == 17)
        {
            cout << "Player 1 successfully sunk all the battleships of player 2\n";
            cout << "Player 1 Won the Game\n";
            return 0;
        }
        else
        {
            cout <<"Player 2 Turn\n";
            printContinue();
            clearScreen();
        }
        playerTurn(gridP2, gridS1, gridS2, final_counter2, counter6,
                    counter7, counter8, counter9, counter10);
        if (final_counter2 == 17)
        {
            cout << "Player 2 successfully sunk all the battleships of player 1\n";
            cout << "Player 2 Won the Game\n";
            return 0;
        }
        else
        {
            cout << "Player 1 Turn\n";
            printContinue();
            clearScreen();
        }
    }
    while (final_counter1 != 17 || final_counter2 != 17);
    return 0;
}

void printContinue()
{
    cout << endl << "Press Enter to Continue" << endl;
    cin.get();
    return;
}

void clearScreen()
{
    #ifdef WINDOWS
        system("cls");
    #else
        system("clear");
    #endif
}

void printTypeError()
{
    cout << "Invalid input. Try again..." << endl;
    return;
}
void printSizes(int s)
{
    if (s == 1)
    {
        cout << " (Size 2)" << endl;
    }
    else if (s == 2 || s == 3)
    {
        cout << " (Size 3)" << endl;
    }
    else if (s == 4)
    {
        cout << " (Size 4)" << endl;
    }
    else if (s == 5)
    {
        cout << " (Size 5)" << endl;
    }
    return;
}
void printGrid(char arr[][10])
{
    cout << "    ";
    for (int k = 0; k < 10; k++)
    {
        cout << k << " ";
    }
    cout << "\n    _ _ _ _ _ _ _ _ _ _" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << "  |";
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
void printPlacement(int r, int c)
{
    cout << "One end of your ship will be placed on the coordinates: (" << r << ", " << c << ")";
    cout << "\nChoose which direction the rest of your ship will be placed from here" << endl;
    cout << "\"L\" or \"Left\" to place it to the left from this cell" << endl;
    cout << "\"R\" or \"Right\" to place it to the right from this cell" << endl;
    cout << "\"U\" or \"Up\" to place it above this cell" << endl;
    cout << "\"D\" or \"Down\" to place it below this cell" << endl;
    return;
}
void placeShips(char gridS[][10])
{
    int ship, row, col;
    int sizes[5] = {2, 3, 3, 4, 5};
    string drctn;

    printGrid(gridS);
    for (ship = 1; ship <= 5; ship++)
    {
        if (ship > 1)
        {
            printGrid(gridS);
        }
        printContinue();
        cout << "\nYou are now placing Ship " << ship;
        printSizes(ship);
        bool correct = false;
        do
        {
            do
            {
                cout<<"\nInput Co-ordinates of one end of your boat" << endl;
                do
                {
                    cout<<"Input Row Number: ";
                    cin >> row;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        printTypeError();
                        continue;
                    }
                    else if (row < 0 || row > 9)
                    {
                        cout << "Wrong Row number, please Input row again: ";
                    }
                    else
                    {
                        correct = true;
                    }
                }
                while (correct == false || row < 0 || row > 9);
                do
                {
                    cout <<"Input Column Number: ";
                    cin >> col;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        printTypeError();
                        continue;
                    }
                    else if (col < 0 || col > 9)
                    {
                        cout << "Wrong Column number, please Input column again: ";
                    }
                }
                while (col < 0 || col > 9);
                if (gridS[row][col] != '0')
                {
                    cout << "There is already a ship on these coordinates. Try again." << endl;
                }
                else
                {
                    correct = true;
                }
            }
            while (correct == false);
            correct = false;
            char choice;
            printPlacement(row, col);
            cin >> drctn;
            bool check = true;
            if (drctn == "L" || drctn == "Left")
            {
                for (int i = col; i >= col - (sizes[ship-1] - 1); i--)
                {
                    if (gridS[row][i] != '0')
                    {
                        check = false;
                        break;
                    }
                }
                if (check == false)
                {
                    cout << "A ship is already present in this range." << endl;
                    cout << "Select different coordinates or direction." << endl;
                    continue;
                }
                if (col - (sizes[ship-1] - 1) < 0)
                {
                    cout << "Not enough space on the left side. Choose different coordinates or direction." << endl;
                }
                else
                {
                    for (int i = col; i >= col - (sizes[ship-1] - 1); i--)
                    {
                        gridS[row][i] = static_cast<char>(ship+48);
                        correct = true;
                    }
                }
            }
            else if (drctn == "R" || drctn == "Right")
            {
                for (int i = col; i <= col + sizes[ship-1] - 1; i++)
                {
                    if (gridS[row][i] != '0')
                    {
                        check = false;
                        break;
                    }
                }
                if (check == false)
                {
                    cout << "A ship is already present in this range." << endl;
                    cout << "Select different coordinates or direction." << endl;
                    continue;
                }
                if (col + sizes[ship-1] - 1 > 9)
                {
                    cout << "Not enough space on the right side. Choose different coordinates or direction." << endl;
                }
                else
                {
                    for (int i = col; i <= col + sizes[ship-1] - 1; i++)
                    {
                        gridS[row][i] = static_cast<char>(ship+48);
                        correct = true;
                    }
                }
            }
            else if (drctn == "U" || drctn == "Up")
            {
                for (int i = row; i >= row - (sizes[ship-1] - 1); i--)
                {
                    if (gridS[i][col] != '0')
                    {
                        check = false;
                        break;
                    }
                }
                if (check == false)
                {
                    cout << "A ship is already present in this range." << endl;
                    cout << "Select different coordinates or direction." << endl;
                    continue;
                }
                if (row - (sizes[ship-1] - 1) < 0)
                {
                    cout << "Not enough space above. Choose different coordinates or direction." << endl;
                }
                else
                {
                    for (int i = row; i >= row - (sizes[ship-1] - 1); i--)
                    {
                        gridS[i][col] = static_cast<char>(ship+48);
                        correct = true;
                    }
                }
            }
            else if (drctn == "D" || drctn == "Down")
            {
                for (int i = row; i <= row + sizes[ship-1] - 1; i++)
                {
                    if (gridS[i][col] != '0')
                    {
                        check = false;
                        break;
                    }
                }
                if (check == false)
                {
                    cout << "A ship is already present in this range." << endl;
                    cout << "Select different coordinates or direction." << endl;
                    continue;
                }
                if (row + sizes[ship-1] - 1 > 9)
                {
                    cout << "Not enough space below. Choose different coordinates or direction." << endl;
                }
                else
                {
                    for (int i = row; i <= row + sizes[ship-1] - 1; i++)
                    {
                        gridS[i][col] = static_cast<char>(ship+48);
                        correct = true;
                    }
                }
            }
            else
            {
                cout << "Invalid direction. Choose different coordinates or direction." << endl;
            }
        }
        while (correct == false);

        printGrid(gridS);
        printContinue();
        clearScreen();
    }
}
void playerTurn(char gridP[][10], char gridS[][10], char gridSS[][10], int &finalcounter,
                 int &counter1, int &counter2, int &counter3, int &counter4, int &counter5)
{
    int row, col;
    char z;
    bool flag, flag_row, flag_col;
    do
    {
        flag = false;
        printGrid(gridSS);
        cout << endl;
        printGrid(gridP);
        cout << "Input Co-ordinates of your boat \n";
        cout << "Input Row Number: ";
        do
        {
            flag_row = false;
            cin >> row;
            if (row < 0 || row > 9)
            {
                cout << "Wrong Row number, please Input row again: ";
                flag_row = true;
            }
            if (cin.fail())
            {
                flag_row = true;
                cout << "Wrong Row number, please Input row again: ";
                cin.clear();
                cin.ignore();
            }
        }
        while (flag_row == true);

        cout << "Input Column Number: ";
        do
        {
            flag_col = false;
            cin >> col;
            if (col < 0 || col > 9)
            {
                cout << "Wrong Column number, please Input column again: ";
                flag_col = true;
            }
            if (cin.fail())
            {
                flag_col = true;
                cout << "Wrong Column number, please Input column again: ";
                cin.clear();
                cin.ignore();
            }
        }
        while (flag_col == true);
        clearScreen();
        if (gridP[row][col] == 'S' || gridP[row][col] == 'H' || gridP[row][col] == 'X')
        {
            cout << "Box already bombed, Choose another Co-ordinate now as we will ask you again!\n";
            flag = true;
            printContinue();
            clearScreen();
        }
    }
    while (flag==true);

    if (gridS[row][col]=='1' || gridS[row][col]=='2' || gridS[row][col]=='3' || gridS[row][col]=='4' || gridS[row][col]=='5')
    {
        gridP[row][col] = 'H';
        switch (gridS[row][col])
        {
            case '1':
                ++counter1;
                break;
            case '2':
                ++counter2;
                break;
            case '3':
                ++counter3;
                break;
            case '4':
                ++counter4;
                break;
            case '5':
                ++counter5;
                break;
        }
        ++finalcounter;
    }
    else
    {
        gridP[row][col] = 'X';
    }

    if (counter1 == 2)
    {
        counter1 = 0;
        z = '1';
        sinkShip(gridP, gridS, z);
    }
    if (counter2 == 3)
    {
        counter2 = 0;
        z = '2';
        sinkShip(gridP, gridS, z);
    }
    if (counter3 == 3)
    {
        counter3 = 0;
        z = '3';
        sinkShip(gridP, gridS, z);
    }
    if (counter4 == 4)
    {
        counter4 = 0;
        z = '4';
        sinkShip(gridP, gridS, z);
    }
    if (counter5 == 5)
    {
        counter5 = 0;
        z = '5';
        sinkShip(gridP, gridS, z);
    }
    printGrid(gridSS);
    cout << endl;
    printGrid(gridP);

    switch (gridP[row][col])
    {
        case 'X':
            cout << "Ship Missed!\n";
            break;
        case 'S':
            cout << "Ship Sunk!\n";
            break;
        case 'H':
            cout << "Ship Hit!\n";
            break;
    }
}
void sinkShip(char gridP[][10], char gridS[][10], char z)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (gridS[i][j] == z)
            {
                gridP[i][j] = 'S';
            }
        }
    }
}