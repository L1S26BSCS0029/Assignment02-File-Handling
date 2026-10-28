     /*
     * Name       : AHMED SHAHZAD
     * Reg No     : ;L1S26BSCS0029
     * Assignment : 02 - File Handling
     * Question   : Q4 - Heart Rate Cleaner
     */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile("heart_rate.txt");

    if (!inFile)
    {
        cout << "heart_rate.txt not found!" << endl;
        return 1;
    }

    int rate[100];
    int count = 0;
    int bad = 0;
    int x;
    char junk[50];
    int reason = 0;

    while (true)
    {
        if (count >= 100)                  // (1)
        {
            reason = 3;
            break;
        }

        if (inFile >> x)
        {
            if (x == -1)                   // (2)
            {
                reason = 1;
                break;
            }

            rate[count] = x;
            count++;                       // (3)
        }
        else if (inFile.eof())             // (4)
        {
            reason = 2;
            break;
        }
        else
        {
            inFile.clear();                // (5)
            inFile >> junk;
            bad++;
        }
    }

    inFile.close();

    // TO DO 1: Write every valid reading to clean_heart_rate.txt.
    ofstream outFile("clean_heart_rate.txt");

    for (int i = 0; i < count; i++)
    {
        outFile << rate[i] << endl;
    }

    outFile.close();

    // TO DO 2: Display the number of valid readings and junk skipped.
    cout << "Valid readings: " << count << endl ;
    cout << "Junk skipped: " << bad << endl;

    // TO DO 3: Display statistics.
    if (count == 0)
    {
        cout << "No valid readings!" << endl;
    }
    else
    {
        int total = 0;
        int highest = 0;
        highest = rate[0];
        int above = 0;
        int alerts = 0;

        for (int i = 0; i < count; i++)
        {
            total = total + rate[i];

            if (rate[i] > highest)
            {
                highest = rate[i];
            }

            if (rate[i] > 100)
            {
                alerts++;
            }
        }

        double average = (double)total / count;

        for (int i = 0; i < count; i++)
        {
            if (rate[i] > average)
            {
                above++;
            }
        }

        cout << "Average: " << average << endl;
        cout << "Highest: " << highest << endl;
        cout << "Above average: " << above << endl;
        cout << "Alerts (above 100): " << alerts << endl;
    }

    // TO DO 4: Display why reading stopped.
    cout << "Stopped because: ";

    if (reason == 1)
    {
        cout << "sentinel found" << endl;
    }
    else if (reason == 2)
    {
        cout << "end of file" << endl;
    }
    else if (reason == 3)
    {
        cout << "array full" << endl;
    }

    return 0;
}



