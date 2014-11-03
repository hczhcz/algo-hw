#include <vector>
#include <set>
#include <iostream>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        set<int> data;

        for (; n > 0; n--) {
            int val;

            cin >> val;
            data.insert(val);
        }

        bool first = true;
        for (set<int>::iterator it = data.begin(); it != data.end(); ++it) {
            if (!first) {
                cout << ' ';
            }

            cout << *it;
            first = false;
        }

        cout << endl;
    }

    return 0;
}
