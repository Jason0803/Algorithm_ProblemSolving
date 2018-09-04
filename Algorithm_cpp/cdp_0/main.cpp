#include <iostream>
using namespace std;

int a[50+10];        //    카드뒷면 숫자를 저장하는 배열
int N;                    //    카드 개수
int M;                    //    신제품용량
int sol;                //    정답

void Input(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> a[i];
}

int main(void){
    
    Input();
    
    //    아래 코드의 오류를 정정하세요
    for (int i = 0; i < N - 3; i++){
        for (int j = i + 1; j < N - 2; j++){
            for (int k = j + 1; k < N - 1; k++){
                for (int l = k + 1; l < N; l++){
                    if (a[i] + a[j] + a[k] + a[l] == M) sol++;
                }
            }
        }
    }
    cout << sol;    //    정답 출력
    
    return 0;
}
