#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;
int n, m, u, v, count;
vector<int> a[MAX];
bool visited[MAX];
int counts[MAX];
void dfs(int index){
    for(int i=0; i<a[index].size(); i++) {
        int next = a[index][i];
        if(visited[next] == false) {
            visited[next] = true;
            dfs(next);
        }
    }
}
int main() {
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v;
        a[v].push_back(u);
    }
    for(int i=0; i<n; i++){
        count = 0;
        visited[i] = true;
        dfs(a, i);
        
    }
    return 0;
}
