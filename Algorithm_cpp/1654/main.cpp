#include <iostream>
#include <vector>
using namespace std;
int k, n;
long long result;
bool check(const vector<long long> &list, long long length) {
    int ret = 0;
    for(long long a : list) {
        ret += a/length;
    }
    return ret >= n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> k >> n;
    vector<long long> list(k);
    long long max = 0;
    for(int i=0; i<k; i++){
        cin >> list[i];
        if(max < list[i]) max = list[i];
    }
    long long left = 1;
    long long right = max;
    while(left <= right) {
        long long mid = (left + right) / 2;
        if(check(list, mid)) {
            if(result < mid) result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result << '\n';
    return 0;
}
