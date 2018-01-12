#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char input[7];
    int n, m, a, s;
    n = 20;
    s = 0;
    scanf("%d", &m);
    while(m--) {
        scanf("%s", input);
        if(!strcmp(input, "all")) {
            s = (1 << n)-1;
        } else if(!strcmp(input, "empty")) {
            s = 0;
        } else {
            scanf("%d", &a);
            a--;
            if(!strcmp(input, "add")) {
                s = (s | (1 << a));
            } else if(!strcmp(input, "remove")) {
                s = (s & ~(1 << a));
            } else if(!strcmp(input, "check")) {
                int temp = ( s & (1 << a));
                if(temp) {
                    puts("1");
                } else puts("0");
            } else if(!strcmp(input, "toggle")) {
                s = (s ^ (1 << a));
            }
        }
    }
    return 0;
}
