#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        cout << "Case #" << tt << ": ";
        int n, k;
        cin >> n >> k;
        int a[n];
       
        for (int t=0;t<n;++t) cin >> a[t];
        sort(a, a+n);
       
        int ct = 0, ss = 0;
        for (int t=0;t<n;++t) {
            if (ss + a[t] <= k) {
                ss += a[t];
                ++ct;
            }
        }
        cout << ct << endl;
    }
}


