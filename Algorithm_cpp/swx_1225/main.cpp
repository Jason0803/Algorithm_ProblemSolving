#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int T, input, temp, i, j;
    queue<int> queue;
    for(int test_case = 1; test_case <= 10; test_case++) {
        scanf("%d", &T);
        for(int i = 0; i < 8; i++) {
            scanf("%d", &input);
            queue.push(input);
        }
        i = 0; j = 5;
        while(true) {
            i = (j%5) + 1;
            temp = queue.front();
            queue.pop();
            temp -= i;
            queue.push(temp);
            j++;
            if(queue.back() <= 0){
                queue.back() = 0;
                break;
            }
        }
        printf("#%d ", test_case);
        for(int i = 0; i < 8; i++) {
            printf("%d ", queue.front());
            queue.pop();
        }
        puts("");
    }
    return 0;
}
