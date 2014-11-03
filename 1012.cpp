#include <vector>
#include <set>
#include <iostream>

using namespace std;

void check(vector<vector<int> > &link, vector<bool> &checked, int i) {
    if (!checked[i]) {
        checked[i] = true;

        for (int j = 0; j < link[i].size(); ++j) {
            check(link, checked, link[i][j]);
        }
    }
}

int main() {
    int N, M;

    while (cin >> N && N > 0 && cin >> M) {
        vector<vector<int> > link(N);

        for (; M > 0; --M) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;

            link[a].push_back(b);
            link[b].push_back(a);
        }

        vector<bool> checked(N, false);
        int count = -1;

        for (int i = 0; i < N; ++i) {
            if (!checked[i]) {
                ++count;
            }
            check(link, checked, i);
        }

        if (count < 0) {
            count = 0;
        }

        cout << count << endl;
    }

    return 0;
}
