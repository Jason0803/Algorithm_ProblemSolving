#include <iostream>
#include <algorithm>
using namespace std;
int N, num[11], Plus, Minus, Mult, Mod;
int Min = 1000000001, Max = -1000000001;
void solve(int idx, int sum, int plus, int minus, int mul, int mod) {
    if(idx == N) {
        Min = min(Min, sum);
        Max = max(Max, sum);
        return;
    }
    if(plus) solve(idx+1, sum+num[idx], plus-1, minus, mul, mod);
    if(minus) solve(idx+1, sum-num[idx], plus, minus-1, mul, mod);
    if(mul) solve(idx+1, sum*num[idx], plus, minus, mul-1, mod);
    if(mod) solve(idx+1, sum/num[idx], plus, minus, mul, mod-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) cin >> num[i];
    cin >> Plus >> Minus >> Mult >> Mod;
    solve(1, num[0], Plus, Minus, Mult, Mod);
    cout << Max << '\n' << Min << '\n';
    return 0;
}
