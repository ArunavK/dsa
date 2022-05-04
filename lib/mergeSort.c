#include<stdio.h>
#include<stdlib.h>

int* sort(int*, int);

int main() {
  int n;
  printf("Enter no. of inputs: ");
  scanf("%d", &n);
  
  int* arr;
  arr = (int*) malloc(n * sizeof(int));
  puts("Enter list:");
  for(int i = 0; i < n; i = i + 1) {
    scanf("%d", &arr[i]); 
  }
  
  int* sortedarr;
  sortedarr = sort(arr, n);

  for(int i=0; i<n; i=i+1) {
    printf("%d ", sortedarr[i]);
  }
  printf("\n");

  return 0;
}

int* sort(int* arr, int n) {

  int* sortedarr = (int*) calloc(n, sizeof(int));
  if(n == 1) {
    return arr;
  } else if (n == 2) {
    if (arr[0] < arr[1]) {
      sortedarr[0] = arr[0];
      sortedarr[1] = arr[1];
    } else {
      sortedarr[0] = arr[1];
      sortedarr[1] = arr[0];
    }
    return sortedarr;
  }

  int* left;
  int* right;
  left = (int*) malloc(n/2 * sizeof(int));
  right = (int*) malloc((n - n/2) * sizeof(int));

  if(n>2) {

    for(int i=0; i<n/2; i++) {
      left[i] = arr[i];
    }

    for(int i=n/2; i<n; i++) {
      right[i - n/2] = arr[i];
    }

    left = sort(left, n/2);
    right = sort(right, n - n/2);
<<<<<<< HEAD:merge-sort/mergeSort.c
  } else {
    left[0] = arr[0];
    right[0] = arr[1];
  }

=======

  } 

  sortedarr = (int*) calloc(n, sizeof(int));
>>>>>>> 006c86613be4555cdf88377b28c365f7f145721a:lib/mergeSort.c

  int left_idx = 0;
  int right_idx = 0;

  for(int i=0; i<n; i++) {
    if(left_idx < n/2 && right_idx < (n-n/2)) {
<<<<<<< HEAD:merge-sort/mergeSort.c
      if(left[left_idx] < right[right_idx]) {
=======
      if (left[left_idx] < right[right_idx]) {
>>>>>>> 006c86613be4555cdf88377b28c365f7f145721a:lib/mergeSort.c
        sortedarr[i] = left[left_idx];
        left_idx++;
      } else {
        sortedarr[i] = right[right_idx];
        right_idx++;
      }
    }
    else if(left_idx >= n/2) {
      sortedarr[i] = right[right_idx]; 
<<<<<<< HEAD:merge-sort/mergeSort.c
      right_idx++;
    } else {
      sortedarr[i] = left[left_idx];
      left_idx++;
    }
    
=======
    } else {
      sortedarr[i] = left[left_idx]; 
    }
   
>>>>>>> 006c86613be4555cdf88377b28c365f7f145721a:lib/mergeSort.c
  }

  free(left);
  free(right);

  return sortedarr;
}
