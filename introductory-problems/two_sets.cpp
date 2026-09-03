#include <iostream>
#include <vector>

using namespace std;

int main() {
  long n;
  cin >> n;
  vector<long> a, b;
  long sum_a = 0;
  long sum_b = 0;
  for (long i = n; i >= 1; i--) {
    if (i == n) {
      a.push_back(i);
      sum_a += i;
      continue;
    }
    if (sum_a > sum_b) {
      b.push_back(i);
      sum_b += i;
    } else {
      a.push_back(i);
      sum_a += i;
    }
  }

  if (sum_a == sum_b) {
    cout << "YES\n";
    cout << a.size() << '\n';
    for (int i : a) {
      cout << i << ' ';
    }
    cout << '\n';
    cout << b.size() << '\n';
    for (int i : b) {
      cout << i << ' ';
    }
    cout << '\n';
  } else {
    cout << "NO\n";
  }
}
