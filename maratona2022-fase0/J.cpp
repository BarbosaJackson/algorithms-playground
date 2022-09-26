#include <bits/stdc++.h>
using namespace std;
int main () {
    int times;
    cin >> times;
    while(times--) {
        int t;
        string s;
        cin >> t >> s;
        int t1, ac = 0;
        if(t > 45) {
            t1 = 45;
            ac = t-t1;
        } else {
            t1=t;
        }
        if(s[0] == '2') {
            t1 += 45;
        }
        cout << t1;
        if(ac) cout << "+" << ac;
        cout << endl;
    }
    return 0;
}