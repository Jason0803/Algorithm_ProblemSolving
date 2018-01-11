#include <stdio.h>
int coex(int a, int b) {
	if(b == 0) return 1;
	if(b%2 == 0) {
		return coex(a, b/2) * coex(a, b/2);
	} else {
		return a * coex(a, b-1);
	}

}
int main() {
	int T, a, b, result;
	for(int i = 1; i <= 10; i++) {
		scanf("%d %d %d", &T, &a, &b);
		result = coex(a,b);
		printf("#%d %d\n", i, result);
	}
	return 0;
}