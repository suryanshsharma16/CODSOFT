#include <iostream>
using namespace std;

int main()
{
    float num1;
    float num2;
    cout << "Enter the first number : ";
    cin >> num1;
    // cout << endl;
    cout << "Enter the second number : ";
    cin >> num2;
    // cout << endl;
    int choice = 0;
    double sum = 0;
    float div = 0;
    double diff = 0;
    double prod = 0;
    cout << "The Calculator performs following arithmetic operations:\n 01. Addition\n 02. Subtraction\n 03. Multiplication\n 04. Division";
    cout << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    if (choice == 4 and num2 == 0)
    {
        cout << "Undefined";
        return 0;
    }
    if (choice == 1)
    {
        sum = num1 + num2;
        cout << "The sum of " << num1 << " and " << num2 << " is " << sum;
    }
    else if (choice == 2)
    {
        diff = num1 - num2;
        cout << "The difference of " << num1 << " and " << num2 << " is " << diff;
    }
    else if (choice == 3)
    {
        prod = num1 * num2;
        cout << "The product of " << num1 << " and " << num2 << " is " << prod;
    }
    else if (choice == 4)
    {
        div = num1 / num2;
        cout << "The division of " << num1 << " and " << num2 << " is " << div;
    }
    return 0;
}