#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  string s;
  cin >> s;
  unordered_map<char, int> char_map;
  for (const char &c : s) {
    char_map[c]++;
  }
  bool odd = false;
  string half = "";
  string middle = "";
  for (auto &[ch, n] : char_map) {
    if (n % 2 != 0) {
      if (!odd) {
        odd = true;
      } else {
        cout << "NO SOLUTION\n";
        return 0;
      }
    }
    if (n % 2 == 0) {
      half += string(n / 2, ch);
    } else {
      middle = string(n, ch);
    }
  }
  cout << half;
  cout << middle;
  reverse(half.begin(), half.end());
  cout << half;
}
