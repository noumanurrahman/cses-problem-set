#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> movies;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    movies.push_back({a, b});
  }
  sort(movies.begin(), movies.end(),
       [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
         return a.second < b.second;
       });
  ll t = 0;
  int n_movies = 0;
  for (pair<ll, ll> movie : movies) {
    if (t > movie.first)
      continue;
    t = movie.second;
    n_movies++;
  }
  cout << n_movies << '\n';
}
