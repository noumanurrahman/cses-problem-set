#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> customers;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    customers.push_back(a);
    customers.push_back(-b);
  }
  ll curr = 0;
  sort(customers.begin(), customers.end(),
       [](ll &a, ll &b) { return abs(a) < abs(b); });
  ll max_customers = 0;
  for (int i = 0; i < (int)customers.size(); i++) {
    ll time = customers[i];
    if (time > 0)
      curr++;
    else
      curr--;
    max_customers = max(max_customers, curr);
  }
  cout << max_customers << '\n';
}
