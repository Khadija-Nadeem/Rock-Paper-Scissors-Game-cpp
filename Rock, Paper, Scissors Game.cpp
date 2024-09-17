#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

void playRound(int& wins, int& losses, int& ties) {
    // Randomly generate computer's choice
    string options[] = {"Rock", "Paper", "Scissors"};
    srand(time(0));  // Seed random number generator
    int computerChoice = rand() % 3;  // Generate number between 0 and 2

    // Get player's choice
    int playerChoice;
    cout << "Get ready to battle! \n"<<endl;
    cout << "Choose your weapon: \n1. Rock ??\n2. Paper ??\n3. Scissors ??\nEnter your choice (1-3): \n"<<endl;
    cin >> playerChoice;
    cout << endl;
    playerChoice--;  // Convert player input to match array index

    if (playerChoice < 0 || playerChoice > 2) {
        cout << "Oops! That's not a valid choice. Please pick again!\n"<<endl;
        return;
    }

    cout << "You chose: " << options[playerChoice] << " ??\n"<<endl;
    cout << "Computer chose: " << options[computerChoice] << " ??\n"<<endl;

    // Determine winner
    if (playerChoice == computerChoice) {
        cout << "It's a tie! ?? Great minds think alike!\n"<<endl;
        ties++;
    } else if ((playerChoice == 0 && computerChoice == 2) ||
               (playerChoice == 1 && computerChoice == 0) ||
               (playerChoice == 2 && computerChoice == 1)) {
        cout << "Victory is yours! ?? You crushed the computer!\n"<<endl;
        wins++;
    } else {
        cout << "You lose this round... but don't give up! ?? Try again!\n"<<endl;
        losses++;
    }
}


int main() {
    int wins = 0, losses = 0, ties = 0;
    char playAgain;

    cout << "Welcome to Rock, Paper, Scissors!\n"<<endl;

    do {
        playRound(wins, losses, ties);
        cout << "Do you want to play again? (y/n): \n"<<endl;
        cin >> playAgain;
        cout  <<endl;
    } while (playAgain == 'y' || playAgain == 'Y');

    // Display final stats
    cout << "\nGame Over!\n"<<endl;
    cout << "Wins: " << wins << "\n";
    cout << "Losses: " << losses << "\n";
    cout << "Ties: " << ties << "\n";

    return 0;
}

