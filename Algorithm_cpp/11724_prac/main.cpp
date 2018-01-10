#include <cstdio>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool check[1001];

void dfs(int start) {
    check[start] = true;
    for(int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
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
    printf("%d\n", component);
}
