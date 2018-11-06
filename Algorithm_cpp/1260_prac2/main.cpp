#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> graph[1001];
bool visited[1001];

void dfs(int node) {
    visited[node] = true;
    printf("%d ", node);
    for(int i=0; i<graph[node].size(); i++) {
        int next  = graph[node][i];
        if(!visited[next])
            dfs(next);
    }
}

void bfs(int start) { 
    queue<int> q;
    memset(visited, false, sizeof(visited));
    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ", node);
        for(int i=0; i<graph[node].size(); i++) {
            int next = graph[node][i];
            if(visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
}
int main() {
    scanf("%d %d %d", &N, &M, &V);
    for(int i=0; i<M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=N; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(V);
    puts("");
    bfs(V);
    puts("");

    return 0;
}