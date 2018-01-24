#include <iostream>
using namespace std;
int map[9][9];
bool check_row[9][10];           // row 행에 column 값이 있는지 여부 확인
bool check_column[9][10];        // row 열에 column 값이 있는지 여부 확인
bool check_value[9][10];         // 9개의 3*3 으로 나눈 뒤, 각 사각형에 들어가는 숫자를 저장
int square(int x, int y) {
    return (x/3)*3+(y/3);
}
bool solve(int n) {
    if(n == 81) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++){
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = n / 9;
    int y = n % 9;
    if(map[x][y] != 0) {
        return solve(n+1);
    } else {
        for(int i=1; i<=9; i++) {
            // i = 찾으려는 값
            if(!check_row[x][i] && !check_column[y][i] && !check_value[square(x,y)][i]) {
                check_row[x][i] = check_column[y][i] = check_value[square(x,y)][i] = true;
                map[x][y] = i;
                if(solve(n+1)) {
                    return true;
                }
                map[x][y] = 0;
                check_row[x][i] = check_column[y][i] = check_value[square(x,y)][i] = false;
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> map[i][j];
            if(map[i][j] != 0) {
                check_row[i][map[i][j]] = true;
                check_column[j][map[i][j]] = true;
                check_value[square(i,j)][map[i][j]] = true;
            }
        }
    }
    solve(0);
    return 0;
}
