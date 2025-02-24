// Program to find the time complexity of bubble sort in best case, worst case and average case in cpp
// take the array as input in vector and then sort it using bubble sort and then find the time complexity of bubble sort
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
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
    bubbleSort(arr);
    clock_t end = clock();
    double timeTaken = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Time taken by Bubble Sort: " << timeTaken << " ms" << endl;
    return 0;
}
