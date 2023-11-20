#include <stdio.h>

void printArray(int a[][3] ){
  for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}

int main() {
  int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  printf("Values in array1 by row are:\n");
  printArray(array1);

  int array2[2][3] = {1, 2, 3, 4, 5, 6};
  printf("Values in array2 by row are:\n");
  printArray(array2);

  // Adding curly more items with curly brackets produces an error because there are only two array3[int][int] values
  int array3[2][3] = {{1, 2}, {4}}; //{5}, {6}
  printf("Values in array3 by row are:\n");
  printArray(array3);
  
  return 0;
}