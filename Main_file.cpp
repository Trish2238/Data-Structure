//Main Function
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "snakeladder.h" //Header file
using namespace std;

int main()
{
    snakesAndladders sNl; // Creating an object for the snakesAndladders class

    srand((unsigned)time(NULL)); // Random number generator for the 6 sided dice
    int maxPlayers = 4;
    int choice;

    // Beginning of the game
    while (true)
    {
        // Calling the draw_line function
        sNl.draw_line(50, '='); cout << "\n";
        sNl.draw_line(50, '='); cout << "\n";
        sNl.draw_line(50, '=');
        cout << "\n\t\tSNAKE LADDER GAME\n";
        sNl.draw_line(50, '='); cout << "\n";
        sNl.draw_line(50, '='); cout << "\n";
        sNl.draw_line(50, '=');

        cout << "\n\nEnter '1' to start the game or '0' to leave: ";
        cin >> choice;

        // Checks for any invalid input
        if (cin.fail() || (choice != 0 && choice != 1))
        {
            cin.clear(); // Clear error flag
            cin.ignore(); // Clear the input buffer

            cout << "\nInvalid input! Please enter '0' or '1'.\n";
            cout << "Please wait a moment";
            Sleep(750); // Buffers the previous line of code for ease of readability
            system("cls"); // Clear the screen if necessary
        }
        // If the player chooses to exit the game
        else if (choice == 0)
        {
            cout << "\nThank you for playing!\n";
            break;
        }
        // If the player chooses to start the game
        else if (choice == 1)
        {
            vector<string> playerNames; // Dynamic array to store player names
            vector<int> playerPositions; // Dynamic array to store player positions
            vector<bool> playerActive; // Dynamic array to keep track of active players
            int playerCount = 0;

            system("cls"); // Clear the screen if necessary

            do
            {
                // Entering how many players will be joining the game
                cout << "Enter the number of players (1-" << maxPlayers << "): ";
                if (!(cin >> playerCount))
                {
                    // If not an integer input
                    cout << "\nInvalid input! Please enter a number.\n";
                    cin.clear(); // Clear the error flag
                    cin.ignore(); // Clear the input buffer
                    Sleep(750); // Buffers the previous line of code for ease of readability
                    system("cls"); // Clear the screen if necessary
                }
                else if (playerCount < 1 || playerCount > maxPlayers)
                {
                    // If it is integer input but out of range
                    cout << "\nInvalid number of players!\n";
                    cout << "Please enter a valid number from 1 to 4.";
                    Sleep(1000); // Buffers the previous line of code for ease of readability
                    system("cls"); // Clear the screen if necessary
                }
    } while (playerCount < 1 || playerCount > maxPlayers); // Do while loop to ensure no error

            // Entering the names of the players
            cout << "\nEnter the names of the players:\n";
            for (int i = 0; i < playerCount; ++i)
            {
                string playerName;
                cout << "Player " << i + 1 << ": ";
                cin >> playerName;

                // To prevent 2 more players of sharing the same name
  if (find(playerNames.begin(), playerNames.end(), playerName) != playerNames.end())
                {
                    cout << "Can't have the same name as " << playerName << "!\n";
                    --i;
                }
                else
                {
                    playerNames.push_back(playerName);
                    playerPositions.push_back(0); // Initialize positions to 0
                    playerActive.push_back(true); // Initialize all players as active
                }
            }

            // Adding the players into the game
            cout << "\nPlayers added:\n";
            for (const string& name : playerNames)
            {
                cout << name << endl;
            }

            cout << "\n";
            sNl.draw_line(42, '='); cout << "\n";
            cout << "The game will be starting shortly... GLHF\n";
            sNl.draw_line(42, '='); cout << "\n";
  Sleep(4000); // Buffers the previous line of code to emulate the process of the preparation of a game

            bool gameWon = false;
            int rounds = 1;

            while (!gameWon)
            {
                Sleep(500); // Buffers the next line of code for ease of readability
                system("cls"); // Clear screen
                sNl.board(); // Calling the board function
sNl.gamescore(playerNames.data(), playerPositions.data(), playerCount, rounds); // Calling the gamescore function

                for (int i = 0; i < playerCount; ++i)
                {
                    if (!playerActive[i])
                    {
                        continue; // Skip inactive players
                    }

                    int playerOption;
                    // To display the options for the players
                    cout << "\n\nOptions for " << playerNames[i] << ":\n";
                    cout << "1. Roll the dice\n";
                    cout << "2. Find other players' positions\n";
                    cout << "3. Leave Game\n";
                    cout << "Enter your choice (1-3): ";

                    while (!(cin >> playerOption) || playerOption < 1 || playerOption > 3)
                    {
                        //If not an integer input
                        if (cin.fail())
                        {
                            cout << "Invalid input! Please enter a number between 1 and 3.\n";
                            cin.clear(); // Clear error flags
                            cin.ignore(); // Clear input buffer
                        }
                        //If it is integer input but out of range
                        else
                        {
                            cout << "Invalid choice! Please enter a number between 1 and 3.\n";
                            cin.clear(); // Clear error flags
                            cin.ignore(); // Clear input buffer
                        }
                        Sleep(500); //Buffers the previous line of code for readability
                    }

                    // Switch statement to decide an appropriate response for the player's choice
                    switch (playerOption)
                    {
                    case 1: // Roll dice option
                    {
                        int lastpos = playerPositions[i];
                        sNl.play_dice(playerPositions[i]); // Calling the play_dice function

                        if (playerPositions[i] < lastpos)
 cout << "\n\aOops!! Snake found !! You are at position " << playerPositions[i] << "\n";
                        else if (playerPositions[i] > lastpos + 6)
 cout << "\nGreat!! You got a ladder!! You are at position " << playerPositions[i] << "\n";

                        cin.ignore(); // Wait for user to press Enter

                        // Check win condition
                        if (playerPositions[i] >= 100)
                        {
                            cout << "\n\n\n";
                            sNl.draw_line(52, '#');
                            cout << "\n\t\tRESULT\n\n";
                            sNl.draw_line(52, '#');
cout << "\n\n\nCongratulations !!! " << playerNames[i] << ", You won the game\n\n";
                            sNl.draw_line(52, '#');
                            gameWon = true; // Set the flag to true to break out of the main loop
                            playerActive[i] = false; // Mark the player as inactive

                            // Delay before clearing the screen
                            Sleep(10000); // Wait for 10 seconds

                            cout << "\nScore screen will be cleared soon...";
                            Sleep(3000); // Wait for 3 seconds
                            system("cls"); //Clear the screen if necessary
                            break; // Exit the player loop
                        }
                        break;
                    }

                    case 2: // Checking another player's position option
                    {
                        string playerNameToFind;
                        cout << "Enter player name to find their position: ";
                        cin >> playerNameToFind;
int playerPosition = sNl.findPlayerPosition(playerNameToFind, playerNames.data(), playerPositions.data(), playerCount); // Calling the search function
if (playerPosition != -1) // To confirm whether a player is on the board and deciding an appropriate response
                        {
                            cout << playerNameToFind << " is at position " << playerPosition << endl;
                        }
                        else
                        {
                            cout << playerNameToFind << " not found on the board." << endl;
                        }
                        cin.ignore(); // Consume newline from previous input
                        cout << "Press Enter to continue...";
                        cin.get(); // Wait for user input to continue
                        sNl.play_dice(playerPositions[i]);
                        break; // To return to the options menu
                    }

                    case 3: // Leave game option
                    {
                        if (sNl.leavingGame()) // Calling the leave game function
                        {
                            cout << "Player " << playerNames[i] << " has left the game.\n";
                            playerActive[i] = false; // Mark the player as inactive

// Clear the player position on the board by setting it to a special value, such as -1
playerPositions[i] = -1; // Assuming -1 represents an empty position on the board
                        }
                        break;
                    }

                    default: // If a player inputs an invalid option
                        cout << "Invalid choice!\n";
                        break;
                    }

                    // To detect whether all players are active or inactive
                    bool allPlayersLeft = true;
                    for (bool active : playerActive)
                    {
                        if (active)
                        {
                            allPlayersLeft = false;
                            break;
                        }
                    }

                    // If all players have left the game
                    if (gameWon || allPlayersLeft)
                    {
                        cout << "All players have left the game.\n";
                        gameWon = true; // To ensure proper exit from the outer loop
                        break; // Exit the player loop
                    }
                }
                rounds++; // Increment round counter
            }

            // Display prompt to end game session
            cout << "\n\nPress Enter to end this game session...";
            cin.ignore(); // Wait for user to press enter
            cout << "Returning to starting menu soon";
            Sleep(3000); //Wait for 3 seconds
            system("cls"); //Clear the screen if necessary
        }
    }

    return 0;
}
