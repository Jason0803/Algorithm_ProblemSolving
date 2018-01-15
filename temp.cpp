#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	char *arr[3] = {“a”,”b”,”c”};
	for(int i=0; i<3; i++) {
		if(strcmp(arr[i], "b")) {
			printf("%s, ", arr[i]);
		}
	}
}