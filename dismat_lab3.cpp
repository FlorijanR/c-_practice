#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(void)
{
    ifstream inFile;
    string fileName;

    cout << "Unesite ime datoteke: ";
    cin >> fileName;
    inFile.open(fileName);
    if (!inFile) {
        cerr << "Unable to open file";
        exit(1);
    }

    int n;
    inFile >> n;
    int neighbour[n][n];

    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> x;
            neighbour[i][j] = x;
        }
    }
    inFile.close();

    int colors[n];
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }

    int k; // base == k
    bool legal = true;
    for (k = 1; k <= n; k++) {

        for (int number = 0; number + 0.5 < pow(k, n); number++) {

            int current = n - 1;
            for (int help = number; help != 0; help /= k) {
                colors[current--] = help % k;
            }
            
            legal = true;
            for (int e = 0; e < n; e++) {
                for(int i = 0; i < n; i++) {
                    if (neighbour[e][i] == 1) {
                        if (colors[i] == colors[e]) {
                            legal = false;
                        }
                    }
                }
            }

            if (legal) break;

            for (int i = 0; i < n; i++) {
                colors[i] = 0;
            }
        }

        if (legal) break;
    }

    cout << k;

    return 0;
}