#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int num = rand() % 100 + 1;

    int guess, attempt = 0;

    cout << "Random Number Guessing Game!" << endl;
    cout << "Guess a number between 1 and 100" << endl;

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < 1 || guess > 100)
        {
            cout << "Please enter a number between 1 and 100" << endl;
            continue;
        }

        attempt++;

        if (guess == num)
        {
            cout << "Congratulations! You guessed the correct number in " << attempt << " attempts" << endl;
        }
        else if (guess < num)
        {
            cout << "Too low! Try guessing a greater number!!" << endl;
        }
        else
        {
            cout << "Too high! Try guessing a smaller number!!" << endl;
        }

    } while (guess != num);

    return 0;
}