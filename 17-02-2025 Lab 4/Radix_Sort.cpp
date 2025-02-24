// Program to find the time complexity of Radix sort in the best case, worst case and average case in cpp
// take the array as input in vector and then sort it using bubble sort and then find the time complexity of bubble sort
#include<bits/stdc++.h>
using namespace std;
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}
void countingSort(vector<int>& arr, int exp, int &iterations) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        iterations++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        iterations++;
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        iterations++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        iterations++;
    }
}
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    int iterations = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp, iterations);
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
    radixSort(arr);
    clock_t end = clock();
    double timeTaken = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Time taken by Bubble Sort: " << timeTaken << " ms" << endl;
    return 0;
}
