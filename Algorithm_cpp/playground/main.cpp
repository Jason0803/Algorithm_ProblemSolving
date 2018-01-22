#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int myints[] = {3,7,2,5,6,4,9};
    printf("min_element : %d\n", *min_element(myints, myints+7));
    printf("%max_element : %d\n", *max_element(myints, myints+7));
    return 0;
}
