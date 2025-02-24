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
#define getunique(v) { sort(all(v)); v.erase(unique(all(v)), v.end()); }

// Function to generate tickets using std::rand()
vector<int> generateWithRand(int N) {
    set<int> tickets;
    while (tickets.size() < N) {
        int ticket = 100 + (std::rand() % (9999 - 100 + 1));
        tickets.insert(ticket);
    }
    return vector<int>(tickets.begin(), tickets.end());
}
// Function to generate tickets using std::uniform_int_distribution
vector<int> generateWithUniformInt(int N) {
    set<int> tickets;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(100, 9999);

    while (tickets.size() < N) {
        tickets.insert(dist(gen));
    }
    return vector<int>(tickets.begin(), tickets.end());
}
// Function to generate tickets using std::normal_distribution
vector<int> generateWithNormalDistribution(int N) {
    set<int> tickets;
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> dist(5000.0, 2000.0);

    while (tickets.size() < N) {
        int ticket = static_cast<int>(round(dist(gen)));
        if (ticket >= 100 && ticket <= 9999) {
            tickets.insert(ticket);
        }
    }
    return vector<int>(tickets.begin(), tickets.end());
}
// Function to generate tickets using std::exponential_distribution
vector<int> generateWithExponentialDistribution(int N) {
    set<int> tickets;
    random_device rd;
    mt19937 gen(rd());
    exponential_distribution<double> dist(1.0 / 5000.0); // λ = 1/mean
    while (tickets.size() < N) {
        int ticket = static_cast<int>(round(dist(gen))) + 100;
        if (ticket >= 100 && ticket <= 9999) {
            tickets.insert(ticket);
        }
    }
    return vector<int>(tickets.begin(), tickets.end());
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter the number of unique lottery tickets to generate: ";
    cin >> n;

    if (n <= 0 || n > 9900) {
        coutn("Invalid input. Number of tickets must be between 1 and 9900.");
        return 1;
    }
    cout << "\nGenerating tickets using std::rand():\n";
    vector<int> randTickets = generateWithRand(n);
    printvec(randTickets);
    cout << "\nGenerating tickets using std::uniform_int_distribution:\n";
    vector<int> uniformTickets = generateWithUniformInt(n);
    printvec(uniformTickets);
    cout << "\nGenerating tickets using std::normal_distribution:\n";
    vector<int> normalTickets = generateWithNormalDistribution(n);
    printvec(normalTickets);
    cout << "\nGenerating tickets using std::exponential_distribution:\n";
    vector<int> exponentialTickets = generateWithExponentialDistribution(n);
    printvec(exponentialTickets);

    return 0;
}
