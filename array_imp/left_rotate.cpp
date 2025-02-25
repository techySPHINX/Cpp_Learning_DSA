#include <iostream>
using namespace std;


void leftRotate(int arr[], int d, int n) {
 int temp[d];
 for (int i = 0; i < d; i++) {
  temp[i] = arr[i];
 }
 for (int i = 0; i < n - d; i++) {
  arr[i] = arr[i + d];
 }
 for (int i = 0; i < d; i++) {
  arr[n - d + i] = temp[i];
 }
}

void printArray(int arr[], int n) {
 for (int i = 0; i < n; i++) {
  cout << arr[i] << " ";
 }
 cout << endl;
}

int main() {
 int arr[] = {1, 2, 3, 4, 5, 6, 7};
 int n = sizeof(arr) / sizeof(arr[0]);
 int d = 2;

 leftRotate(arr, d, n);
 printArray(arr, n);

  return 0;
 }

   