#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, u, v, cnt;
vector<int> net[101];
bool visit[101];
int dist[101][101];
int cavin[101];
queue<int> q;
// int net[101][101];

void bfs(int start) {
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        printf("node : %d\n", node);
        for(int i=0; i<net[node].size(); i++) {
            int next = net[node][i];
            dist[node][next] = dist[next][node] = 1;
            if(visit[next] == false) {
                visit[next] = true;
                printf("-next : %d\n", next);
                dist[start][next] = dist[next][start] = dist[start][node] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie();
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        net[u].push_back(v);
        net[v].push_back(u);
        
        dist[u][v] = dist[v][u] = 1;
    }

    for(int i=1; i<=n; i++) {
        visit[i] = true;
        q.push(i);
        printf("[start : %d]\n", i);
        bfs(i);
        for(int j=1; j<=n; j++) {
            cavin[i] += dist[i][j];
        }
        puts("");
        
        // init.
        for(int j=1; j<=n; j++) {
            visit[j] = false;
            
            for(int k=0; k<net[j].size(); k++) {
                int temp_next = net[j][k];
                printf("[INITIALISE] :: %d <-> %d\n", j, temp_next);
                dist[j][temp_next] = 1;
            }
        }
    }

    // to pirnt
    for(int i=1; i<=n; i++) {
        cout << "i : " << cavin[i] << '\n';
    }
    int* min_value = min_element(cavin+1, cavin+n);
    int min_pos = 1;
    for(int i=1; i<=n; i++) {
        if(cavin[i] == *min_value){
            min_pos = i;
            break;
        }
    }
    cout << min_pos << '\n';
    return 0;
}
