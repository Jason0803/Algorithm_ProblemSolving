#include <iostream>
#include <vector>
using namespace std;
int n,s;
int cnt = 0;
vector<int> arr(20);
void solve(int index, int sum) {
    if(index == n){
        if(sum == s)
            cnt++;
        return;
    }
    solve(index+1, sum+arr[index]);
    solve(index+1, sum);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    solve(0,0);
    if(s == 0) cnt--;
    cout << cnt << '\n';
    return 0;
}
