#include <cstdio>
int graph[1001];
bool check[1001];
void dfs(int x) {
    if(check[x]) return;
    check[x] = true;
    dfs(graph[x]);
}
int main() {
    int N, T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) {
            scanf("%d", &graph[i]);
            check[i] = false;
        }
        int count = 0;
        for(int i = 1; i <= N; i++) {
            if(check[i] == false) {
                dfs(i);
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
