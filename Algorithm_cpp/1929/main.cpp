#include <cstdio>
#define MAX 1000000
bool prime[MAX+1];
int main(){
    int a, b, c;
    scanf("%d %d", &a,&b);
    prime[0] = true;
    prime[1] = true;
    for(int i=2; i*i<=b; i++) {
        if(!prime[i]) {
            for(int j=i*i; j <= b; j+=i){
                prime[j] = true;
            }
        }
    }
    for(int i=a; i<=b; i++) {
        if(!prime[i]) printf("%d\n", i);
    }
    return 0;
}
