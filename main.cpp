#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "solve_lab.h"
#include "generate_lab.h"

using namespace std;

int main() {
    int n = 51;
    int m = 119;
    vector<string> lab = simple_generate_lab(n, m);
    int k = search_path(lab, 1, 1);
    cout << k << endl;
return 0;
}
