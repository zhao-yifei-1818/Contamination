#include <iostream>
/**
 * @brief Assignment 8 Contamination
 * @name Yifei Zhao
 */
using namespace std;

const int MAZE_SIZE = 10;
const char EMPTY = '*';
const char WALL = '#';
const char CONTAMINATED = 'C';

bool isSafe = true;       // track situation is safe
int contaminatedArea = 0; // track contaminated area

void contaminate(char Location[MAZE_SIZE][MAZE_SIZE], int startrow,
                 int startcol)
{
  if (startrow < 0 || startcol < 0 || startrow >= MAZE_SIZE
      || startcol >= MAZE_SIZE) { // if out of range base case
    isSafe = false;
    return;
  }

  if (Location[startrow][startcol] == WALL
      || Location[startrow][startcol]
             == CONTAMINATED) { // wall or contaminated base case

    return;
  }

  Location[startrow][startcol] = CONTAMINATED; // Contaminate the current cell
  contaminatedArea++;                          // Increase the counter

  contaminate(Location, startrow - 1, startcol); // Spread up
  contaminate(Location, startrow, startcol + 1); // right
  contaminate(Location, startrow + 1, startcol); // down
  contaminate(Location, startrow, startcol - 1); // left
}

int main()
{
  char Location[MAZE_SIZE][MAZE_SIZE];
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      Location[i][j] = EMPTY; // Set the cell as empty
    }
  }
  int startrow;
  int startcol;

  cout << "Enter contaminated location (row col): ";
  cin >> startrow >> startcol;

  cout << "Enter wall locations (row col), followed by 0 0 to indicate end of "
          "input:\n"; // Ask the user for the wall locations
  while (cin >> startrow >> startcol, startrow || startcol) {
    Location[startrow][startcol] = WALL;
  }

  contaminate(Location, startrow,
              startcol); // Start the contamination from the initial location

  for (int i = 0; i < MAZE_SIZE; i++) {   // For each row
    for (int j = 0; j < MAZE_SIZE; j++) { // For each column
      cout << Location[i][j] << ' ';      // Print the cell
    }
    cout << endl;
    ; // Print a newline
  }

  if (isSafe) { // If the situation is safe
    cout << "Safe!\n"
         << "Contaminated area: " << contaminatedArea << endl; // Print
  } else { // If the situation is not safe
    cout << "Not Safe";
    cout << endl;
  }

  return 0;
}