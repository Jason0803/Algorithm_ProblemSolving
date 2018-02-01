#include <iostream>
using namespace std;
int coins[10];
int n, k, ans;
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> coins[i];
    
    for(int i=n-1; i>=0; i--) {
        if(coins[i] <= k) {
            ans += k / coins[i];
            k %= coins[i];
        }
    }
    
    cout << ans << '\n';
    return 0;
}
