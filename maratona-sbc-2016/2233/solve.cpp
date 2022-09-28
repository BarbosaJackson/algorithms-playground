#include <bits/stdc++.h>

using namespace std;

int main() {
	long long int r,g,b;
	cin >> hex >> r >> g >> b;
	cout << hex << 1 + (g > r ? 0 : ( (r/g) * (r/g) ) ) + ((g > r ? 0 : ( (r/g) * (r/g) ) ) * (g/b) * (g/b)) << endl;
	return 0;
}