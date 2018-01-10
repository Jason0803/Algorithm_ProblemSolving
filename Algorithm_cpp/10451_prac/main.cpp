#include <cstdio>

using namespace std;

int graph[1001];
bool check[1001];

void dfs(int node) {
    if(check[node]) return;
    check[node] = true;
    dfs(graph[node]);
}

int main() {
    int T, N;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) {
            scanf("%d", &graph[i]);
            check[i] = false;
        }
        int cycle = 0;
        for(int i = 1; i <= N; i++) {
            if(check[i] == false){
                dfs(i);
                cycle++;
            }
        }
        printf("%d\n", cycle);
    }
    return 0;
}
