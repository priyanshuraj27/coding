
// Program to find the time complexity of bubble sort in best case, worst case and average case in cpp
// take the array as input in vector and then sort it using bubble sort and then find the time complexity of bubble sort
#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> arr, int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr,n);
    clock_t end = clock();
    double timeTaken = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Time taken by Bubble Sort: " << timeTaken << " ms" << endl;
    return 0;
}
