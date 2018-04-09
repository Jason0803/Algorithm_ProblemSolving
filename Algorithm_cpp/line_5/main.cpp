#include <iostream>
#include <vector>
using namespace std;
typedef struct _Job {
    int sd, day;
    int pay;
} Job;
vector<Job> v;
int N, M, D, I, ans;
void dfs(int current, Job node, int current_sum) {
    if(current+node.day > 200) return;
    int sum = current_sum + node.pay;
    if(ans < sum) ans = sum;
    int next = current + node.day;
    for(int i=0; i<v.size(); i++) {
        if(v[i].sd > next) {
            dfs(next, v[i], sum);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int tc = 1; tc <= N; tc++) {
        cin >> M >> D >> I;
        v.push_back(Job{M,M,I});
    }
    for(int i=0; i<N; i++) {
        dfs(0, v[i], 0);
    }
    return 0;
}
