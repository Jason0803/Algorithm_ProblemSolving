#define MAX 50
#include <cstdio>
#include <algorithm>
using namespace std;

struct POS {
    int x, y;
};

int N, M, bCnt, pCnt, ans = 0x7fffffff;
POS building[15], people[2 * MAX + 2];
bool visit[15];

int getMin() {
    int ret = 0;
    for (int p = 0; p < pCnt; p++) {        // 사람별로
        int minVal = 0x7fffffff;
        for (int b = 0; b < bCnt; b++) {    // 치킨집 중 가장 가까운 곳
            if (!visit[b]) continue;
            int diff = abs(people[p].x - building[b].x) + abs(people[p].y - building[b].y);
            minVal = min(minVal, diff);
        }
        ret += minVal;
    }
    return ret;
}

void dfs(int idx, int cnt) {
    if (cnt == M) {
        int min = getMin();
        if (ans > min) ans = min;
        return;
    }
    for (int i = idx + 1; i < bCnt; i++) {
        if (!visit[i]) {
            // 2. 방문하지 않은 것 중,방문하며 cnt 는 M을 향해 다가간다
            // main 의 1번에 지나온 i 번째는 false
            visit[i] = true;
            dfs(i, cnt + 1);
            visit[i] = false;
        }
    }
}

int main() {
    scanf("%d %d ", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            scanf("%d ", &val);
            if (val == 2) building[bCnt++] = { i, j };
            if (val == 1) people[pCnt++] = { i, j };
        }
    }
    
    for (int i = 0; i < bCnt; i++) {
        // 1. i 번째 치킨집 선택하고 시작하는 경우,
        visit[i] = true;
        dfs(i, 1);
        visit[i] = false;
    }
    
    printf("%d ", ans);
    return 0;
}
