#include <iostream>
using namespace std;
int coins[10];
int n, k, ans, cnt;
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> coins[i];
    
    while(k > 0) {
        for(int i=n-1; i>=0; i--) {
            if(coins[i] <= k) {
                cnt = k / coins[i]; 
                k -= cnt * coins[i];
                ans+=cnt;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
