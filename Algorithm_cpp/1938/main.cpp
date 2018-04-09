#include <iostream>
#include <queue>
#define VERTICAL 1
#define HORIZON  0
using namespace std;
typedef struct _Pos {
    int centre_r, centre_c;
    int ori;     // 0 : hor, 1 : vert
    int cnt;     // count of movements
} Pos;
Pos st, fn;
int N, ans;
char map[52][52];
bool visited[52][52][2];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

bool rotatable(Pos p) {
    bool ret = false;
    if(p.ori == HORIZON) {
        // check the above & below of centre
        if(1 <= p.centre_r && p.centre_r < N-1) {
           if(map[p.centre_r-1][p.centre_c] != 1 && map[p.centre_r+1][p.centre_c] != 1)
               ret = true;
        }
    } else {
        // check the left & right of centre
        if(1 <= p.centre_c && p.centre_c < N-1) {
            if(map[p.centre_r][p.centre_c-1] != 1 && map[p.centre_r][p.centre_c+1] != 1) {
                ret = true;
            }
        }
    }
    
    return ret;
}
void find_centre(int r, int c, char type) {
    // 1. check if hor.

    if(c < N-2 && map[r][c+1] == type && map[r][c+2] == type) {
        if(type == 'B'){
            st.centre_r = r;
            st.centre_c = c+1;
            st.ori = HORIZON;
        } else {
            fn.centre_r = r;
            fn.centre_c = c+1;
            fn.ori = HORIZON;
        }
    }
    
    
    // 1. check if vert.
    
    if(r < N-2 && map[r+1][c] == type && map[r+2][c] == type) {
        if(type == 'B') {
            st.centre_r = r+1;
            st.centre_c = c;
            st.ori = VERTICAL;
        } else {
            fn.centre_r = r+1;
            fn.centre_c = c;
            fn.ori = VERTICAL;
        }
    }

}
void input() {
    bool st_found = false;
    bool fn_found = false;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'B' && !st_found) {
                find_centre(i, j, 'B');
                st_found = true;
            }
            if(map[i][j] == 'E' && ! fn_found) {
                find_centre(i, j, 'E');
                fn_found = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    
    input();
    printf("St : (%d %d)\n", st.centre_r, st.centre_c);
    printf("Fn : (%d %d)\n", fn.centre_r, fn.centre_c);
    return 0;
}
