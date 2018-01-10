#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
int N, M;
int graph[100][100];
bool visited[100][100];
int dist[100][100];
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

void bfs(){
    int r,c;
    queue<pair<int, int>> queue;
    queue.push(make_pair(0,0));
    visited[0][0] = true;
    dist[0][0] = 1;
    while(!queue.empty()) {
        r = queue.front().first;
        c = queue.front().second;
        queue.pop();
        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(0 <= nr && nr < N && 0 <= nc && nc < M) {
                if(graph[nr][nc] == 1 && visited[nr][nc] == false) {
                    queue.push(make_pair(nr, nc));
                    visited[nr][nc] = true;
                    dist[nr][nc] = dist[r][c] + 1;
                }
            }
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
    bfs();
    printf("%d", dist[N-1][M-1]);
    return 0;
}
