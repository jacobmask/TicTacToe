#include <iostream>
#include <string>
using namespace std;

// array for game 
char square[3][3] = {
	{'\xF0','\xF0','\xF0'},
	{'\xF0','\xF0','\xF0'},
	{'\xF0','\xF0','\xF0'} };

/* Checks completion of one line*/
#define check_line(n1, n2, n3)	(get_cell(n1) == get_cell(n2) && get_cell(n1) == get_cell(n3) && get_cell(n3) != '\xF0')

/* the function that can get one cell's value */
char get_cell(int n);

/* the function that can set one cell's value */
void set_cell(int n, char value);

/* the function that can display the current matrix values */
void display();

/* the function that can set X or O value on the player's matrix */
void mark(int player, int box);

/* the function that can check the winner between player1 and player2 */
int check_winner();

int main()
{
	int player1 = 1, player2 = 2;
	string player1name, player2name;
	int r, c, result = 0, flag = 0;

	/* print description of this game */
	cout << "Welcome to Tic-Tac-Toe Game" << endl;

	/* input the two players name */
	cout << "Please enter player 1's name: " << endl;
	cin >> player1name;
	cout << "Please enter player 2's name: " << endl;
	cin >> player2name;

	/* displaying of the initial game table */
	display();

	for (int i = 1; i < 5; i++)
	{
		cout << endl << player1name << "(X)'s turn" << endl;
		cout << "Enter a row and column to place an X. Enter -1 to quit the game" << endl;

		do {
			cout << "Row: ";
			cin >> r;
			if (r == -1) {
				flag = -1;
				break;
			}
			cout << "Column: ";
			cin >> c;
			if (c == -1) {
				flag = -1;
				break;
			}
			
			if (r > 3 || c > 3) {
				cout << "Enter a row and column between 1 ~ 3" << endl;
				continue;
			}

			r--;
			c--;
			if (get_cell(r * 3 + c) != '\xF0') {
				cout << "That location is not avaiable, Select another location." << endl;
				continue;
			}
			
			break;
		} while (true);
		if (flag == -1) break;
		
		mark(player1, r * 3 + c);
		display();

		result = check_winner();
		if (result == 1)
		{
			cout << player1name << " (X) WINS !!!" << endl;
			flag = 1;
			break;
		}
		else
			if (result == 2)
			{
				cout << player2name << " (O) WINS !!!" << endl;
				flag = 1;
				break;
			}

		cout << endl << player2name << "(O)'s turn" << endl;
		cout << "Enter a row and column to place an O. Enter -1 to quit the game" << endl;
		do {
			cout << "Row: ";//Get Row
			cin >> r;
			if (r == -1) {
				flag = -1;
				break;
			}
			cout << "Column: ";//Get Column
			cin >> c;
			if (c == -1) {
				flag = -1;
				break;
			}

			if (r > 3 || c > 3) {//Verify valid number
				cout << "Enter a row and column between 1 ~ 3" << endl;
				continue;
			}

			r--;
			c--;
			if (get_cell(r * 3 + c) != '\xF0') {
				cout << "That location is not avaiable, Select another location." << endl;
				continue;
			}

			break;
		} while (true);
		if (flag == -1) break;

		mark(player2, r * 3 + c);
		display();

		result = check_winner();
		if (result == 1)
		{
			cout << player1name << " (X) WINS !!!" << endl;
			flag = 1;
			break;
		}
		else
			if (result == 2)
			{
				cout << player2name << " (O) WINS !!!" << endl;
				flag = 1;
				break;
			}
	}
	if (flag == 0)
		cout << " Sorry, The game is a draw " << endl;
	else if (flag == -1)
		cout << " Game is cancelled by user" << endl;

	return 0;
}

char get_cell(int n) //Gets the box
{
	if (n >= 0 && n < 9) {
		return square[n / 3][n % 3];
	}
	return 0;
}

void set_cell(int n, char value)  //Sets the box
{
	if (n >= 0 && n < 9) {
		square[n / 3][n % 3] = value;
	}
}

int check_winner()//Check if player has won
{
	if (check_line(0, 1, 2))
	{
		if (get_cell(0) == 'X')
			return 1;
		else
			return 2;
	}
	else
		if (check_line(3, 4, 5))
		{
			if (get_cell(3) == 'X')
				return 1;
			else
				return 2;
		}
		else
			if (check_line(6, 7, 8))
			{
				if (get_cell(6) == 'X')
					return 1;
				else
					return 2;
			}
			else
				if (check_line(0, 3, 6))
				{
					if (get_cell(0) == 'X')
						return 1;
					else
						return 2;
				}
				else
					if (check_line(1, 4, 7))
					{
						if (get_cell(1) == 'X')
							return 1;
						else
							return 2;
					}
					else
						if (check_line(2, 5, 8))
						{
							if (get_cell(2) == 'X')
								return 1;
							else
								return 2;
						}
						else
							if (check_line(0, 4, 8))
							{
								if (get_cell(0) == 'X')
									return 1;
								else
									return 2;
							}
							else
								if (check_line(2, 4, 6))
								{
									if (get_cell(2) == 'X')
										return 1;
									else
										return 2;
								}
								else
									if (check_line(0, 3, 6))
									{
										if (get_cell(0) == 'X')
											return 1;
										else
											return 2;
									}
									else
										return 0;
}

void mark(int player, int box)//Marks X/Os
{
	if (player == 1)
	{
		set_cell(box, 'X');
	}
	else
		set_cell(box, 'O');
}

void display()
{
	cout << "\t\tColumns" << endl;
	cout << "\t\t1\t2\t3" << endl;
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
			cout << "Row\t" << (i / 3 + 1) << ":\t";

		cout << get_cell(i) << "\t";
		if (i == 2 || i == 5 || i == 8)
			cout << "\n";
	}
}
