#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<int> graph[1001];
bool check[1001];

void dfs(int start) {
    check[start] = true;
    printf("%d ", start);
    for(int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if(check[next] == false) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    memset(check, false, sizeof(check));
    check[start] = true;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ", node);
        for(int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if(check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}
int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(V);
    puts("");
    bfs(V);
    puts("");
    return 0;
}
