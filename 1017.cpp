#include <iostream>

using namespace std;

const int bigint = 1000000000;

int count;
int dist[100][100];
int new_d[100];
bool act[100];
bool fin[100];
bool xfin[100];

int main() {
    while (1) {
        cin >> count;

        if (!count) return 0;

        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < count; ++j) {
                dist[i][j] = bigint;
            }
            // act[i] = false;
            fin[i] = false;
            xfin[i] = false;
        }

        for (int i = 0; i < count * (count - 1) / 2; ++i) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            cin >> dist[x][y];
            dist[y][x] = dist[x][y];
        }

        fin[0] = true;

        int result = 0;

        while (true) {
            bool go = false;

            for (int i = 0; i < count; ++i) {
                act[i] = false;
                new_d[i] = bigint;
            }

            for (int i = 0; i < count; ++i) {
                if (fin[i] && !xfin[i]) {
                    xfin[i] = true;
                    for (int j = 0; j < count; ++j) {
                        if (fin[j]) continue;
                        if (new_d[j] < dist[i][j]) continue;

                        new_d[j] = dist[i][j];
                        go = true;
                        act[j] = true;
                        xfin[i] = false;
                    }
                }
            }
            /* for (int i = 0; i < count; ++i) {
                if (act[i]) cout << 'a';
                if (fin[i]) cout << 'f';
                if (xfin[i]) cout << 'x';
                cout << '(' << i + 1 << ')' << endl;
            }*/

            if (!go) break;

            int best = -1;
            int best_d = bigint;

            for (int i = 0; i < count; ++i) {
                if (!act[i]) continue;
                // cout << i + 1 << '-' << new_d[i] << endl;
                if (
                    best_d < new_d[i]
                ) continue;

                best = i;
                best_d = new_d[i];
            }
            // cout << "get " << best + 1 << '-' << best_d << endl;

            fin[best] = true;
            result += best_d;
        }

        cout << result << endl;

        /* for (int i = 0; i < count; ++i) {
            cout << i << ':' << min_d[i] << ' ' << min_p[i] << endl;
        }
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < count; ++j) {
                cout << dist[i][j] << ':' << price[i][j] << ' ';
            }
            cout << endl;
        }*/
    }

    return 0;
}
