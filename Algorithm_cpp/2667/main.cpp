#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
int a[30][30];
int visited[30][30];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int n;
int answer[25*25];

void bfs(int r, int c, int count) {
    queue<pair<int, int>> queue;
    queue.push(make_pair(r, c));
    visited[r][c] = count;
    while(!queue.empty()) {
        r = queue.front().first;
        c = queue.front().second;
        queue.pop();
        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(a[nr][nc] == 1 && visited[nr][nc] == 0) {
                    queue.push(make_pair(nr, nc));
                    visited[nr][nc] = count;
                }
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(a[i][j] == 1 && visited[i][j] == 0){
                bfs(i, j, ++count);
            }
        }
    }
    printf("%d\n", count);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            answer[visited[i][j]]++;
        }
    }
    sort(answer+1, answer+count+1);
    for(int i = 1; i <= count; i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}
