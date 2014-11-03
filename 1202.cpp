#include <vector>
#include <iostream>

using namespace std;

void sortx(vector<int> &data) {
    if (data.empty()) {
        return;
    }

    vector<int> ff;
    vector<int> bb;
    int flag = data[0];

    for (int i = 1; i < data.size(); ++i) {
        if (data[i] < flag) {
            ff.push_back(data[i]);
        } else {
            bb.push_back(data[i]);
        }
    }

    sortx(ff);
    sortx(bb);

    data.clear();

    for (int i = 0; i < ff.size(); ++i) {
        data.push_back(ff[i]);
    }

    data.push_back(flag);

    for (int i = 0; i < bb.size(); ++i) {
        data.push_back(bb[i]);
    }
}

int main() {
    int n;

    while (cin >> n) {
        vector<int> data(n);

        for (int i = 0; i < n; ++i) {
            int val;

            cin >> val;
            data[i] = val;
        }

        sortx(data);

        for (int i = 0; i < n; ++i) {
            cout << data[i] << ' ';
        }

        cout << endl;
    }

    return 0;
}
