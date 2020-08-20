#include "bits/stdc++.h"

using namespace std;

int cnt = 1;

void printT(int x, int y) {
    int a = cnt % 10;
    int b = cnt / 10 % 10;
    if (a == 7 && (b & 1))
        cout << '[' << x << ',' << y << ']';
    cnt++;
}

void printArray(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        printT(x1, y1);
    } else if (x1 == x2) {
        for (int j = y1; j <= y2; j++) {
            printT(x1, j);
        }
    } else if (y1 == y2) {
        for (int i = x1; i <= x2; i++) {
            printT(i, y1);
        }
    } else {
        for (int j = y1; j < y2; j++)
            printT(x1, j);
        for (int i = x1; i < x2; i++)
            printT(i, y2);
        for (int j = y2; j > x1; j--)
            printT(x2, j);
        for (int i = x2; i > x1; i--)
            printT(i, x1);
    }
}


void findT(int m, int n) {
    if (m < 10 || m > 1000 || n < 10 || n > 1000) {
        cout << "[]" << endl;
        return;
    }
    int x1 = 0, y1 = 0, x2 = m - 1, y2 = n - 1;
    cout << '[';
    while (x1 <= x2 && y1 <= y2) {
        printArray(x1++, y1++, x2--, y2--);
    }
    cout << ']';
}

int main() {
    int m, n;
    cin >> m >> n;
    findT(m, n);
    return 0;
}