#include <iostream>
#include <vector>
#include <algorithm>


#define debug true
using namespace std;

class Date
{
public:
    int year;
    int month;
    int day;

    Date (int y, int m, int d):
        year(y), month(m), day(d) {}

    // a: 2023-12-25
    // b: 2023-12-25
    bool less(Date a, Date b) {
        if (a.year < b.year) return true;
        if (a.month < b.month) return true;
        if (a.day < b.day) return true;
        return false;

        // stable
    }


};

// linter
void foo() { // foo, bar
    if (debug) {
        cout << "debug!\n";
        return;
    }
    else cout << "NOTHING\n";
}

int main() {
    Date d = {2023, 7, 4}; // format: 2023-7-4
    Date d2 = {2023, 12, 25}; // format: 2023-7-4
    Date d3 = {2023, 1, 2}; // format: 2023-7-4

    cout << d.year << "-"
         << d.month << "-"
         << d.day << "\n";

    cout << d.less(d, d2) << "\n";
    cout << d.less(d, d3) << "\n";


    return 0;
}

// TODO: string format