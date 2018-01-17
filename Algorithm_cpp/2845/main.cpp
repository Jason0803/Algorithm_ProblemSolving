#include <cstdio>
int main(){
    int l,p, input;
    scanf("%d %d", &l, &p);
    for(int i=0; i<5; i++){
        scanf("%d", &input);
        printf("%d ", input - l*p);
    }
    return 0;
}
