#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
int comp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main () {
   int n = 0;
   scanf("%d", &n);
   if(n >= 1 && n <= MAX) {
      int* array = (int*)malloc(sizeof(int)*n);
      for(int i = 0; i < n; i ++) {
         scanf("%d", &array[i]);
      }
      qsort(array, n, sizeof(int), comp);

      for(int j = 0; j < n; j++) 
         printf("%d\n", array[j]);
   }
   return 0;
}