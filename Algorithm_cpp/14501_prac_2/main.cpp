#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> pii[16];
int N, ans;
void dfs(int current, pair<int, int> node, int sum) {
    if(current + node.first >= N+1) return;
    int n_sum = sum + node.second;
    if(ans < n_sum) ans = n_sum;
    for(int i=0; current+node.first+i < N; i++) {
        dfs(current+node.first+i, pii[current+node.first+i], n_sum);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        int u, v;
        cin >> u >> v;
        pii[i] = make_pair(u,v);
    }
    for(int i=0; i<N; i++) {
        dfs(i, pii[i], 0);
    }
    cout << ans << '\n';
    return 0;
}
