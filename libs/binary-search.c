#include<stdio.h>

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
