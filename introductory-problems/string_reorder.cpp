#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> freq(26, 0);
  for (char c : s)
    freq[c - 'A']++;
  for (int f : freq) {
    if (f > (n + 1) / 2) {
      cout << -1 << '\n';
      return 0;
    }
  }
  string answer = "";
  for (int i = 0; i < n; i++) {
    int c = -1;
    for (int j = 0; j < 26; j++) {
      if (freq[j] == 0)
        continue;
      if (i > 0 && 'A' + j == answer[i - 1])
        continue;
      freq[j]--;
      int remaining = n - i - 1;
      int max_freq = 0;
      for (int k = 0; k < 26; k++)
        max_freq = max(max_freq, freq[k]);
      if (max_freq <= (remaining + 1) / 2) {
        c = j;
        break;
      }
      freq[j]++;
    }
    if (c == -1) {
      cout << -1 << '\n';
      return 0;
    }
    answer += 'A' + c;
  }
  cout << answer << '\n';
}
