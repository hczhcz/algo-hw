#include <iostream>

using namespace std;

int count;
int input[100];
int result[100];

int main() {
    while (cin >> count) {
        for (int i = 0; i < count; ++i) {
            cin >> input[i];
            result[i] = 0;
        }

        int best = 0;
        for (int i = count - 1; i >= 0; --i) {
            result[i] = 0;
            for (int j = i; j < count; ++j) {
                if (input[i] >= input[j]) {
                    int new_r = result[j] + 1;
                    if (new_r > result[i]) {
                        result[i] = new_r;
                    }
                }
            }
            if (result[i] > best) {
                best = result[i];
            }
        }

        cout << best << endl;
    }

    return 0;
}
