#include <cstdio>
#include <algorithm>
#define MAX_DAYS 15
using namespace std;
int n, m;
pair<int, int> days[MAX_DAYS];
void dfs(int current, pair<int,int> node, int current_sum) {
    if(current + node.first >= n+1) return;
    int sum = node.second + current_sum;
    m = sum > m ? sum : m;
    int next = current + node.first;
    for(int i=0; next+i < n; i++) {
        pair<int, int> next_node = days[next+i];
        dfs(next+i, next_node, sum);
    }
}

int main() {
    int a, b;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        days[i] = make_pair(a,b);
    }
    m = 0;
    for(int i=0; i<n; i++){
        dfs(i,days[i], 0);
    }
    printf("%d\n", m);
    return 0;
}
