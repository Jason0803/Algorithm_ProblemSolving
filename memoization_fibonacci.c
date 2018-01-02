#include <stdio.h>
#include <stdlib.h>
long long memo[46];

long long fib(int n) {
	if(n <= 1) {
		return n;
	}
	else {
		if(memo[n] > 0) {
			return memo[n];
		}
		memo[n] = fib(n-1) + fib(n-2);
		return memo[n];
	}	
}

int main() {
	int N;
	scanf("%d", &N);
	if(N >= 1 && N <= 45)
		printf("%lld", fib(N));

	return 0;
} 