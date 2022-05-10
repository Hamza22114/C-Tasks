#include <iostream>
#include <cstdlib> // system call

using namespace std;

// constant globals
const char EMPTY = '-';
const char RED = 'R';
const char BLACK = 'B';

// non-constant globals
int rows = 7;
int columns = 6;

// function prototypes
/*
Dynamically allocates the board (rows, columns) and fills it with empty pieces.
*/
char** createBoard();
// Overload for if other than default 7 x 6.
char** createBoard(int rows, int columns);

/*
Deletes the rows and columns of the board.
*/
void deleteBoard(char** board);

/*
Prints the board to the screen.
The top of the board is the 0th row.
The bottom of the board is the row-1th row.
The left-most column is 0.
The right-most column is columns-1.
Put | between the columns.
See the example output in Moodle.
*/
void printTheBoard(char** board);

/*
Returns true if the column is in the valid range (0 to columns-1)
*/
bool validColumn(int column);

/*
Returns true if the column in the given board is full (no empty spots).
*/
bool isColumnFull(char** board, int column);

/*
"Drops" a piece into the board at the given column.
The piece should "fall" to the bottom-most empty row.
Note: the top row of the board has an index of 0 and the bottom row has an index of rows - 1.
*/
void playPiece(char** board, int column, char piece);

/*
Takes in a player piece (black or red) and returns the opposite.
*/
char switchPlayer(char piece);



int main() {
	char **board = NULL;
	char ans;
	
	// Your Code Goes Here
	cout << "Enter Y/y to Change board size:";
	ans = cin.get();
	if((ans == 'Y') || (ans == 'y'))
	{
		// Get rows and columns
		cout << "Enter rows ... ";
		cin >> rows;
		cout << "Enter columns ...";
		cin >> columns;
		// Creates a different-sized board.
		board = createBoard(rows, columns); 
	}
	else
	// Creates a default-sized board.
		board = createBoard(); 
	cin.ignore(); // Eat up return from ans.	
	
	// Now that the board is created and 
	// initialized, then access row/column with the syntax: board[row][column].

	// Here I'm just avoiding system(pause), my Linux does not have one.
	// Also, should be careful if Cygwin or MingW situations on top of 
	// Windows but I skipped that since I did this on Linux.
	#if defined(_WIN64)
	/* Windows (64-bit) */
	system("pause");
	#elif defined(_WIN32)
	/* Windows (32-bit) */
	system("pause");
	#else
	// Linux (or Windows)
	std::cout << "Pause - Press return to end." << std::endl;
	cin.clear();
	std::cin.get();
	#endif
	
	// delete the board
	if(board)
	{
		deleteBoard(board);
		board = NULL;
	}
	
	return 0;
}

// Your Function Definitions Go Here
char** createBoard()
{
	char **board = NULL;
	
	board = new char*[rows];
	if(board)
	{
		for(int i = 0; i < rows; i++)
		{
			board[i] = new char[columns];
		}
		// Initialize the board with '-'
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				board[i][j] = '-';
	}
	else
	{
		// Error ...
	}
	
	return board;
}

char** createBoard(int rows, int columns)
{
	char **board = NULL;
	
	board = new char*[rows];
	if(board)
	{
		for(int i = 0; i < rows; i++)
		{
			board[i] = new char[columns];
		}
		// Initialize the board with '-'
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				board[i][j] = '-';
	}
	else
	{
		// Error ...
	}
	
	return board;	
}

void deleteBoard(char **board)
{
	for(int i = 0; i < rows; i++)
		delete[] board[i];
	delete[] board;
}