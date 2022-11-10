
// Chapter 7, Programming Challenge 18: Tic-Tac-Toe Game
#include <iostream>
using namespace std;

// Constants for the rows and columns
const int ROWS = 3;
const int COLS = 3;

// Function prototypes
void display(char [] [COLS]);
void turns(char [] [COLS], char);
bool outcome(char [][COLS]);
bool onlyWayToWin(char [] [COLS], char);
bool possibilities(char [] [COLS], char);
void displayWin(char [] [COLS]);





int main()
{
	// Array for the game position.
	char gameBoard[ROWS][COLS] = { '*', '*', '*',
								   '*', '*', '*',
								   '*', '*', '*' };
//  YOUR CODE HERE
   
	// Display the position one last time.
	do
	{
		display(gameBoard);

		turns(gameBoard, 'X');

		display(gameBoard);

		turns(gameBoard, 'O');
			

	} while (!outcome(gameBoard));
	
   
	// Display the winner.
	display(gameBoard);

	displayWin(gameBoard);

	return 0;
}

void display(char position[] [COLS])
{

   // Display the rows.
   for (int row = 0; row < ROWS; row++)
   {
      // Row label.
       
      // Row contents.
      for (int col = 0; col < COLS; col++)
      {
         cout << position [row][col] << " ";
      }
      cout << endl;
   }
}




void turns(char position[] [COLS], char player)
{
bool available = false;

int row;
int col;

cout <<"It is player " << player << "'s turn \n";
cout <<"Enter a number for both row and column\n";
cout <<"Only enter numbers 1,2, and 3\n\n";

while (!available)
{

	cout << "Row: "; cin >> row;

while (row <1 || row >ROWS)
{
	cout << "Row not available, stay within range\n";
	cout << "Row: "; cin >> row;

}

cout << "Column: "; cin >> col;

while(col <1 || col > COLS)
{
	cout << "Column not available, stay within range\n";
	cout << "Column: "; cin >> col;
}

if(position[row - 1][col - 1] == '*')
	available = true;
else
{
	cout << "Location is taken, choose another";
}

}
position[row - 1][col - 1] = player;
}

bool outcome(char position[] [COLS])
{
	if(onlyWayToWin(position, 'X') || onlyWayToWin(position, 'O'))
	return true;

	else if (possibilities(position, 'X') || onlyWayToWin(position, 'O'))
	return false;

	else
	return true;
}

bool onlyWayToWin(char position[] [COLS], char player)
{

   if (position[0][0] == player && position[0][1] == player &&
       position[0][2] == player)
      return true;
 

   if (position[1][0] == player && position[1][1] == player && 
       position[1][2] == player)
      return true;
 

   if (position[2][0] == player && position[2][1] == player && 
       position[2][2] == player)
      return true;
       

   if (position[0][0] == player && position[1][0] == player && 
       position[2][0] == player)
      return true;
    

   if (position[0][1] == player && position[1][1] == player && 
       position[2][1] == player)
      return true;
 

   if (position[0][2] == player && position[1][2] == player && 
       position[2][2] == player)
      return true;
 

   if (position[0][0] == player && position[1][1] == player && 
       position[2][2] == player)
      return true;
    else
   return false;
}

bool possibilities(char position[][COLS], char player)
{

   if ((position[0][0] == player || position[0][0] == '*') && 
       (position[0][1] == player || position[0][1] == '*') &&
       (position[0][2] == player || position[0][2] == '*'))
      return true;
 

   if ((position[1][0] == player || position[1][0] == '*') && 
       (position[1][1] == player || position[1][1] == '*') &&
       (position[1][2] == player || position[1][2] == '*'))
      return true;
 

   if ((position[2][0] == player || position[2][0] == '*') && 
       (position[2][1] == player || position[2][1] == '*') &&
       (position[2][2] == player || position[2][2] == '*'))
      return true;
 

   if ((position[0][0] == player || position[0][0] == '*') && 
       (position[1][0] == player || position[1][0] == '*') &&
       (position[2][0] == player || position[2][0] == '*'))
      return true;
 

   if ((position[0][1] == player || position[0][1] == '*') && 
       (position[1][1] == player || position[1][1] == '*') &&
       (position[2][1] == player || position[2][1] == '*'))
      return true;
 

   if ((position[0][2] == player || position[0][2] == '*') && 
       (position[1][2] == player || position[1][2] == '*') &&
       (position[2][2] == player || position[2][2] == '*'))
      return true;
 

   if ((position[0][0] == player || position[0][0] == '*') && 
       (position[1][1] == player || position[1][1] == '*') &&
       (position[2][2] == player || position[2][2] == '*'))
      return true;
 
    else
   return false;
}

void displayWin(char position[][COLS])
{
	if(onlyWayToWin(position, 'X'))
	cout << "Player 1 wins!\n";
	
	else if (onlyWayToWin(position, 'O'))
	cout <<"Player 2 wins!\n";
	
	else
	cout <<"it is a tie!\n";
}

