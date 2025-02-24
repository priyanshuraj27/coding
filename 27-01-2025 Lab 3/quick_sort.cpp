#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high, int& iterations) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        iterations++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int& iterations) {
    if (low < high) {
        int pi = partition(arr, low, high, iterations);
        quickSort(arr, low, pi - 1, iterations);
        quickSort(arr, pi + 1, high, iterations);
    }
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
    double timeTaken = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Time taken by QuickSort: " << timeTaken << " ms" << endl;
    cout << "Total iterations: " << iterations << endl;
    return 0;
}
