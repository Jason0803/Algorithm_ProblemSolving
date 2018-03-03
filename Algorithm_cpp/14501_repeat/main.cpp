#include <iostream>
#include <algorithm>
#define MAX_DAYS 15
using namespace std;
int n, ans;
pair<int, int> schedule[MAX_DAYS];

void dfs(int date, pair<int, int> next, int current_sum) {
    if(date + next.first >= n+1) return;
    int sum = next.second + current_sum;
    ans = ans > sum ? ans : sum;
    int next_date = date + next.first;
    for(int i=0; next_date+i < n; i++) {
        dfs(next_date+i, schedule[next_date+i], sum);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> schedule[i].first >> schedule[i].second;
    }
    
    for(int i=0; i<n; i++) {
        dfs(i, schedule[i], 0);
    }

    cout << ans << '\n';
    return 0;
}
