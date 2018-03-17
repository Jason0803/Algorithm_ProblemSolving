#include <iostream>
#define HOME    '1'
#define EMPTY   '0'
#define MAX_SIZE 24
using namespace std;
int T, N, M, houses, ret;
char map[MAX_SIZE][MAX_SIZE];

void input() {
    cin >> N >> M;
    houses = 0;
    ret = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            houses += map[i][j] == HOME ? 1 : 0;
        }
    }
}
int count_available(int r, int c, int k) {
    int cnt = 0;
    
    if(k == 1) cnt += map[r][c] == HOME ? 1 : 0;

    else {
        int w = 0;
        for(int i = r-k+1; i <= r; i++) {
            for(int j = c-w; j <= c+w; j++) {
                if(i < 0 || i >= N || j < 0 || j>= N) continue;
                cnt += map[i][j] == HOME ? 1 : 0;
            }
            w++;
        }
        w = k-2;
        for(int i = r+1; i < r+k; i++) {
            for(int j = c-w; j <= c+w; j++) {
                if(i < 0 || i >= N || i < 0 || i >= N) continue;
                cnt += map[i][j] == HOME ? 1 : 0;
            }
            w--;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        input();
        int max_k = 1;
        while( M * houses >= (max_k * max_k) + (max_k-1) * (max_k-1)) max_k++;
        int served = 0;
        for(int k=max_k-1; k>0; k--) {
            int max_servve = 0;
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    served = count_available(i, j, k);
                    max_servve = max_servve < served ? served : max_servve;
                }
            }
            if(M * max_servve >= (k*k + (k-1)*(k-1) )) {
                ret = max_servve;
                break;
            }
        }
        cout << "#" << test_case << " " << ret << '\n';
    }
    return 0;
}
