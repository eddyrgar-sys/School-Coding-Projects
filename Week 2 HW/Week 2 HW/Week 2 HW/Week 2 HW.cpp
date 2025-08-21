//This program asks for a password then verifies that it meets the stated criteria. 
//If it doesn’t, the program should display a message telling the user why.
//Programer: Eddy Garcia

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isValidPassword(const string& password) 
{
    if (password.length() < 6) 
    {
        cout << "Password must be at least 6 characters long." << endl;
        return false;
    }

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;

    for (char ch : password) 
    {
        if (isupper(ch)) 
        {
            hasUppercase = true;
        }
        else if (islower(ch)) 
        {
            hasLowercase = true;
        }
        else if (isdigit(ch)) 
        {
            hasDigit = true;
        }
    }

    if (!hasUppercase) 
    {
        cout << "Password must contain at least one uppercase letter." << endl;
        return false;
    }

    if (!hasLowercase) 
    {
        cout << "Password must contain at least one lowercase letter." << endl;
        return false;
    }

    if (!hasDigit) 
    {
        cout << "Password must contain at least one digit." << endl;
        return false;
    }

    return true;
}

int main() 
{
    string password;

    cout << "Enter your password: ";
    getline(cin, password);

    if (isValidPassword(password)) 
    {
        cout << "Password is valid!" << endl;
    }
    else 
    {
        cout << "Password is invalid. Please try again." << endl;
    }

    return 0;
}
