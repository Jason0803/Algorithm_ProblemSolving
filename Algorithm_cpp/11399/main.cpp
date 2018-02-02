#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, sum, result;
int main() {
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++) {
        sum += a[i];
        result += sum;
    }
    cout << result << '\n';
    return 0;
}
