#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, m, x, y, a, b;
vector<int> net[101];
queue<int> q;
int dist[101];
bool check[101];
void bfs() {
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i=0; i<net[node].size(); i++) {
            int next = net[node][i];
            if(next == y) {
                dist[next] = dist[node] + 1;
                break;
            }
            if(check[next] == false) {
                check[next] = true;
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    scanf("%d", &m);

    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        net[a].push_back(b);
        net[b].push_back(a);
    }
    q.push(x);
    check[x] = true;
    bfs();
    if(dist[y] == 0) printf("-1\n");
    else printf("%d\n", dist[y]);
    return 0;
}
