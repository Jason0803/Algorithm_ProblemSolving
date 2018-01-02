#include <stdio.h>

int count[2];

int fib(int n) {
	if(n <= 1) {
		count[n]++;
		return n;
	}
	else return fib(n-2) + fib(n-1);
}

int main() {
	int T,N;
	scanf("%d", &T);

	while(T >0) {
		scanf("%d", &N);
		fib(N);
		printf("%d %d\n", count[0], count[1]);
		count[0] = 0;
		count[1] = 0;
		T--;
	}
	return 0;
} 