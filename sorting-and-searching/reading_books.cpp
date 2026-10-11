#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> books(n);
  for (int i = 0; i < n; i++)
    cin >> books[i];
  sort(books.begin(), books.end());
  ll longest_read = books[n - 1];
  ll other_sum = 0;
  for (int i = 0; i < n - 1; i++)
    other_sum += books[i];
  ll answer;
  if (longest_read > other_sum)
    answer = 2 * longest_read;
  else
    answer = longest_read + other_sum;
  cout << answer << '\n';
}
