#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
int box[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> q;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void input() {
    scanf("%d %d", &M, &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &box[i][j]);
            dist[i][j] = -1;
            if(box[i][j] == 1) {
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
}
void bfs() {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(0 <= nr && nr < N && 0 <= nc && nc < M) {
                if(box[nr][nc] == 0 && dist[nr][nc] == -1) {
                    q.push(make_pair(nr, nc));
                    dist[nr][nc] = dist[r][c] + 1;
                }
            }
        }
    }
}
int main() {
    int ans = 0;
    input();
    bfs();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(ans < dist[i][j])
                ans = dist[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0 && dist[i][j] == -1) {
                ans = -1;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
