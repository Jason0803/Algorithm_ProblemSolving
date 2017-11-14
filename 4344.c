#include <stdio.h>
#include <stdlib.h>

int main() {
	int testCase = 0;
	int numberOfStudents = 0;
	int** scores;
	int sum = 0;
	double avg = 0.0;
	int count = 0;

	scanf("%d%*c", &testCase);
	scores = (int** )malloc(testCase * sizeof(int* ));
	
	for(int i = 0; i < testCase; i++) {	
		scanf("%d", &numberOfStudents);
		if(numberOfStudents >= 1 && numberOfStudents <= 1000) {
			sum = 0;
			scores[i] = (int* )malloc(numberOfStudents * sizeof(int));
			
			for(int j = 0; j < numberOfStudents; j++) {
				scanf(" %d", &scores[i][j]);
				sum += scores[i][j];
			}
			avg = (double)sum / numberOfStudents;
			count = 0;
			for(int k = 0; k < numberOfStudents; k++) {
				if((double)scores[i][k] > avg)
					count++;
				
			}
			printf("%.3lf%%\n", (double)(count) / numberOfStudents * 100);

		} else {
			free(scores);
		}

	}
	return 0;
}