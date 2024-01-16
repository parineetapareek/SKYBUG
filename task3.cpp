#include <iostream>
using namespace std;
#define max 3

void print(char arr[max][max])
{
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

bool win(char arr[max][max], char XO)
{
    for (int i = 0; i < max; i++)
    {
        if (arr[i][0] == XO && arr[i][1] ==  XO && arr[i][2] == XO)
            return true;
    }

    for (int i = 0; i < max; i++)
    {
        if (arr[0][i] == XO && arr[1][i] == XO && arr[2][i] == XO)
            return true;
    }

    if (arr[0][0] == XO && arr[1][1] == XO && arr[2][2] == XO)
        return true;

    if (arr[0][2] == XO && arr[1][1] == XO && arr[2][0] == XO)
        return true;

    return false;
}

bool isDraw(char arr[max][max])
{
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (arr[i][j] == '-')
                return false;
        }
    }
    return true;
}

int main()
{
    cout<<"Welcome to Tic-Tac-Toe Game"<<endl<<endl;

    char grid[max][max] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    print(grid);
    cout<<endl;

    int row, column;
    char player = 'X';

    do
    {
        cout << "Player " << player << " enter your move-->" << endl;
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> column;

        if (grid[row][column] == '-')
        {
            grid[row][column] = player;
            print(grid);
        }

        else
        {
            cout << "Invalid move!!" << endl;
        }

        cout << endl;

        if (win(grid, player))
        {
            cout << "Player " << player << " won the game!!!" << endl;
            break;
        }

        if (isDraw(grid))
        {
            cout << "Game is Draw!!" << endl;
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    } while (true);

    return 0;
}