#include <bits/stdc++.h>
using namespace std;

#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define printfirst cout << "first" << "\n"
#define printsecond cout << "second" << "\n"
#define couts(n) cout << n << " "
#define coutn(n) cout << n << endl
#define endl '\n'
#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef unordered_map<int, int> mapii;
typedef unordered_map<int, char> mapic;
typedef unordered_map<char, int> mapci;
typedef unordered_map<char, char> mapcc;
typedef set<int> seti;
typedef set<char> setc;

template <class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& vi : v) {
        in >> vi;
    }
    return in;
}

void printvec(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

#define F first
#define S second
#define sum(v) accumulate(v.begin(), v.end(), 0LL)
#define f(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define getunique(v) \
    {                \
        sort(all(v));\
        v.erase(unique(all(v)), v.end()); \
    }

void generateInputFile(const string& filename, int n, int minValue, int maxValue) {
    ofstream outFile(filename);
    if (!outFile) {
        coutn("Error: Could not create input file!");
        return;
    }
    srand(time(0));
    f(i, n) {
        int num = minValue + rand() % (maxValue - minValue + 1);
        outFile << num << " ";
    }
    outFile.close();
    coutn("Input file generated successfully: " + filename);
}

vi readInputFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        coutn("Error: Could not open input file!");
        return {};
    }
    vi numbers;
    int num;
    while (inFile >> num) {
        numbers.pb(num);
    }
    inFile.close();
    return numbers;
}

void writeOutputFile(const string& filename, const vi& data) {
    ofstream outFile(filename);
    if (!outFile) {
        coutn("Error: Could not create output file!");
        return;
    }
    for (int x : data) {
        outFile << x << " ";
    }
    outFile.close();
    coutn("Output file written successfully: " + filename);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "Enter the number of random numbers to generate: ";
    string inputFile = "input.txt";
    string outputFile = "output.txt"; 
    int n;
    cin >> n;
    int minValue = 1;
    int maxValue = 10000;
    generateInputFile(inputFile, n, minValue, maxValue);
    vi numbers = readInputFile(inputFile);
    if (numbers.empty()) return 0;
    sort(all(numbers));
    writeOutputFile(outputFile, numbers);
    coutn("Sorted numbers written to output file: " + outputFile);
    return 0;
}
