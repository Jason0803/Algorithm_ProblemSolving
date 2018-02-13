#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX 1010
#define INF 987654321
using namespace std;
struct Point {
    int r, c, passed;
};
int n, m;
int result = 100000;
int map[MAX][MAX];
int dist[MAX][MAX][2];
int dr[] = {0 ,0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<Point> q;

void bfs() {
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int passed = q.front().passed;
        q.pop();
        for(int k=0; k<4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr < 0 || nr > n || nc < 0 || nc > m) continue;
            
            // 다음곳 방문 여부
            if(dist[nr][nc][passed] > dist[r][c][passed]+1) {
                // 벽이고, 아직 벽을 부수지 않았다면
                if(map[nr][nc] == 1 && passed == 0) {
                    dist[nr][nc][1] = dist[r][c][0] + 1;
                    q.push(Point{nr,nc,1});
                } else if(map[nr][nc] == 0) {
                    q.push(Point{nr,nc,passed});
                    dist[nr][nc][passed] = dist[r][c][passed] +1;
                }
            }
        }
    }
    
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            scanf("%1d", &map[i][j]);
            dist[i][j][0] = dist[i][j][1] = INF;
        }
    }
    q.push(Point{0,0,0});
    dist[0][0][0] = dist[0][0][1] = 1;
    bfs();
  
    result = dist[n-1][m-1][0];
    if(result > dist[n-1][m-1][1]) result = dist[n-1][m-1][1];
    if(result == INF) printf("-1\n");
    else printf("%d\n", result);

    return 0;
}
