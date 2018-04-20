#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {int r; int c;};
int N, M, ans, map[50][50], mat[14][101];
bool check[14];
vector<Point> p, ch;

void dfs(int idx, int depth) {
    if(idx >= ch.size()) return;
    if(depth == M) {
        int sum=0;
        for(int i=0; i<p.size(); i++) {
            int temp = 987654321;
            for(int j=0; j<ch.size(); j++) {
                
                if(!mat[j][i]) {
                    mat[j][i] = abs(p[i].r-ch[j].r)+abs(p[i].c-ch[j].c);
                }
                if(temp>mat[j][i]) temp = mat[j][i];
            }
            sum+=temp;
        }
        if(ans>sum) ans=sum;
        return;
    }
    
    // 1.
    check[idx] = true;
    dfs(idx+1, depth+1);
    check[idx] = false;
    
    // 2.
    dfs(idx+1, depth);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j]==1) p.push_back({i,j});
            else if(map[i][j]==2) ch.push_back({i,j});
        }
    }
    ans = 987654321;
    for(int i=0; i<ch.size(); i++) {
        check[i] = true;
        dfs(i,1);
        check[i] = false;
    }
    cout << ans << '\n';
    return 0;
}
