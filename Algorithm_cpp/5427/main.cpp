#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 1004
#define INF 987654321
#define EMPTY '.'
#define WALL '#'
#define CURRENT_POSITION '@'
#define FIRE '*'
using namespace std;
struct Point{
    int r, c;
} current_pos, destination;
int t, n, m, ans;
char map[MAX][MAX];
int walk[MAX][MAX];
int flame[MAX][MAX];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<pair<int, int>> q;
queue<pair<int, int>> dest;
bool isNotSafe(int r, int c) {
    return (r < 0 || r >= n || c < 0 || c >= m);
}
void flmae_throw() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            // flood[][] == 1 : 물이 찰 곳,
            // flood[][] == 0 : 현재 물이 찬 곳
            // flood[][] == -1 : default
            if ( map[i][j] == FIRE ) flame[i][j] = 0;
            if ( map[i][j] == EMPTY ) {
                bool flamed = false;
                for(int k=0; k<4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(isNotSafe(nr,nc)) continue;
                    if(map[nr][nc] == FIRE) flamed = true;
                }
                if(flamed) {
                    q.push(make_pair(i,j));
                    flame[i][j] = 1;
                }
            }
            
        }
    }
}
void find_route() {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(isNotSafe(nr,nc)) continue;
            if(flame[nr][nc] == -1 && map[nr][nc] != WALL) {
                flame[nr][nc] = flame[r][c] + 1;
                q.push(make_pair(nr,nc));
            }
        }
    }
    walk[current_pos.r][current_pos.c] = 0;
    q.push(make_pair(current_pos.r, current_pos.c));
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(isNotSafe(nr,nc)) continue;
            if(walk[nr][nc] == -1 && map[nr][nc] != WALL) {
                if(flame[nr][nc] > walk[r][c] + 1 || flame[nr][nc] == -1) {
                    walk[nr][nc] = walk[r][c] + 1;
                    q.push(make_pair(nr,nc));
                }
            }
        }
    }
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie();
    cin >> t;
    while(t--) {
        cin >> m >> n;
        ans = INF;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                walk[i][j] = -1;
                flame[i][j] = -1;
                cin >> map[i][j];
                if(map[i][j] == CURRENT_POSITION) {
                    current_pos.r = i;
                    current_pos.c = j;
                    map[i][j] = EMPTY;
                } else if(map[i][j] == EMPTY) {
                    if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                        //printf("\nFOUND DEST CANDIDATE :: (%d, %d)\n", i, j);
                        dest.push(make_pair(i,j));
                    }
                }
            }
        }
        if(current_pos.r == 0 || current_pos.r == n-1 || current_pos.c == 0 || current_pos.c == m-1) {
            ans = 0;
        } else {
            flmae_throw();
            find_route();
            
            while(!dest.empty()) {
                //printf("QUEUE START !!!\n");
                int r = dest.front().first;
                int c = dest.front().second;
                dest.pop();
                if(walk[r][c] != -1) {
                    //printf("Current value : (%d, %d) = %d\n", r, c, walk[r][c]);
                    if(ans > walk[r][c])
                        ans = walk[r][c];
                }
            }
        }
        
        if(ans != INF) cout << ans+1 << '\n';
        else cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}
