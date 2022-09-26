#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int N,L,D;
    while(cin >> N >> L >> D) {
        long long int consume = (N * D);
        long long int it = consume / (L * 1000);
        if(consume % (L * 1000)) it++;
        cout << (it * L) << endl;
        
    }
    return 0;
}