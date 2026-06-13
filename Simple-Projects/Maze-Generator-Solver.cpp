#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 10;
const int COLS = 20;

char maze[ROWS][COLS];

int playerX = 1;
int playerY = 1;

int endX = ROWS - 2;
int endY = COLS - 2;

void generateMaze()
{
    srand(time(0));

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(i == 0 || i == ROWS - 1 ||
               j == 0 || j == COLS - 1)
                maze[i][j] = '#';
            else
            {
                if(rand() % 100 < 25)
                    maze[i][j] = '#';
                else
                    maze[i][j] = ' ';
            }
        }
    }

    maze[playerX][playerY] = 'S';
    maze[endX][endY] = 'E';
}

void displayMaze()
{
    system("cls"); // Windows

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(i == playerX && j == playerY)
                cout << 'P';
            else
                cout << maze[i][j];
        }
        cout << endl;
    }
}

int main()
{
    generateMaze();

    char move;

    while(true)
    {
        displayMaze();

        if(playerX == endX && playerY == endY)
        {
            cout << "\nCongratulations! You escaped the maze!\n";
            break;
        }

        cout << "\nMove (W/A/S/D): ";
        cin >> move;

        int newX = playerX;
        int newY = playerY;

        switch(toupper(move))
        {
            case 'W':
                newX--;
                break;

            case 'S':
                newX++;
                break;

            case 'A':
                newY--;
                break;

            case 'D':
                newY++;
                break;
        }

        if(maze[newX][newY] != '#')
        {
            playerX = newX;
            playerY = newY;
        }
    }

    return 0;
}
