#include <iostream>
#include <vector>
using namespace std;

void moveZerosToRight(vector<int>& arr) {
 int n = arr.size();
 int j = 0;

 for (int i = 0; i < n; i++) {
  if (arr[i] != 0) {
   swap(arr[i], arr[j]);
   j++;
  }
 }
}

// Function to move all zeros to the left side of the array
void moveZerosToLeft(vector<int>& arr) {
 int n = arr.size();
 int j = n - 1; // index of the next non-zero element

 for (int i = n - 1; i >= 0; i--) {
  if (arr[i] != 0) {
   swap(arr[i], arr[j]);
   j--;
  }
 }
}

int main() {
 vector<int> arr = {0, 1, 0, 3, 12, 0, 5};

 cout << "Original array: ";
 for (int num : arr) {
  cout << num << " ";
 }
 cout << endl;

 moveZerosToRight(arr);
 cout << "Array after moving zeros to the right: ";
 for (int num : arr) {
  cout << num << " ";
 }
 cout << endl;

 // Reset the array to original state
 arr = {0, 1, 0, 3, 12, 0, 5};

 moveZerosToLeft(arr);
 cout << "Array after moving zeros to the left: ";
 for (int num : arr) {
  cout << num << " ";
 }
 cout << endl;

 return 0;
}
