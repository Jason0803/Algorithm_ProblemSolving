#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 303
using namespace std;
int n, m, components, ans;
int count_blocks;
int map[MAX][MAX];
int adjs[MAX][MAX];
bool visited[MAX][MAX];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<pair<int, int>> q;
void count_adjs() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] != 0) {
                adjs[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(0 <= nr && nr < n && 0 <= nc && nc < m) {
                if(map[nr][nc] == 0) {
                    adjs[r][c]++;
                }
            }
        }
    }
}
void dfs(int r, int c) {
    for(int k=0; k<4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if(0 <= nr && nr < n && 0 <= nc && nc < m) {
            if(visited[nr][nc] || map[nr][nc] == 0) continue;
            visited[nr][nc] = true;
            dfs(nr,nc);
        }
    }
}
int count_components() {
    int ret = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = false;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j] == false && map[i][j] != 0) {
                visited[i][j] = true;
                dfs(i,j);
                ret++;
            }
        }
    }
    return ret;
}
void melt_down() {
    count_blocks = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] != 0) {
                map[i][j] -= adjs[i][j];
                if(map[i][j] < 0) map[i][j] = 0;
                count_blocks++;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j] != 0)
                count_blocks++;
        }
    }
    
    while(count_blocks != 0) {
        count_adjs();
        components = count_components();
        
        if(components >= 2) {
            cout << ans << '\n';
            break;
        } else {
            melt_down();
            ans++;
        }
    }
    
    if(components < 2) cout << "0\n";
    
    return 0;
}

/*
반례
 
5 5
1 1 0 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
0 1 1 1 0
 
1 0 0 0 1
1 1 0 1 1
1 1 1 1 1
0 1 1 1 1
0 0 1 0 0
 
0 0 0 0 0
1 0 0 0 1
0 1 0 1 1
0 0 1 0 0
0 0 0 0 0
 
--> 2번만에 됨
 
 */
