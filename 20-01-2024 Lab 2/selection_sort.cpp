// Program to find the time complexity of selection sort in best case, worst case and average case in cpp
// take the array as input in vector and then sort it using bubble sort and then find the time of selection sort using clock_t
// Program to find the time complexity of bubble sort in best case, worst case and average case in cpp
// take the array as input in vector and then sort it using bubble sort and then find the time complexity of bubble sort
#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    clock_t start = clock();
    selectionSort(arr);
    clock_t end = clock();
    double timeTaken = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Time taken by Bubble Sort: " << timeTaken << " ms" << endl;
    return 0;
}