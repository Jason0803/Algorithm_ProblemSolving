// 도움받은곳 : blockdmask님 블로그. (http://blockdmask.tistory.com/229)
#include <cstdio>
int n;
int weight[11][11];
bool check[11];
int m = 99999999;

void dfs(int start, int y, int sum, int count){
    if(count == n && start == y) {
        if(m > sum) m = sum;
        return;
    }
    for(int x=0; x<n; x++){
        if(weight[y][x] == 0) continue;
        
        if(check[y] == false && weight[y][x] > 0){
            check[y] = true;
            sum += weight[y][x];
            
            if(sum <= m)
                dfs(start, x, sum, count+1);
            
            check[y] = false;
            sum -= weight[y][x];
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &weight[i][j]);
    
    for(int y=0; y<n; y++)
        dfs(y,y,0,0);
    
    printf("%d\n", m);
}
