#include <bits/stdc++.h>
#define DEBUG() if(0)
#define MAXN 200005
#define LEFT(X) (X << 1)
#define RIGHT(X) ((X << 1) + 1)
using namespace std;
int h[(MAXN << 1) + 1];

void solve(int n) {
    int x, limit = 2 * n + 1;
    h[1] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        DEBUG() cout << x << " " << LEFT(x) << " " << RIGHT(x) << endl;
        h[LEFT(i)] = h[x] + 1;
        h[RIGHT(i)] = h[x] + 1;
    }
    for(int i = 1; i <= limit; i++) {
        DEBUG() cout << i << " ";
        cout << h[i] << endl;
    }
}

int main() {
    int N;
    while(cin >> N) {
        solve(N);
        DEBUG() cout << "-----------------------" << endl;
    }
    return 0;
}