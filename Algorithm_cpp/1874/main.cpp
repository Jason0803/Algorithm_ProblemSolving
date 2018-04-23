#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> st;
    string str;
    int K; int N;
    cin >> N;
    int max = 0;
    /*
     
     
     */
    for(int i=0; i<N; ++i) {
        cin >> K;
        if(K>max) {
            for(int j=max; j<K; ++j) {
                st.push(j+1);
                str += "+\n";
            }
        } else if(st.top() >K) {
            cout << "NP" << '\n';
            return 0;
        }
        
        st.pop();
        if(i== N-1) str += "-\n";
        else str += "-\n";
        
        if(max<K) max = K;
    }
    cout << str;
    return 0;
}
