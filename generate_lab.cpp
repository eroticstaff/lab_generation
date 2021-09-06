//
// Created by xyamix on 06.09.2021.
//

#include "generate_lab.h"
#include <vector>
#include <string>
#include <time.h>

using namespace std;

vector<string> simple_generate_lab(int n, int m) {
    for (int c = 0; c < 1; c++) {
        srand(time(NULL) + c);
        vector<string> lab(n);
        for (int i = 0; i < n; i++) {
            string s;
            if (i % 2 == 0) {
                for (int j = 0; j < m; j++) {
                    s += "#";
                }
            } else {
                for (int j = 0; j < m; j++) {
                    if (j % 2 == 0) {
                        s += "#";
                    } else {
                        s += ".";
                    }
                }
            }
            lab[i] = s;
        }
        int count = 0;
        for (int y = 1; y < n; y += 2) {
            for (int x = 1; x < m; x += 2) {
                int side = rand() % 2;
                if (side == 0 && y != 1) {
                    lab[y - 1][x] = '.';
                    count += 1;
                } else if (side == 0 && y == 1) {
                    side = 1;
                }
                if (side == 1 && x != 1) {
                    lab[y][x - 1] = '.';
                    count += 1;
                } else if (side == 1 && x == 1 && y != 1) {
                    lab[y - 1][x] = '.';
                    count += 1;
                }
            }
        }
        lab[n - 2][m - 2] = 'F';
        return lab;
    }
}
