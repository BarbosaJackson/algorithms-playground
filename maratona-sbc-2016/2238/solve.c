#include <stdio.h>
#include <math.h>

int main(){
    long long int x, A, B, C, D, ans = -1;
	scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
	x = A;
	int sqrt_c = sqrt(C);
	for (int i = 0; i <= sqrt_c; i += 1) {
		if ((x % B) && !(C % x) && (D % x)) {
			ans = x;
	        break;
		}
		x += A;
	}
    printf("%lld\n", ans);
	return 0;
}