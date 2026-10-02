#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  ll x, y, k;
  cin >> x >> y >> k;
  vector<ll> requests(x);
  vector<ll> apartments(y);
  for (ll i = 0; i < x; i++)
    cin >> requests[i];
  for (ll i = 0; i < y; i++)
    cin >> apartments[i];
  sort(requests.begin(), requests.end());
  sort(apartments.begin(), apartments.end());
  int i = 0;
  int j = 0;
  ll answer = 0;
  while (i < x && j < y) {
    int r = requests[i];
    int a = apartments[j];
    if (a < r - k)
      j++;
    else if (a > r + k)
      i++;
    else {
      answer++;
      i++;
      j++;
    }
  }
  cout << answer << '\n';
}
