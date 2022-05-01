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
  sortedarr = (int*) malloc(n * sizeof(int));

  for(int i=0; i<n; i=i+1) {
    printf("%d", sortedarr[i]);
  }

  return 0;
}

int* sort(int* arr, int n) {

  if(n>2) {
    int* left = (int*) malloc(n/2 * sizeof(int));
    int* right = (int*) malloc((n - n/2) * sizeof(int));

    for(int i=0; i<n/2; i++) {
      left[i] = arr[i];
    }

    for(int i=n/2; i<n; i++) {
      right[i - n/2] = arr[i];
    }

    left = sort(left, n/2);
    right = sort(right, n - n/2);
  } else {
    left = arr[0];
    right = arr[1];
  }

  int* sortedarr = (int*) calloc(n, sizeof(int));

  int left_idx = 0;
  int right_idx = 0;

  for(int i=0; i<n; i++) {
    if(left_idx < n/2 && right_idx < (n-n/2)) {
      sortedarr[i] = (left[left_idx] < right[right_idx]) ? left[left_idx] : right[right_idx];
    }
    else if(left_idx >= n/2) {
      sortedarr[i] = right[right_idx]; 
    } else
    
  }

  free(left);
  free(right);

  return sortedarr;
}
