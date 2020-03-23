#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    freopen("in", "r", stdin);
    int T, n, k;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        string s;
        cin >> s;
        int sm = 0;
        int l, r;
        while (k--) {
            set<char> ss;
            cin >> l >> r;
            map<char, int> mp;
            for (int t=l;t<=r;++t) {
                if (ss.count(s[t]))
                    ss.erase(s[t]);
                else
                    ss.insert(s[t]);
            }
            sm += (ss.size() == 1 || ss.size() == 0);
        }
        cout << sm << endl;
    }
}

