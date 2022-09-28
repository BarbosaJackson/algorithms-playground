#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, N, i = 0;
    map<int, int> values;
    cin >> N;
    while(i < N) {
        cin >> x;
        if(!values[x]) {
            values[x] = 0;
        }
        values[x]++;
        i++;
    }
    for(auto v : values) {
        while(v.second--) {
            N--;
            cout << v.first << (!N ? '\n' : ' ');
        }
    }
}

int main() {
    int N;
    while(cin >> N) {
        while(N--) {
            solve();
        }
    }
    return 0;
}