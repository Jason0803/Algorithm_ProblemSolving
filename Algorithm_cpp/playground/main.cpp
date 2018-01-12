#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {-1, 3, 0, -7, 8, -3, 0};
    
    // 기존 상태
    for(int i=0; i < sizeof(arr)/sizeof(int) ; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    // 정렬
    sort(arr, arr+sizeof(arr)/sizeof(int));
    
    // 정렬 이후
    for(int i=0; i < sizeof(arr)/sizeof(int) ; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}
