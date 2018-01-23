#include <iostream>
#define MAX 15
using namespace std;

int n;
int result;
bool map[MAX];
bool d1[2*MAX-1];
bool d2[2*MAX-1];

void solve(int row){ 
    if(row >= n) result++;
    for(int i=0; i<n; i++) {
        if(arr[i]) continue;
        if(d1[row+1] || d2[n-1 + (row-1)]) continue;
        arr[i] = d1[y+1] = d2[n-1+(row-1)] = true;
        solve(row+1);
        arr[i] = d1[y+1] = d2[n-1+(row-1)] = false;
    }
}

int main() {
    cin >> n;
    solve(0);
    cout << result << '\n';
    return 0;
}