#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
int a[10];
char c[11];
int main() {
    scanf("%s", c);
    for(int i=0; i<strlen(c); i++)
        a[i] = c[i] - '0';
    
    sort(a, a+strlen(c), greater<>());
    
    for(int i=0; i<strlen(c); i++)
        printf("%d",a[i]);
    return 0;
}
