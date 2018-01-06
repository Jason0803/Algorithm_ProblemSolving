#include <cstdio>

int main(int argc, const char * argv[]) {
    int stick = 64;
    int count = 0;
    int input;
    scanf("%d", &input);
    
    while(input > 0) {
        if(input == stick) {
            count++;
            break;
        } else if(input < stick){
            stick /= 2;
        } else {
            input -= stick;
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
