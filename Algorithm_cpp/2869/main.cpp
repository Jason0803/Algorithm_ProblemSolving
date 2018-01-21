#include <cstdio>
int main(){
     int a,b,v;
    scanf("%d %d %d", &a, &b, &v);
    printf("%d\n",(v-a)%(a-b)?(v-a)/(a-b)+2:(v-a)/(a-b)+1);
    return 0;
}
