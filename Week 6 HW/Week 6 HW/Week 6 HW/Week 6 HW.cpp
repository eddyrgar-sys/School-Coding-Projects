//Week 6 HW - Numbers Class
//Programmer: Eddy Garcia

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Numbers 
{

private:
    int number;
    static const string lessThan20[20];
    static const string tens[10];
    static const string hundred;
    static const string thousand;

public:
    //Constructor that accepts a nonnegative integer
    Numbers(int num) : number(num) {}

    //Function to print the English description of the number
    void print() const 
    {
        if (number == 0) 
        {
            cout << lessThan20[0] << endl;
        }
        else {
            cout << convertToWords(number) << endl;
        }
    }

private:
    //Helper function to convert the number to English words
    string convertToWords(int num) const 
    {
        if (num == 0) return "";

        if (num < 20) 
        {
            return lessThan20[num];
        }
        if (num < 100) 
        {
            return tens[num / 10] + (num % 10 != 0 ? " " + lessThan20[num % 10] : "");
        }
        if (num < 1000) 
        {
            return lessThan20[num / 100] + " " + hundred + (num % 100 != 0 ? " " + convertToWords(num % 100) : "");
        }
        return lessThan20[num / 1000] + " " + thousand + (num % 1000 != 0 ? " " + convertToWords(num % 1000) : "");
    }
};

//Static arrays for translating key numbers
const string Numbers::lessThan20[20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                                        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

const string Numbers::tens[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

const string Numbers::hundred = "hundred";
const string Numbers::thousand = "thousand";

//Main function to test the class
int main() 
{
    int number;

    cout << "Enter a number between 0 and 9999: ";
    cin >> number;

    if (number < 0 || number > 9999) 
    {
        cout << "Invalid number. Please enter a number between 0 and 9999." << endl;
    }
    else 
    {
        Numbers num(number);
        num.print();
    }

    return 0;
}
