/********************************************************************************
### 10 - In this assignment we want you to create a console X/O Game

- X/O Game is the minimum requirement you can also create Connect 4 game or Tetris Clone or Snake Game
- But the main assignment is X/O Game
- Please follow the following instructions to solve the assignment:
	- Understand the game rules very good
	- Bring a pen and a piece of paper and start to think about how you can divide your program
	- Will the program check something? what about wrong inputs? and like that…
	- Think about the first part then code it and the second part then code it
	- but before all of that, there is a good method, write the final result you want the program to be like it at the end and think about what will happen if there is an error somewhere.
	- and Good Luck ??
***********************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
bool checkWin(char a[3][3]) {
	// Check for horizontal wins
	for (int i = 0; i < 3; ++i) {
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != ' ') {
			return true;
		}
	}

	// Check for vertical wins
	for (int i = 0; i < 3; ++i) {
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != ' ') {
			return true;
		}
	}

	// Check for diagonal wins
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != ' ') {
		return true;
	}
	if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != ' ') {
		return true;
	}

	// No win
	return false;
}

bool isEmpty(char c)
{
	if (c == 'X' || c == 'O')
	{
		cout << "Place is not empty ! " << endl;
		return false;
	}
	return true;

}

bool isCorrectDimention(int d)
{

	if (d == 1 || d == 2 || d == 3)
	{
		return true;
	}
	cout << "Incorrect dimentions !" << endl;
	return false;
}
void changeOpponent(char* o)
{
	if (*o == 'X')
		*o = 'O';
	else
		*o = 'X';

}
void initializeBoard(char board[3][3])
{
	for (int r = 0; r < 3; r++)
	{
		{
			for (int c = 0; c < 3; c++)
				board[r][c] = ' ';
		}
	}
}
void drawBoard(char a[3][3])
{
	int ro = 0;
	for (int r = 0; r < 7; r++)
	{
		if (r % 2 == 0)
		{
			for (int c = 0; c < 12; c++)
			{

				cout << "-";
			}
		}
		else
		{
			for (int c = 0; c < 4; c++)
			{
				if (c == 3)
					cout << "|";
				else
					cout << "| " << a[ro][c] << " ";
			}
			ro++;
		}

		cout << endl;
	}

}


int main()
{

	char opp = 'X';
	int side;
	char board[3][3];
	int row, col;
	initializeBoard(board);
	cout << "                                     Welcome To Tic-Tac-Toe Game :)  " << endl;
	for (int i = 0; i < 9; i++)
	{
		do {
			cout << opp << " Enter row and col : " << endl;
			cin >> row >> col;

		} while (!isCorrectDimention(row) || !isCorrectDimention(col) || !isEmpty(board[row - 1][col - 1]));
		board[row - 1][col - 1] = opp;
		if (checkWin(board))
		{
			drawBoard(board);
			cout << "*** " << opp << " You Win ***" << endl;
			return 0;
		}
		else
		{
			drawBoard(board);
			changeOpponent(&opp);
		}


	}

	cout << "Game Over :(" << endl;

}





