#include <iostream>
#include <vector>
using namespace std;
vector<int> lotto;
void solve(vector<int> &a, int index, int count) {
    if(count == 6) {
        for(int num : lotto)
            printf("%d ", num);
        puts("");
        return;
    }
    int n = a.size();
    if(n == index) return;
    lotto.push_back(a[index]);
    solve(a, index+1, count+1); // index 증가 & count 증가 > 다음걸 사용해서 수행
    lotto.pop_back();           // ㄴ 스텝에서 진행한 것을 빼고
    solve(a, index+1, count);   // index 증가 > 수행 (위에 수행한 경우를 빼고)
}
int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        
        solve(a,0,0);
        cout << '\n';
    }
    return 0;
}
