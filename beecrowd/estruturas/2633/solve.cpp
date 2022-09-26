#include <bits/stdc++.h>

using namespace std;

void solve(int N) {
    set<pair<int, string>> meat;
    int valid;
    string name;
    while(N--) {
        cin >> name >> valid;
        meat.insert({valid, name});
    }
    int i = 0;
    int lim = meat.size();
    for(auto m : meat) {
        cout << m.second << (i + 1 == lim ? '\n' : ' ');
        i += 1;
    }
}

int main() {
    int N;
    while(cin >> N) solve(N);
    return 0;
}