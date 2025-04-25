// to implement the 0 1 knapsack problem using greedy method
#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace std;
void insertionSort(vector<pair<double, int>> &vec)
{
int n = vec.size();
for (int i = 1; i < n; ++i)
{
pair<double, int> key = vec[i];
int j = i - 1;
while (j >= 0 && vec[j].first < key.first)
{
vec[j + 1] = vec[j];
--j;
}
vec[j + 1] = key;
}
}
int main()
{
cout << "Enter size and weight" << endl;
int n, target;
cin >> n >> target;
vector<int> profit(n), weights(n);
cout << "Enter Profits" << endl;
for (int i = 0; i < n; i++)
cin >> profit[i];
cout << "Enter Weights" << endl;
for (int i = 0; i < n; i++)
cin >> weights[i];
auto start = chrono::high_resolution_clock::now();
vector<pair<double, int>> vec;
for (int i = 0; i < n; ++i)
{
vec.push_back({profit[i] / (weights[i] * 1.0), i});
}
insertionSort(vec);
int weight = 0;
double maxProfit = 0.0;
int i = 0;
cout<<"Selected Items:"<<endl;
while (weight < target && i < n)
{
int itemWeight = weights[vec[i].second];
int itemProfit = profit[vec[i].second];
if (weight + itemWeight <= target)
{
cout<<itemProfit<<" "<<itemWeight<<endl;
weight += itemWeight;
maxProfit += itemProfit;
}
else
{
cout << itemProfit * ((target - weight) / (double)itemWeight) << " " << target -
weight << endl;
maxProfit += itemProfit * ((target - weight) / (double)itemWeight);
break;
}
i++;
}
cout << "Max Profit is " << maxProfit << endl;
auto end = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
cout << "Time taken by the algorithm: " << duration.count() << " nanoseconds" << endl;
return 0;
}
