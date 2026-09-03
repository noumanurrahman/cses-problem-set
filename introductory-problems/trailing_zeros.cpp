#include <iostream>
#include <utility>

using namespace std;

pair<int, int> find_factors(long long n);

int main() {
  long long n;
  cin >> n;

  long long factors5 = 0;

  while (n > 0) {
    n /= 5;
    factors5 += n;
  }

  cout << factors5 << '\n';
}
