#include <iostream>
#include <string>
#include <vector>
#include "solve_lab.h"
#include <windows.h>
using namespace std;

void print_lab(vector<string> lab) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (auto i: lab) {
        for (auto j: i) {
            if (j == '+'){
                SetConsoleTextAttribute(hConsole,2);
                cout<< j;
            }
            else{
                SetConsoleTextAttribute(hConsole,1);
                cout << j;
            }
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

int search_path(vector<string> lab, int x, int y) {
    int k = 0;
    if (x + 1 < lab[0].length() && lab[y][x + 1] != '#' && lab[y][x + 1] != '+') {
        if (lab[y][x + 1] == 'F') {
            cout << "YOOOHHOOO" << endl;
            print_lab(lab);
            return 1;
        }
        lab[y][x + 1] = '+';
        k = search_path(lab, x + 1, y);
        if (k == 1) return k;
        else lab[y][x + 1] = '.';
    }
    if (x - 1 >= 0 && lab[y][x - 1] != '#' && lab[y][x - 1] != '+') {
        if (lab[y][x - 1] == 'F') {
            cout << "YOOOHHOOO" << endl;
            print_lab(lab);
            return 1;
        }
        lab[y][x - 1] = '+';
        k = search_path(lab, x - 1, y);
        if (k == 1) return k;
        else lab[y][x + 1] = '.';
    }
    if (y + 1 < lab.size() && lab[y + 1][x] != '#' && lab[y + 1][x] != '+') {
        if (lab[y + 1][x] == 'F') {
            cout << "YOOOHHOOO" << endl;
            print_lab(lab);
            return 1;
        }
        lab[y + 1][x] = '+';
        k = search_path(lab, x, y + 1);
        if (k == 1) return k;
        else lab[y][x + 1] = '.';
    }
    if (y - 1 < lab.size() && lab[y - 1][x] != '#' && lab[y - 1][x] != '+') {
        if (lab[y - 1][x] == 'F') {
            cout << "YOOOHHOOO" << endl;
            print_lab(lab);
            return 1;
        }
        lab[y - 1][x] = '+';
        k = search_path(lab, x, y - 1);
        if (k == 1) return k;
        else lab[y][x + 1] = '.';
    }
    return k;

}
