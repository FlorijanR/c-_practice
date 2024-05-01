#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ifstream inFile;
    string fileName;

    cout << "Unesite ime datoteke: ";
    cin >> fileName;
    inFile.open(fileName);
    if (!inFile)
    {
        cerr << "Unable to open file";
        exit(1);
    }

    int n;
    inFile >> n;
    int array[n][n];

    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inFile >> x;
            array[i][j] = x;
        }
    }
    inFile.close();

    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

    bool exists = false;
    int length = 0;
    for (int j = 0; n - j > 2 && !exists; j++) {
        sort(a, a + n);

        do {
            exists = true;

            for (int i = 0; i < n - j; i++) {
                if (i == n - j - 1) {
                    if (!array[a[0]][a[i]]) {
                        exists = false;
                    }
                } else {
                    if (!array[a[i]][a[i + 1]]) {
                        exists = false;
                        break;
                    }
                }
            }
            
            if (exists) length = n - j;
        } while (!exists && next_permutation(a, a + n));
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl << length;

    return 0;
}