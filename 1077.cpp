#include <iostream>

using namespace std;

int main() {
    long long count;

    while (cin >> count) {
        long long s = 0;
        long long best;

        long long i = 0;
        for (long long i = 0; i < count; ++i) {
            long long last;
            cin >> last;
            if (i == 0) {
                best = last;
            }
            s += last;
            if (s > best) {
                best = s;
            }
            if (s < 0) {
                s = 0;
            }
        }

        cout << best << endl;
    }

    return 0;
}
