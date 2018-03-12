#include <iostream>
#include <algorithm>
#define MAX_SIZE    1001
using namespace std;
int N, M, X, ret;
int dist[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE]; // required ?
int cost[MAX_SIZE];
void dfs(int dept, int dest, int current, int current_sum) {
    if(current == dest) {
        if(dist[dept][dest] == 0 || dist[dept][dest] > current_sum)
            dist[dept][dest] = current_sum;
        printf(" >>> FOUND !\n");
        return;
    }
    for(int next=1; next<=N; next++) {
        if(current == next) continue;
        if(dist[current][next] == 0 || visited[current][next]) continue;
        if(dist[dept][dest] != 0 && current_sum + dist[current][next] > dist[dept][dest]) continue;
        if(dist[dept][dest] != 0 && dist[next][dest] >= dist[dept][dest]) continue;
        visited[current][next] = true;
        printf(" > Current : %d\n", current);
        printf(" >> Next : %d, current_sum : %d\n", next, current_sum + dist[current][next] );
        dfs(dept, dest, next, current_sum + dist[current][next]);
        for(int i=1; i<= N; i++) {
            visited[current][i] = false;
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> N >> M >> X;
    int u, v, t;
    for(int i=0; i<M; i++) {
        cin >> u >> v >> t;
        dist[u][v] = t;
    }
    for(int i=1; i<=N; i++) {
        if(i == X) {
            cost[i] = 0;
            continue;
        }
        
        printf("Start : %d\n", i);

        dfs(i,X,i,0);
        
        printf("For reverse : %d\n", i);

        dfs(X,i,X,0);
        cost[i] = dist[i][X] + dist[X][i];
        printf("Cost[%d] = %d\n", i, cost[i]);
    }
    cout << *max_element(cost, cost+MAX_SIZE) << '\n';
    return 0;
}
