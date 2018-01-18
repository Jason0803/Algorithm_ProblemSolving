#include <iostream>
#include <queue>
#include <set>
#define MAX 3
using namespace std;

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
int arr[MAX][MAX];
int tmp[MAX][MAX];
queue<pair<int, int>> q;
set<int> visit;

int bfs()
{
	while (!q.empty()) {
		int sum = q.front().first;
		int w = q.front().second;
		q.pop();

		if (sum == 123456780)
			return w;

		int tmpSum = sum;
		int y, x;
		for (int i = MAX - 1; i >= 0; i--) {
			for (int j = MAX - 1; j >= 0; j--) {
				tmp[i][j] = tmpSum % 10;
				if (tmp[i][j] == 0) {
					y = i; x = j;
				}
				tmpSum /= 10;
			}
		}

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny >= 0 && nx >= 0 && ny <= MAX - 1 && nx <= MAX - 1) {
				int swap_value = tmp[ny][nx];
				int cost = 0;
				for (int j = 0; j < MAX; j++) {
					for (int k = 0; k < MAX; k++) {
						cost *= 10;
						if (j == y && k == x) {
							cost += swap_value;
						}
						else if (j == ny && k == nx) {
							cost += 0;
						}
						else {
							cost += tmp[j][k];
						}
					}
				}
				if (visit.find(cost) == visit.end()) {
					visit.insert(cost);
					q.push(make_pair(cost, w + 1));
				}
			}
		}
	}
	return -1;
}

int main()
{
	int n = 0;
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> arr[i][j];
			sum *= 10;
			sum += arr[i][j];

			n++;
		}
	}

	q.push(make_pair(sum, 0));
	visit.insert(sum);

	cout << bfs();
	return 0;
}