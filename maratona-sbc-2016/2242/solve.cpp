#include <bits/stdc++.h>

using namespace std;

#define DBG 0
#define DEBUG(X) if(X)

bool is_vocal(char c) {
    string vocals = "aeiou";
    for(auto v : vocals) {
        if(v == c) return true;
    }
    return false;
}

void solve(string s) {
    DEBUG(DBG) cout << s << endl;
    string ans = "S";
    int i, j, len;
    len = s.size(); i = 0; j = len - 1;
    while(i < j) {
        DEBUG(DBG) cout << "[ * ] " << i << " " << j << endl;
        while(i < len && !is_vocal(s[i])) {
            DEBUG(DBG) cout << "[ i ] " << i << " " << len << endl;
            i++;
        }
        DEBUG(DBG) cout << s[i] << endl;
        while(j && !is_vocal(s[j])) {
            DEBUG(DBG) cout << "[ j ] " << j << endl;
            j--;
        }
        if(s[i] != s[j]) {
            ans = "N";
            break;
        }
        i++;
        j--;
    }
    DEBUG(DBG) cout << "[ ans ] " << endl;
    cout << ans << endl;
}

int main() {
    string s;
    while(cin >> s) solve(s);
    return 0;
}