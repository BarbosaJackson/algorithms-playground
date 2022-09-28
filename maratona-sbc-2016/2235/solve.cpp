#include <iostream>
 
using namespace std;
 
int main() {
 
    int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF)
		printf("%c\n", (a == b || a == c || a == (b+c) || b == (a+c) || c == (a + b) || b == c) ? 'S' : 'N');
 
    return 0;
}