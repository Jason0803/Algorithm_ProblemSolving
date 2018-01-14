#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    if(prev_permutation(a.begin(), a.end())){
        for(int i=0; i<n; i++)
            printf("%d ", a[i]);
    } else printf("%d", -1);
    return 0;
}
