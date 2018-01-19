#include <cstdio>

int main() {
    int T, N, M;           // N:창구 수, M:고객 수
    int t[100001];         // 창구의 업무처리시간
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        // 데이터 입력 및 초기화
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++) {
            scanf("%d", &t[i]);
        }
        // 탐색 시작
        long long start = 1;         // 탐색 시간 시작점
        long long end = 1e14 + 1;    // 탐색 시간 끝점
        long long res = end;         // 최소 수용시간
        while (start <= end) {
            long long mid = (start + end) / 2;     // 비교 시간
            long long sum = 0;                     // mid초 안에 수용 가능 고객
            for (int i = 0; i < N; i++)
                sum += mid / t[i];
            // mid초 안에 모든 고객을 수용 가능
            if (sum >= M) {
                res = res < mid ? res : mid;
                end = mid - 1;        // 탐색 시간 범위 : mid 이하
            }
            // mid초 안에 모든 고객을 수용 불가능
            else start = mid + 1;     // 탐색 시간 범위 : mid 이상
        }
        printf("#%d %lld\n", tc, res);
    }
    return 0;
}
