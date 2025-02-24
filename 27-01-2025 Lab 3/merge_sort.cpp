#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr, int left, int mid, int right, int& iterations) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        iterations++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        iterations++;
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        iterations++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        iterations++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        iterations++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, int& iterations) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, iterations);
    mergeSort(arr, mid + 1, right, iterations);
    merge(arr, left, mid, right, iterations);
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
    int iterations = 0;
    clock_t start = clock();
    mergeSort(arr, 0, n - 1, iterations);
    clock_t end = clock();
    double timeTaken = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Time taken by Merge Sort: " << timeTaken << " ms" << endl;
    cout << "Total iterations: " << iterations << endl;
    return 0;
}
