#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#define ll long long
using namespace std;

int main() {
    freopen("in", "r", stdin);
    ll T, n, k, p;
    cin >> T;
    for (ll lk=1;lk<=T;lk++) {
        cout << "Case #" << lk << ": ";
        cin >> n >> k >> p;

        ll tm;
        stack<ll> st[n];
        vector<ll> va;
        for (ll t=0;t<n;++t) {
            va.clear();
            for (ll tt=0;tt<k;++tt) {
                cin >> tm;
                va.push_back(tm);
            }
            for (ll ta=va.size()-1;ta>=0;--ta) st[t].push(va[ta]);
        }
        ll sm = 0, in;
        while (p--) {
            ll max_ = 0;
            in = -1;
            for (ll t=0;t<n;++t) {
                if (st[t].empty()) continue;

                if (st[t].top() > max_) {
                    max_ = st[t].top();
                    in = t;
                }
            }
            sm += max_;
            if (in != -1) st[in].pop();
        }
        cout << sm << endl;
    }
}

