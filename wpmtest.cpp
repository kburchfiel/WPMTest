//AMDG
//WPMTest (a simple typing test)
//Kenneth Burchfiel (First release: 8/28/2020)

#include <iostream>
#include <chrono>

using namespace std; //Not best practice but OK in my opinion for a simple program like this
using namespace chrono; //This line proved to be necessary as well in order to get the program to compile

double wpmtest(string s, double d, double w)
{
    cout << "Begin typing!\n";
    while (true)
    {

        auto starttime = system_clock::now();

        string e;
        getline(cin, e);
        if (e == s)
        {
            auto endtime = system_clock::now();
            double time = duration_cast<milliseconds>(endtime - starttime).count();
            cout << "Complete! the time was " << time / 1000 << " seconds.\n";
            double WPM = (w / time) * 60000; //There are 60,000 milliseconds in a minute, so we need to multiply the number of words by 60K to convert from milliseconds to minutes
            cout << "Your WPM (with 5 characters equaling one word) was " << WPM << ".\n";

            return WPM;
        }
        if (e != s && e.size() != 0) //e.size() !=0 is added in so that the program doesn't declare the user's entry incorrect before an entry even appears.
        {
            cout << "Text was incorrect. Please try again.\n";
        }
    }
}

int main()

{
    cout << "Please enter a line of text that you would like to type.\n";
    string stringtotype;
    while (true)
    {
        getline(cin, stringtotype);
        if (stringtotype.size() == 0)
        {
            cout << "No text was entered. Please try again.\n";
            continue;
        }
        break;
    }

    double chars = stringtotype.size();
    double words = chars / 5;
    double WPM;
    cout << "The text \"" << stringtotype << "\" has " << chars << " characters (including spaces), which equates to " << words << " words for the purpose of calculating WPM.\n";

    cout << " The timer will start when you type any letter/number followed by Enter.\n";

    char c;
    cin >> c;

    if (cin)
    {
        while (true)
        {
            double WPM = wpmtest(stringtotype, chars, words);

            if (WPM < 30) //These if statements don't share any additional info, but are more of a proof of concept for future programs that may use these WPM brackets in different ways
            {
                cout << "Your WPM was less than 30. Keep practicing!\n";
            }
            if (WPM >= 30 && WPM < 60)
            {
                cout << "Not bad! Your WPM was in between 30 and 60.\n";
            }

            if (WPM >= 60 && WPM < 120)
            {
                cout << "Good job! Your WPM was in between 60 and 120.\n";
            }
            if (WPM >= 120 && WPM < 150)
            {
                cout << "Amazing! Your WPM was in between 120 and 150.\n";
            }
            if (WPM >= 150 && WPM < 200)
            {
                cout << "Extraordinary! Your WPM was in between 150 and 200!\n";
            }
            if (WPM >= 200)
            {
                cout << "Legendary! Your WPM was 200 or higher!\n";
            }
            cout << "Would you like to try again? If yes, type any letter other than 'q'; if not, type 'q'.\n";
            char c2;
            cin >> c2;
            if (c2 != 'q')
            {
                continue;
            }
            else
                break;
        }
    }

    cout << "Press any character to exit the program, or simply close the window.\n";

    char c2;
    cin >> c2;
}
