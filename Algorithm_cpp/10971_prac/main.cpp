#include <iostream>
#define MAX_SIZE 11
#define INF 987654321
using namespace std;
int N, ans;
int map[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE];
void tsp(int start, int current, int sum, int count) {
    if(start == current && count == N) {
        if(ans > sum) ans = sum;
        return;
    }
    for(int next=1; next<=N; next++) {
        if(map[current][next] == 0) continue;
        if(check[next] == false) {
            check[next] = true;
            sum += map[current][next];
            if(sum <= ans)
                tsp(start, next, sum, count+1);
            check[next] = false;
            sum -= map[current][next];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
        }
    }
    ans = INF;
    for(int start = 1; start <= N; start++) {
        tsp(start, start, 0, 0);
    }
    cout << ans << '\n';
    return 0;
}
