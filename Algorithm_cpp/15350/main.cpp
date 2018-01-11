#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string gene;
string T[10001];
void Comb(int n, int r){
    if(r == 0){
        return;
    }else if(n<r){
        return;
    }
    else {  //loop이 아님
        max(Comb(n-1, r-1), Comb(n-1,r));
        //Comb(n-1, r-1);  //n-1Cr-1: 현재 아이템을 선택한 경우
        //Comb(n-1, r);    //n-1Cr: 현재 아이템을 선택하지 않은 경우
    }
}
void mutate(int n, int a, int b) {
    int count = 0;
    string temp = gene.substr(a-1, b-1);
    do {
        for(int i = a-1; i <= b-1; i++) {
            count++;
            //strstr(gene, temp+a);
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    getline(cin, gene);
    while(true) {
        char a, b;
        scanf("%c %c", &a, &b);
        if(a == '0' && b == '0') break;
        
    }
    return 0;
}
