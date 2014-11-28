#include <iostream>

using namespace std;

int size;
int count;
int bestv[2000];

int main() {
    while (cin >> size >> count) {
        for (int s = 0; s <= size; ++s) {
            bestv[s] = 0;
        }

        for (int i = 0; i < count; ++i) {
            int now_s, now_v;
            cin >> now_s >> now_v;

            for (int s = size; s >= now_s; --s) {
                bestv[s] = max(bestv[s], bestv[s - now_s] + now_v);
            }
        }

        cout << bestv[size] << endl;
    }

    return 0;
}
