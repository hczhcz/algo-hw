#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n1, n2;

    while (cin >> n1) {
        vector<int> data1, data2;

        for (int n = n1; n > 0; --n) {
            int val;

            cin >> val;
            data1.push_back(val);
        }

        cin >> n2;

        for (int n = n2; n > 0; --n) {
            int val;

            cin >> val;
            data2.push_back(val);
        }

        int val;
        int s = 0;
        int a = 0;
        int b = 0;
        while (s <= (n1 + n2 - 1) / 2) {
            if (a >= data1.size()) {
                val = data2[b];
                ++b;
            } else if (b >= data2.size()) {
                val = data1[a];
                ++a;
            } else {
                if (data1[a] > data2[b]) {
                    val = data2[b];
                    ++b;
                } else {
                    val = data1[a];
                    ++a;
                }
            }
            ++s;
        }
        cout << val << endl;
    }

    return 0;
}
