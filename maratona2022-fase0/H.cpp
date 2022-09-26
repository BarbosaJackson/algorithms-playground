#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main() {
    lli N, i, cards_used, next_level;
    cin >> N;
    while(N--) {
        i = 1;
        cards_used = 2;
        next_level = 5;
        while(cards_used + next_level <= N) {
            i++;
            cards_used = (cards_used + next_level);
            next_level = (next_level + 2);
        }
        cout << i << endl;
    }
    return 0;
}