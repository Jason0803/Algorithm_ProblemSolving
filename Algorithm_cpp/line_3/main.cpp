#include <iostream>
#include <vector>
using namespace std;
int N, ans;
vector<int> a[100001];
bool visited[100001];
void dfs(int current) {
    visited[current] = true;
    for(int i=0; i<a[current].size(); i++) {
        int next = a[current][i];
        if(!visited[next]) dfs(next);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while(N--) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int group = 0;
    for(int i=1; i<=100000; i++){
        if(!visited[i] && a[i].size() != 0) {
            dfs(i);
            group++;
        }
    }
    
    cout << group << '\n';
    return 0;
}
