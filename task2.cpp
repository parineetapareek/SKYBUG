#include <iostream>
#include <cmath>
using namespace std;

double operation(char operation, double num1, double num2)
{
    switch (operation)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0)
        {
            cout << "Error: Division by zero is not allowed!" << endl;
            exit(1);
        }
        return num1 / num2;
    case '^':
        return pow(num1, num2);
    default:
        cout << "Error: Invalid operation!" << endl;
        exit(1);
    }
}

int main()
{
    char oprn, choice;
    double num1, num2;

    do
    {
        cout << "Enter the first number: ";
        cin >> num1;

        cout << "Enter the operation (+, -, *, /, ^): ";
        cin >> oprn;

        cout << "Enter the second number: ";
        cin >> num2;

        double result = operation(oprn, num1, num2);
        cout << "Result: " << result << endl;

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    return 0;
}