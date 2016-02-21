#include <iostream>

#include "GuessClass.h"

using namespace std;

int getSmallNumber()
{
	do
	{
		int userMinNumber;
		cout << "Please enter the smallest number you'd like in your range: " << flush;
		cin >> userMinNumber;

		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Please only enter numeric values." << endl;

		} else
		{
			return userMinNumber;
		}
	} while (!cin);
}

int getLargeNumber()
{
	do
	{
		int userMaxNumber;
		cout << "Please enter the largest number you'd like in your range: " << flush;
		cin >> userMaxNumber;

		if (!cin)
		{
			cin.clear();
			cin.ignore();

			cout << "Please only enter numeric values." << endl;

		} else
		{
			return userMaxNumber;
		}
	} while (!cin);
}

bool checkRange(int smallNumberIn, int largeNumberIn)
{
	if (smallNumberIn == largeNumberIn)
	{
		cout << endl << "The smallest number cannot be equal to the largest one.\n" << endl;

	} else if (smallNumberIn > largeNumberIn)
	{
		cout << endl << "Please enter the smaller number before the larger one." << endl;

	} else
	{
		return true;
	}
}

void guess(int smallNumberIn, int largeNumberIn, int randomNumberIn)
{
	int userGuess;

	bool correctGuess = false;

	do
	{
		cout << "Please guess a number between: \"" << smallNumberIn << "\" and: \"" << largeNumberIn << "\": " << flush;
		cin >> userGuess;

		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please only enter numeric values." << endl;

		} else if (userGuess < smallNumberIn || userGuess > largeNumberIn)
		{
			cout << "The range is from: \"" << smallNumberIn << "\" to: \"" << largeNumberIn << "\". Please guess within that range." << endl;

		} else if (userGuess > randomNumberIn)
		{
			cout << "Too high, please try again." << endl;

		} else if (userGuess < randomNumberIn)
		{
			cout << "Too low, please try again." << endl;

		} else if (userGuess == randomNumberIn)
		{
			correctGuess = true;
		}
	} while (!correctGuess);

	cout << "Congratulations! You guessed: " << "\"" << randomNumberIn << "\"" << ", and that was correct!\n" << endl;
}

bool exit()
{
	char userInput;
	bool validInput = false;

	do
	{
		cout << "Would you like to try again? (y/n): " << flush;
		cin >> userInput;

		switch (userInput)
		{
			case 'y':
			case 'Y': cout << "Continuing...\n" << endl;
					  validInput = true;
					  break;
			case 'n':
			case 'N': cout << "Exiting..." << endl;
					  validInput = true;
					  return true;
					  break;

			default: cin.clear();
					 cin.ignore(100, '\n');
					 cout << "Invalid input, please press \"y\" or \"n\"." << endl;
					 break;
		}
	} while (!validInput);
}





