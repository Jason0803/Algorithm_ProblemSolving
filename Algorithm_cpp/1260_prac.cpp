#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int x) {
    check[x] = true;
    printf("%d ", node);
    for(int i = 0; i < a[node].size(); i++) { // 간선 갯수만큼
        int next = a[node][i];
        if(check[next] == false) {
            dfs(next);
        }
    }
}

void bfs(int x) {
    queue<int> q;
    memset(check, false, sizeof(check));
    check[x] = true;
    q.push(x);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ", node);
        for(int i = 0; i < a[node].size(); i++) {
            int next = a[node][i];
            if(check[next] == false) {
                check[next] == true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(start);
    puts("");
    bfs(start);
    puts("");

    return 0;
}