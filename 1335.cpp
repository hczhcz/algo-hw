#include <iostream>

using namespace std;

const int bigint = 10000;

int size;
int data[100][100];
int len[100][100];

void visit(int x = 0, int y = 0, int d = 0) {
    if (x >= size || y >= size || x < 0 || y < 0) return;
    if (data[x][y]) return;
    if (len[x][y] <= d) return;
    if (d + (size - 1 - x) + (size - 1 - y) >= len[size - 1][size - 1]) return;

    len[x][y] = d;

    visit(x + 1, y, d + 1);
    visit(x, y + 1, d + 1);
    visit(x - 1, y, d + 1);
    visit(x, y - 1, d + 1);
}

int main() {
    while (cin >> size) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cin >> data[i][j];
                len[i][j] = bigint;
            }
        }

        visit();

        int result = len[size - 1][size - 1];
        cout << (result == bigint ? -1 : result) << endl;
    }

    return 0;
}
