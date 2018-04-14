#include <iostream>

using namespace std;
typedef struct _Point {
    int r, c;
}Point;

int N, K, L, board[101][101], ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> K;
    for(int i=0; i<K; i++) {
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
    }
    cin >> L;
    
    
    return 0;
}
