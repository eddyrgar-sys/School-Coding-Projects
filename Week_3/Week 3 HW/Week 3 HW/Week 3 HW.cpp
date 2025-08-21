// This program displays a menu allowing the user to select air, water, or steel. 
// After the user has made a selection, he or she should be asked to enter the 
// distance a sound wave will travel in the selected medium. The program will 
// then display the amount of time it will take. (Rounded to four decimal places.)

//Programmer: Eddy Garcia

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //Feet per second = FPS
    const int AIR_FPS = 1100,
        WATER_FPS = 4900,
        STEEL_FPS = 16400,
        MIN_DISTANCE = 0;

    int user_menu_choice;

    float travel_distance,time;

    cout << " Select a Medium " << endl;
    cout << "----------------- " << endl;
    cout << "    1. Air         " << endl;
    cout << "    2. Water       " << endl;
    cout << "    3. Steel       " << endl;
    cout << "----------------- " << endl;
    cin >> user_menu_choice;

    switch (user_menu_choice)
    {
    case 1:
    case 2:
    case 3:
        cout << "\nHow far will the sound wave travel? ";
        cin >> travel_distance;

        if (travel_distance < MIN_DISTANCE)
        {
            cout << "\nError. Distance must be more than 0.\n";
            cout << "Re-run the program and try again.\n" << endl;
        }
        else
        {
            // Valid
            if (user_menu_choice == 1)
            {
                time = travel_distance / AIR_FPS;
                cout << setprecision(4) << fixed;
                cout << "A sound wave takes " << time; cout << " seconds to travel through air." << endl;
            }
            if (user_menu_choice == 2)
            {
                time = travel_distance / WATER_FPS;
                cout << setprecision(4) << fixed;
                cout << "A sound wave takes " << time; cout << " seconds to travel through water." << endl;
            }
            if (user_menu_choice == 3)
            {
                time = travel_distance / STEEL_FPS;
                cout << setprecision(4) << fixed;
                cout << "A sound wave takes " << time; cout << " seconds to travel through steel." << endl;
            }
         }
    break;

    default:
        cout << "\nPlease choose a number between 1 and 3." << endl;
        cout << "Re-run the program and try again.\n" << endl;
        break;
    }
    return 0;
}