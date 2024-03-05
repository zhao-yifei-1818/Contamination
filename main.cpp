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

void contaminate(char Location[MAZE_SIZE][MAZE_SIZE], int x, int y)
{
  if (x < 0 || y < 0 || x >= MAZE_SIZE
      || y >= MAZE_SIZE) { // if out of range base case
    isSafe = false;
    return;
  }

  if (Location[x][y] == WALL
      || Location[x][y] == CONTAMINATED) { // wall or contaminated base case

    return;
  }

  Location[x][y] = CONTAMINATED; // Contaminate the current cell
  contaminatedArea++;            // Increase the counter

  contaminate(Location, x - 1, y); // Spread up
  contaminate(Location, x, y + 1); // right
  contaminate(Location, x + 1, y); // down
  contaminate(Location, x, y - 1); // left
}

int main()
{
  char Location[MAZE_SIZE][MAZE_SIZE];
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      Location[i][j] = EMPTY; // Set the cell as empty
    }
  }
  int x;
  int y;

  cout << "Enter contaminated location (row col): ";
  cin >> x >> y;
  int startx;
  int starty;

  cout << "Enter wall locations (row col), followed by 0 0 to indicate end of "
          "input:\n"; // Ask the user for the wall locations
  while (cin >> startx >> starty, startx || starty) {
    Location[startx][starty] = WALL;
  }

  contaminate(Location, x,
              y); // Start the contamination from the initial location

  for (int i = 0; i < MAZE_SIZE; i++) {   // For each row
    for (int j = 0; j < MAZE_SIZE; j++) { // For each column
      cout << Location[i][j] << ' ';      // Print the cell
    }
    cout << '\n'; // Print a newline
  }

  if (isSafe) { // If the situation is safe
    cout << "Safe!\n"
         << "Contaminated area: " << contaminatedArea << '\n'; // Print
  } else { // If the situation is not safe
    cout << "Not Safe\n";
  }

  return 0;
}