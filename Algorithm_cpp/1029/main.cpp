#include <cstdio>
int N, net[16][16], ans;
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%1d", &net[i][j]);
        }
    }
    return 0;
}
