#include<stdio.h>

int search(int, int*, int);

int main() {

  int n;
  printf("Enter no. of inputs: ");
  scanf("%d", &n);
  
  int arr[100];
  puts("Enter list:");
  for(int i = 0; i < n; i = i + 1) {
    scanf("%d", &arr[i]); 
  }
  
  for(int i=0; i < n; i = i+1) {
    printf("%d\t", i);
  }  
  printf("\n");
  for(int i=0; i < n; i = i+1) {
    printf("|\t");
  }  
  printf("\n");
  for(int i=0; i<n; i=i+1) {
    printf("%d\t", arr[i]);
  }
  printf("\n");

  int targ;
  printf("Enter target: ");
  scanf("%d", &targ);

  int pos;
  pos = searchsorted(targ, arr, n);
  if(pos == -1)
    printf("Target not found in list\n");
  else
    printf("Position: %d\n", pos);
  return 0;
}

int searchsorted(int targ, int* arr, int n) {
  int low = 0;
  int high = n-1;
  int mid = (low + high)/2;

  int idx;
  while (low < high) {

    mid = (low + high) / 2;

    if (targ == arr[mid]) {
      return mid;
    } else if (targ == arr[low]) {
      return low;
    } else if (targ == arr[high]) {
      return high;
    } else if (low == mid) {
      return -1;  
    } else if(targ < arr[mid]) {
      high = mid;
    } else if (targ > arr[mid]) {
      low = mid; 
    }
  }

  return -1;
}
