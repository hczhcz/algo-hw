#include <iostream>

using namespace std;

int count;
int data[100];
int sum;
int sumhalf;
int xc;

void simplesort() {
    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (data[i] < data[j]) {
                int t = data[i];
                data[i] = data[j];
                data[j] = t;
            }
        }
    }
}

int dotry(int i = 0, int s = 0) {
    if (s >= sumhalf) return s;
    if (i >= count) return sum;

    ++xc;
    if (xc > 1000000) return sum;

    int result = dotry(i + 1, s + data[i]);
    int result2 = sum;
    if (i != sumhalf) result2 = dotry(i + 1, s);

    return result2 > result ? result : result2;
}

int main() {
    while (cin >> count) {
        sum = 0;
        xc = 0;

        for (int i = 0; i < count; ++i) {
            cin >> data[i];
            sum += data[i];
        }

        sumhalf = (sum + 1) >> 1;

        simplesort();

        int result = dotry();

        cout << result - (sum - result) << endl;
    }

    return 0;
}
