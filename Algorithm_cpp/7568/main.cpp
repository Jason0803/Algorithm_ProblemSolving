#include <cstdio>
#include <vector>

using namespace std;

struct Person {
    int weight;
    int height;
    int rank;
};

int compare(Person a, Person b) {
    if(a.height > b.height && a.weight > b.weight) {
        return 1;
    } else if(a.height < b.height && a.weight < b.weight) {
        return -1;
    } else return 0;
 
}

int main() {
    int N;
    Person temp;
    vector<Person> list;
    scanf("%d", &N);
    
    for(int test_case = 1; test_case <= N; test_case++) {
        scanf("%d %d", &temp.weight, &temp.height);
        temp.rank = N;
        list.push_back(temp);
    }
    
    for(int i = 0; i < list.size()-1; i++) {
        for(int j = i + 1; j < list.size(); j++) {
            int comp = compare(list.at(i), list.at(j));
            if(comp == 1) {
                list.at(i).rank--;
            } else if(comp == 0) {
                list.at(i).rank--;
                list.at(j).rank--;
            } else list.at(j).rank--;
        }
    }
    
    for(Person a : list) {
        printf("%d ", a.rank);
    }
    
    return 0;
}
