#include <iostream>
#include <ctime>
#include <cstdlib>

#include "GuessClass.h"

using namespace std;

int main()
{
	unsigned seed = static_cast<unsigned>(time(0));
	srand(seed);

	int smallNumber = 0;
	int largeNumber = 0;

	do
	{
		do
		{
			smallNumber = getSmallNumber();
			largeNumber = getLargeNumber();

		} while (!checkRange(smallNumber, largeNumber));

		int randomNumber = (rand() % (1 + largeNumber - smallNumber)) + smallNumber;

		guess(smallNumber, largeNumber, randomNumber);

	} while (!exit());

	return 0;
}
