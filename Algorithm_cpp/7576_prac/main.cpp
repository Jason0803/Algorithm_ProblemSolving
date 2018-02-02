#include <iostream>
#include <queue>
using namespace std;
int n, m, ans;
int map[1000][1000];
int d[1000][1000];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<pair<int, int>> q;
void bfs() {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(0 <= nr && nr < n && 0 <= nc && nc < m) {
                if(map[nr][nc] == 0 && d[nr][nc] == -1) {
                    d[nr][nc] = d[r][c] + 1;
                    q.push(make_pair(nr,nc));
                }
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> m >> n;
    /*
     map[i][j] --> 익었다면 1 / 익지 않았다면 0
     d[][] --> 익었다면 0 (기본 거리) / 익지 않았다면 -1 (익을 수 없을 수 있음) 저장해둠
           ---> 추후 d[i][j] 번째가 익기까지 걸린 시간 저장함
     */
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                d[i][j] = 0;
                q.push(make_pair(i,j));
            } else  d[i][j] = -1;
        }
    }
    bfs();
    for(int i=0; i<n;i++) {
        for(int j=0; j<m; j++) {
            ans = ans < d[i][j] ? d[i][j] : ans;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 0 && d[i][j] == -1) {
                ans = -1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
