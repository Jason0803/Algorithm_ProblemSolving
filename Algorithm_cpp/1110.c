#include <stdio.h>
#include <string.h>
int main()
{
    char temp[2];
    char num[2];
    char re[2];
    int cycle=0,i;

    scanf("%s",num);
    
    if(strlen(num)==1){
        num[1]=num[0];
        num[0]='0';
    }
    temp[0] = num[0];
    temp[1] = num[1];
    for(i=0;;i++) {
        re[1] = num[0] + num[1] - '0';
        if(re[1] > '9') {
            re[1] = re[1] -10;
        }

        re[0] = num[1];

        num[0] = re[0];
        num[1] = re[1];
        cycle++;
        if( num[0] == temp[0] && num[1] == temp[1]){
            break;
        }
    }
    printf("%d\n",cycle);
    return 0;
}