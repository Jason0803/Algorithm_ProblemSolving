#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
struct Meeting {
    int begin, end;
};
bool comp(const Meeting &a, const Meeting  &b) {
    if(a.end == b.end) return a.begin < b.begin;
    else return a.end < b.end;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n;
    vector<Meeting> meetings(n);
    for(int i=0; i<n; i++) {
        cin >> meetings[i].begin >> meetings[i].end;
    }
    
    sort(meetings.begin(), meetings.end(), comp);
    
    int current = 0;
    int answer = 0;
    for(int i=0; i<n; i++) {
        if(current <= meetings[i].begin) {
            current = meetings[i].end;
            answer++;
        }
    }
    cout << answer << '\n';
    return 0;
}
