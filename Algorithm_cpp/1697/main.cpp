#include <cstdio>
#include <queue>
#define MAX 200002
using namespace std;
bool check[MAX+1];
int dist[MAX+1];
void bfs(int n) {
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        if(node-1 >= 0 && check[node-1] == false){
            check[node-1] = true;
            q.push(node-1);
            dist[node-1] = dist[node] + 1;
        }
        if(node + 1 < MAX && check[node+1] == false){
            check[node+1] = true;
            q.push(node+1);
            dist[node+1] = dist[node] + 1;
        }
        if(node*2 < MAX && check[node*2] == false){
            check[node*2] = true;
            q.push(node*2);
            dist[node*2] = dist[node] + 1;
        }
    }
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    dist[n] = 0;
    check[n] = true;
    bfs(n);
    printf("%d\n", dist[k]);
}
