#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int graph[26][26];
int visited[26][26];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void bfs(int r, int c, int count) {
    queue<pair<int,int>> q;
    q.push(make_pair(r, c));
    visited[r][c] = count;
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(graph[nr][nc] == 1 && visited[nr][nc] == 0){
                    visited[nr][nc] = count;
                    q.push(make_pair(nr, nc));
                }
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%1d", &graph[i][j]);
        
    int count = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(graph[i][j] == 1 && visited[i][j] == 0)
                bfs(i,j,++count);
        }

    printf("%d\n", count);
    
    int *answer = new int[n*n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            answer[visited[i][j]]++;
    
    sort(answer+1, answer+count+1);
    for(int i=1; i<=count; i++)
        printf("%d\n", answer[i]);
    
    return 0;
}
