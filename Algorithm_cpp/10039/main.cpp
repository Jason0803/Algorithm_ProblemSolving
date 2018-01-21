#include <cstdio>
int main(){
    int input, sum;
    sum = 0;
    while(scanf("%d",&input)==1){
        if(input<40) input = 40;
        sum+= input;
    }
    printf("%d\n", sum/5);
}
