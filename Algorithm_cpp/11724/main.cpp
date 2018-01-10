#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool check[1001];

void dfs(int node) {
    check[node] = true;
    for(int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if(check[next] == false) {
            check[next] = true;
            dfs(next);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int component = 0;
    
    for(int i = 1; i <= N; i++) {
        if(check[i] == false) {
            dfs(i);
            component++;
        }
    }
    printf("%d", component);
    return 0;
}
