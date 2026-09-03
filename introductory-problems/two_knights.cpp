#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int k = 1; k <= n; k++) {
    long size = k * k;
    long possible_ways = size * (size - 1) / 2;
    long attacking_ways = 4 * (k - 1) * (k - 2);
    cout << possible_ways - attacking_ways << '\n';
  }
}
