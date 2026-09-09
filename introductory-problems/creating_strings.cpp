#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  vector<string> solutions;
  do {
    solutions.push_back(s);
  } while (next_permutation(s.begin(), s.end()));
  cout << solutions.size() << '\n';
  for (auto s : solutions) {
    cout << s << '\n';
  }
}
