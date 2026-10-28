/*
 * Name       : AHMED SHAHZAD
 * Reg No     : L1S26BSCS0029
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */



#include <iostream>
#include <fstream>  // FIX 1: <fstream> was missing, so we added it.
using namespace std;

int main() {

    ifstream inFile("stock.txt");

    // FIX 2: This was not written !inFile  as it checks whether opening failed or not .
    if (!inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    // FIX 3: ios::app is needed to preserve old lines and to write new lines at the end of file  reorder.txt.
    ofstream reorder("reorder.txt", ios::app);

    char code[10];
    int qty, count = 0, low = 0;
    double price;

    // FIX 4: int loses decimal values; so we use decimal datatype.
    double total = 0;

    // FIX 5: Skip the first line because it contains the header, not item data.
    inFile.ignore(1000, '\n');

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;

        // FIX 6: Write endl after each reorder record so every item gets its own line.
        total = total + qty * price;
        if (qty < 10) {
            reorder << code << " " << qty << endl;
            low++;
        }
    }

    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;

    return 0;
}
