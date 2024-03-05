#include <iostream>
/*
Yifei Zhao

*/
using namespace std;

const int SIZE = 10;
const char EMPTY = '*';
const char WALL = '#';
const char CONTAMINATED = 'C';

bool isSafe = true;       // track situation is safe
int contaminatedArea = 0; // track contaminated area

void contaminate(char Location[SIZE][SIZE], int x, int y)
{
  if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) { // if out of range base case
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
  char Location[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      Location[i][j] = EMPTY; // Set the cell as empty
    }
  }
  int x;
  int y;

  cout << "Enter contaminated location (row col): "; // Ask the user for the
                                                     // contaminated location
  cin >> x >> y; // Read the coordinates from the user

  cout << "Enter wall locations (row col), followed by 0 0 to indicate end of "
          "input:\n";             // Ask the user for the wall locations
  while (cin >> x >> y, x || y) { // While the coordinates are not 0 0
    Location[x][y] = WALL;        // Set the cell as a wall
  }

  contaminate(Location, x,
              y); // Start the contamination from the initial location

  for (int i = 0; i < SIZE; i++) {   // For each row
    for (int j = 0; j < SIZE; j++) { // For each column
      cout << Location[i][j] << ' '; // Print the cell
    }
    cout << '\n'; // Print a newline
  }

  if (isSafe) { // If the situation is safe
    cout << "Safe!\nContaminated area: " << contaminatedArea
         << '\n'; // Print that the situation is safe and the contaminated area
  } else {        // If the situation is not safe
    cout << "Not Safe\n"; // Print that the situation is not safe
  }

  return 0; // End the program
}