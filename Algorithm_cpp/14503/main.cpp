#include <iostream>
#define MAX_SIZE 50
#define EMPTY   0
#define WALL    1
#define CLEANED 2
using namespace std;
int n, m, R, C, D, ans;
int map[MAX_SIZE][MAX_SIZE];
bool blocked;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
void dfs(int r, int c, int d){
    int nr, nc, nd = d;
    
    for(int i=0; i<4; i++){
        nd = (nd+3) % 4;
        nr = r + dr[nd];
        nc = c + dc[nd];
        
        if(nr>n-2 || nr<1 || nc>m-2 || nc<1 || map[nr][nc]==1) continue;
        if(map[nr][nc] == EMPTY){
            ans++;
            map[nr][nc] = CLEANED;
            dfs(nr,nc,nd);
            return;
        }
    }
    
    nd = (d+2) % 4;
    nr = r + dr[nd];
    nc = c + dc[nd];
    
    if(map[nr][nc] == 1) return;
    else dfs(nr,nc,d);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    cin >> n >> m;
    cin >> R >> C >> D;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    ans = 1;
    map[R][C] = CLEANED;
    dfs(R,C,D);
    cout << ans << '\n';
    return 0;
}
