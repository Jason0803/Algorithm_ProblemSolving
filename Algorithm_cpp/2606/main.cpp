#include <cstdio>
#include <vector>
using namespace std;
vector<int> graph[101];
bool check[101];
int n, m;
void dfs(int x, int &count) {
    check[x] = true;
    for(int i=0; i < graph[x].size(); i++) {
        int next = graph[x][i];
        if(check[next] == false) {
            check[next] = true;
            count++;
            dfs(next, count);
        }
    }
}
int main () {
    scanf("%d", &n);
    scanf("%d", &m);
    
    while(m--){
        int u,v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int count = 0;
    dfs(1, count);
    printf("%d\n", count);
    return 0;
}
