#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>& arr, int n, int i, int& iterations) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    iterations++;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    iterations++;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, iterations);
    }
}
void heapSort(vector<int>& arr) {
    int n = arr.size();
    int iterations = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, iterations);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, iterations);
    }
    cout << "Total iterations: " << iterations << endl;
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
    heapSort(arr);
    clock_t end = clock();
    double timeTaken = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Time taken by Heap Sort: " << timeTaken << " ms" << endl;

    return 0;
}
