#include <iostream>
#include <algorithm>
using namespace std;
int N, ans;
pair<int, int> days[16];
void dfs(int current, pair<int, int> node, int current_sum) {
    if(current + node.first > N+1) return;
    
    current_sum += node.second;
    if(ans < current_sum) ans = current_sum;
    for(int next = current + node.first; next <= N; next++) {
        dfs(next, days[next], current_sum);
    }
    current_sum -= node.second;
    
}
int main() {
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> days[i].first >> days[i].second;
    
    for(int start=1; start<=N; start++)
        dfs(start, days[start], 0);
    
    cout << ans << '\n';
    return 0;
}
