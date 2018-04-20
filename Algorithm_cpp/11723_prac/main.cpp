#include <iostream>
#include <string.h>
using namespace std;
int M, S, num;
char cmd[7];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M;
    while(M--) {
        cin >> cmd;
        if(!strcmp(cmd, "all")){
            S = (1<<20)-1;
        } else if(!strcmp(cmd, "empty")) {
            S = 0;
        } else {
            cin >> num;
            num--;
            if(!strcmp(cmd, "check")) {
                if(S & (1<<num)) cout << "1\n";
                else cout << "0\n";
            } else if(!strcmp(cmd, "remove")) {
                S &= ~(1<<num);
            } else if(!strcmp(cmd, "add")) {
                S |= (1<<num);
            } else if(!strcmp(cmd, "toggle")) {
                S ^= (1<<num);
            }
        }
    }
    return 0;
}
