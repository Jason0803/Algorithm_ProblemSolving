#include <iostream>
#include <string.h>
#include <vector>
#define MAX_SIZE 401
using namespace std;
int n, k, s;
bool found;
vector<int> rel[MAX_SIZE];
bool visited[MAX_SIZE];
void dfs(int current, int dest) {
    if(current == dest) {
        found = true;
        memset(visited, false, sizeof(visited));
        return;
    }
    for(int i=0; i<rel[current].size(); i++) {
        int next = rel[current][i];
        if(visited[next]) continue;
        visited[next] = true;
        dfs(next, dest);
    }
    memset(visited, false, sizeof(visited));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> n >> k;

    int u, v;
    for(int i=0; i<k; i++) {
        cin >> u >> v;
        rel[u].push_back(v);
    }
    cin >> s;
    for(int i=0; i<s; i++) {
        found = false;
        cin >> u >> v;
        dfs(u, v);
        if(found) cout << "-1\n";
        else {
            dfs(v,u);
            if(found) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}
