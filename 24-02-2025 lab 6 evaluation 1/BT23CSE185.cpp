/*Coded by Priyanshu (BT23CSE185)*/
// Quick Sort 
// DAA Lab evaluation 1
// Date: 24-02-2025
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right, int& iterations) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        iterations++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);  
    return i + 1;
}
void quickSort(vector<int>& arr, int left, int right, int& iterations) {
    if (left < right) {
        int pi = partition(arr, left, right, iterations);
        quickSort(arr, left, pi - 1, iterations);
        quickSort(arr, pi + 1, right, iterations);
    }
}
void display(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int iterations = 0;
    clock_t start = clock();
    quickSort(arr, 0, n - 1, iterations);
    clock_t end = clock();
    display(arr);
    double timeTaken = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Time taken by QuickSort: " << timeTaken << " ms" << endl;
    cout << "Total iterations: " << iterations << endl;
    return 0;
}
