#include <iostream>
#define MAX 16
using namespace std;
int n;
int result;
bool arr[MAX];
bool d1[2*MAX-1];
bool d2[2*MAX-1];
void solve(int row){
    if(row >= n) result++;
    for(int i=0; i<n; i++) {
        if(arr[i]) continue;
        if(d1[row+i] || d2[n-1 + (row-i)]) continue;
        arr[i] = d1[row+i] = d2[n-1+(row-i)] = true;
        solve(row+1);
        arr[i] = d1[row+i] = d2[n-1+(row-i)] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    solve(0);
    cout << result << '\n';
    return 0;
}
