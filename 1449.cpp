#include <vector>
#include <iostream>

using namespace std;

int count;
bool data[500][500];
bool ok[500];
vector<int> result;

int main() {
    int m, x, y;
    while (cin >> count >> m) {
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < count; ++j) {
                data[i][j] = false;
            }
            ok[i] = false;
        }

        for (; m > 0; --m) {
            cin >> x >> y;
            data[x - 1][y - 1] = true;
        }

        result.clear();
        while (1) {
            bool go = false;
            int i, j;

            for (i = 0; i < count; ++i) {
                if (!ok[i]) {
                    go = true;

                    for (j = 0; j < count; ++j) {
                        if (!ok[j] && data[j][i]) break;
                    }

                    if (j == count) {
                        ok[i] = true;
                        result.push_back(i);
                        break;
                    }
                }
            }

            if (!go) break;
        }

        bool sp = false;

        for (int i = 0; i < count; ++i) {
            if (sp) cout << ' ';
            cout << result[i] + 1;
            sp = true;
        }
        cout << endl;
    }

    return 0;
}
