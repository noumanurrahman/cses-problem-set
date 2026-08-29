#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  if (n <= 3) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  vector<int> l1;
  vector<int> l2;
  for (int i = n - 2; i >= 1; i -= 2) {
    cout << i << ' ';
  }
  cout << n << ' ';
  for (int i = n - 3; i >= 1; i -= 2) {
    cout << i << ' ';
  }
  cout << n - 1 << '\n';
}
