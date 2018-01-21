#include <cstdio>
#include <algorithm>
#define MAX 300
using namespace std;
int d[MAX+1][MAX+1];
int n, m;
int find(int r, int c) {
    int a, b;
    if(r == 1 && c == 1) return 0;
    if(d[r][c] != 0) return d[r][c];
    if(r == 1 || c == 1) {
        if(c!=1) return find(1, c-1) + 1;
        if(r!=1) return find(r-1,1) + 1;
    }

    a = find(r-1, c) + find(1,c) + 1;
    b = find(r, c-1) + find(r, 1) + 1;
    
    d[r][c] = d[c][r] = min(a,b);
    return d[r][c];
}
int main(){
    // ..그냥 n*m -1 하면 됨.
    d[1][2] = d[2][1] = 1;
    scanf("%d %d", &n, &m);
    printf("%d\n",find(n,m));
    return 0;
}
