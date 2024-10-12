//Declaration
#include "snakeladder.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Function for when the players choose to leave the game
bool snakesAndladders::leavingGame()
{
	char choice;

	// Prompting the player for confirmation of leaving the game
	cout << "Are you sure you would like to leave the game? " << endl;
	cout << "Choose (Y/N) to confirm " << endl;
	cin >> choice;

	// If else statement to decide an appropriate response for the player's choice
	if (choice == 'Y' || choice == 'y')
	{
		cout << "\nUnderstood.\n";
		return true;
	}
	else if (choice == 'N' || choice == 'n')
	{
		cout << "\nUnderstood.\n";
		cout << "Press Enter to Roll the Dice";
		cin.ignore(); // Clear the input buffer
		cin.get(); // Wait for user input to continue
		return false;
	}
	else
	{
		cout << "Invalid choice. Please choose with 'Y' or 'N'." << endl;
		return false;
	}
}

// Function to display the correct amount of lines easily 
void snakesAndladders::draw_line(int n, char ch)
{
	for (int i = 0; i < n; i++)
		cout << ch;
}

// Function to display the board and location for the snakes and ladders
void snakesAndladders::board()
{
	system("cls"); // Clear the screen if necessary
	draw_line(52, '-'); // Calling the draw_line function
	cout << "\n| Snake at Position \t|\t" << "Ladder at Position |\n";
	draw_line(52, '-'); // Calling the draw_line function
	cout << endl;
	cout << "| From 98 to 28 \t|\t" << "From 8 to 26       |\n";
	cout << "| From 92 to 51 \t|\t" << "From 21 to 82      |\n";
	cout << "| From 83 to 19 \t|\t" << "From 43 to 77      |\n";
	cout << "| From 69 to 33 \t|\t" << "From 50 to 91      |\n";
	cout << "| From 59 to 17 \t|\t" << "From 62 to 96      |\n";
	cout << "| From 48 to 9  \t|\t" << "From 66 to 87      |\n";
	cout << "| From 46 to 5  \t|\t" << "From 80 to 100     |\n";
	draw_line(52, '-'); // Calling the draw_line function
	cout << endl;
}

// Function to display current status of the game when playing
void snakesAndladders::gamescore(const std::string* playerNames, const int* playerPositions, int playerCount, int rounds)
{
	cout << "\n";
	draw_line(52, '-'); // Calling the draw_line function
	cout << "\n\t\tGAME STATUS: ROUND " << rounds << "\n";
	draw_line(52, '-'); // Calling the draw_line function
	for (int i = 0; i < playerCount; ++i) // Loop to update each player's position as the game goes on
	{
		cout << "\n > " << playerNames[i] << " is at position " << playerPositions[i] << endl;
	}
	draw_line(52, '_'); // Calling the draw_line function
	cout << endl;
}

//Dice for players to roll
void snakesAndladders::play_dice(int& score)
{
	int dice;
	dice = 1 + rand() % 6; // To emulate a 6 sided dice throw
	cout << "\nYou got " << dice << " Point !! ";
	score = score + dice;
	cout << "Now you are at position " << score;

	//When the players rolls onto a snake or ladder slot
	switch (score)
	{
		//If player landed on Snakes
	case 98:
		score = 28;
		break;

	case 92:
		score = 51;
		break;

	case 83:
		score = 19;
		break;

	case 69:
		score = 33;
		break;

	case 59:
		score = 17;
		break;

	case 48:
		score = 9;
		break;

	case 46:
		score = 5;
		break;

		//If player landed on Ladders
	case 8:
		score = 26;
		break;

	case 21:
		score = 82;
		break;

	case 43:
		score = 77;
		break;

	case 50:
		score = 91;
		break;

	case 54:
		score = 93;
		break;

	case 62:
		score = 96;
		break;

	case 66:
		score = 87;
		break;

	case 80:
		score = 100;
		break;
	}
}

// Function for searching
int snakesAndladders::findPlayerPosition(const std::string& playerName, const std::string* pNames, const int* pPositions, int playerCount)
{
	for (int i = 0; i < playerCount; ++i) // Loop to search through the dynamic arrays to display a player's name and position
	{
		if (playerName == pNames[i])
		{
			return pPositions[i];
		}
	}
	return -1; // Player not found
}
