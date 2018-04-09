/*
 시간복잡도 : O(n)
 공간복잡도 : O(n)

 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int T, N, M;
stack<char> c_st;
string input;
void encode() {
    int cnt = 1;
    for(int i=0; i<=input.size(); i++) {
        if(c_st.empty() && i < input.size()) {
            c_st.push(input[i]);
        } else {
            if(c_st.top() == input[i]) {
                cnt++;
            } else {
                cout << cnt << c_st.top();
                cnt = 1;
                c_st.pop();
                if(i < input.size()) c_st.push(input[i]);
            }
        }
    }
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    
    while(T--) {
        cin >> input;
        encode();
    }

    return 0;
}
