#include <iostream>
#include <string>
using namespace std;
int num;
string input;
int main() {
    while(true) {
        cin >> input;
        if(input == "0") return 0;
        num = 0;
        for(int i=0; i<input.size(); i++) {
            num += input.at(i)-'0';
        }
        while(num > 9) {
            int tnum = num;
            num = 0;
            while(tnum){
                num += tnum % 10;
                tnum /= 10;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
