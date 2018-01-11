#include <stdio.h>
#include <stdlib.h>

int d[1000001];

int makeOne(int n) {
	if(n == 1) return 0;
	if(d[n] > 0) return d[n];

	d[n] = makeOne(n-1) + 1;

	if(n%2 == 0) {
		int temp = makeOne(n/2) + 1;
		if(d[n] > temp) d[n] = temp;
	}
	if(n%3 == 0) {
		int temp = makeOne(n/3) + 1;
		if(d[n] > temp) d[n] = temp;
	} 
	return d[n];
}

int main () {
	int N;
	scanf("%d", &N);
	if(N >= 1 && N <= 1000000)
		printf("%d", makeOne(N));
	
	return 0;
}