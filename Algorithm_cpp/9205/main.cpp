#include <cstdio>
#include <algorithm>
#define MAX_SIZE 105
using namespace std;
typedef struct _Point {
    int x, y;
} Point;
Point home, festival;
int T, N;
int dist[MAX_SIZE];
int abs(int input) {
    return input < 0 ? -input : input;
}
int main(int argc, const char * argv[]) {
    scanf("%d", &T);
    while(T--) {
        bool satisfied = true;
        scanf("%d", &N);
        scanf("%d %d", &home.x, &home.y);
        for(int i=0; i<N; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            dist[i] = abs(x-home.x) + abs(y-home.y);
        }
        scanf("%d %d", &festival.x, &festival.y);
        
        if(abs(festival.x - home.x) + abs(festival.y - home.y) > 1000) {
            sort(dist, dist+N);
            
        }
        
        // print
        if(satisfied) printf("happy\n");
        else printf("sad\n");
    }
    return 0;
}
