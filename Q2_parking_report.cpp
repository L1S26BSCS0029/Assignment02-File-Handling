/*
 * Name       : AHMED SHAHZAD
 * Reg No     : L1S26BSCS0029
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream inFile("parking.txt");

    if (!inFile)
    {
        cout << "parking.txt not found!" << endl;
        return 1;
    }

    int d, m, y;
    char slash;

    inFile >> d >> slash >> m >> slash >> y;

    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');

    ofstream outFile("receipts.txt");

    outFile << "Receipts for " << d << "/" << m << "/" << y << endl;

    char plate[15];
    char longestPlate[15] = "";
    char type;
    char inTime[6], outTime[6];

    int count = 0;
    int cars = 0, bikes = 0;
    int total = 0;
    int longest = -1;

    cout << "Parking report for "
        << d << "/" << m << "/" << y << endl;

    while (count < 30 &&
        inFile >> plate >> type >> inTime >> outTime)
    {
        int inHour = (inTime[0] - '0') * 10
            + (inTime[1] - '0');

        int inMin = (inTime[3] - '0') * 10
            + (inTime[4] - '0');

        int outHour = (outTime[0] - '0') * 10
            + (outTime[1] - '0');

        int outMin = (outTime[3] - '0') * 10
            + (outTime[4] - '0');

        int start = inHour * 60 + inMin;
        int finish = outHour * 60 + outMin;

        int minutes = finish - start;

        int hoursCharged = (minutes + 59) / 60;

        if (hoursCharged == 0)
        {
            hoursCharged = 1;
        }

        int fee;

        if (type == 'C')
        {
            fee = hoursCharged * 100;
            cars++;
        }
        else
        {
            fee = hoursCharged * 40;
            bikes++;
        }

        int h = minutes / 60;
        int min = minutes % 60;

        if (type == 'C')
        {
            cout << plate << " Car ";
        }
        else
        {
            cout << plate << " Bike ";
        }

        cout << h << " h " << min
            << " min Fee: " << fee << endl;

        outFile << plate << " " << fee << endl;

        total = total + fee;

        if (minutes > longest)
        {
            longest = minutes;
            strcpy(longestPlate, plate);
        }

        count++;
    }

    inFile.close();
    outFile.close();

    if (count == 0)
    {
        cout << "No vehicles found!" << endl;
        return 0;
    }

    cout << "Vehicles: " << count << endl;

    cout << "Cars: " << cars
        << " Bikes: " << bikes << endl;

    cout << "Total collected: " << total << endl;

    cout << "Longest stay: " << longestPlate << " ("
        << longest / 60 << " h "
        << longest % 60 << " min)" << endl;

    return 0;
}
