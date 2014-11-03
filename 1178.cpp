#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        vector<pair<int, int> > data;

        while (n > 0) {
            string s;

            cin >> s;

            if (s == "Insert") {
                pair<int, int> val;
                char chr;

                cin >> val.first >> chr >> chr >> val.second; // x+iy

                int mod2 = val.first * val.first + val.second * val.second;

                for (
                    vector<pair<int, int> >::iterator it = data.begin();
                    true;
                    ++it
                ) {
                    if (it == data.end()) {
                        data.push_back(val);
                        cout << "SIZE = " << data.size() << endl;

                        break;
                    }

                    int mod1 =
                        it->first * it->first
                        + it->second * it->second;

                    if (mod1 < mod2) {
                        continue;
                    }

                    if (mod1 == mod2 && it->second > val.second) {
                        continue;
                    }

                    if (mod1 == mod2 && it->second == val.second) {
                        //break;
                    }

                    data.insert(it, val);
                    cout << "SIZE = " << data.size() << endl;

                    break;
                }

                --n;
            } else if (s == "Pop") {
                if (data.empty()) {
                    cout << "empty" << endl;
                } else {
                    cout << data.back().first << "+i" << data.back().second << endl;
                    data.pop_back();
                    cout << "SIZE = " << data.size() << endl;
                }

                --n;
            }
        }
    }

    return 0;
}
