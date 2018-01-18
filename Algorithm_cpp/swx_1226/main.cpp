#include <cstdio>
#include <algorithm>
using namespace std;
int map[16][16];
bool check[16][16];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int result;
void dfs(int r, int c) {
    for(int k=0; k<4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        
        if(0 > nr || nr >= 16 || 0 > nc || nc >= 16) continue;
        if(map[nr][nc] == 1) continue;
        if(map[nr][nc] == 3) result = 1;
        
        if(map[nr][nc] == 0 && check[nr][nc] == false) {
            check[nr][nc] = true;
            dfs(nr, nc);
        }
    }
}
int main() {
    int t;
    pair<int, int> start;
    for(int test_case=1; test_case<=10; test_case++) {
        scanf("%d", &t);
        result = 0;
        for(int i=0; i<16; i++){
            for(int j=0; j<16; j++){
                scanf("%1d", &map[i][j]);
                check[i][j] = false;
                if(map[i][j] == 2)
                    start = make_pair(i, j);
            }
        }
        dfs(start.first, start.second);
        printf("#%d %d\n", t, result);
    }
    return 0;
}
