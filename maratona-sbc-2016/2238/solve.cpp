#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int x, A, B, C, D, ans = -1;
	cin >> A >> B >> C >> D; x = A;
	int sqrt_c = sqrt(C);
	for (int i = 0; i <= sqrt_c; i += 1) {
		if ((x % B) and !(C % x) and (D % x)) {
			ans = x;
	        break;
		}
		x += A;
	}

	cout << ans << endl;
	return 0;
}