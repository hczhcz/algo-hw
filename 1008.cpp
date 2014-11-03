#include <iostream>

using namespace std;

const int bigint = 1000000000;

int count;
int dist[1000][1000];
int price[1000][1000];
int min_d[1000];
int min_p[1000];
bool act[1000];
bool fin[1000];
bool xfin[1000];

int main() {
    while (1) {
        int m;
        cin >> count >> m;

        if (!count) return 0;

        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < count; ++j) {
                dist[i][j] = bigint;
                price[i][j] = bigint;
            }
            min_d[i] = bigint;
            min_p[i] = bigint;
            // act[i] = false;
            fin[i] = false;
            xfin[i] = false;
        }

        for (; m > 0; --m) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            cin >> dist[x][y] >> price[x][y];
            dist[y][x] = dist[x][y];
            price[y][x] = price[x][y];
        }

        int s, t;
        cin >> s >> t;
        --s; --t;

        min_d[s] = 0;
        min_p[s] = 0;
        fin[s] = true;

        while (true) {
            bool go = false;

            for (int i = 0; i < count; ++i) {
                act[i] = false;
            }

            for (int i = 0; i < count; ++i) {
                if (fin[i] && !xfin[i]) {
                    xfin[i] = true;
                    for (int j = 0; j < count; ++j) {
                        if (fin[j]) continue;
                        if (
                            min_d[j] < min_d[i] + dist[i][j]
                        ) continue;
                        if (
                            min_d[j] == min_d[i] + dist[i][j] &&
                            min_p[j] <= min_p[i] + price[i][j]
                        ) continue;

                        min_d[j] = min_d[i] + dist[i][j];
                        min_p[j] = min_p[i] + price[i][j];

                        go = true;
                        act[j] = true;
                        xfin[i] = false;
                    }
                }
            }

            if (!go) break;

            int best = -1;
            int best_d = bigint;
            int best_p = bigint;

            for (int i = 0; i < count; ++i) {
                if (!act[i]) continue;
                if (
                    best_d < min_d[i]
                ) continue;
                if (
                    best_d == min_d[i] &&
                    best_p <= min_p[i]
                ) continue;

                best = i;
                best_d = min_d[i];
                best_p = min_p[i];
            }

            fin[best] = true;
        }

        cout << min_d[t] << ' ' << min_p[t] << endl;

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
