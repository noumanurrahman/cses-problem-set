#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string text;
  if (getline(cin, text)) {
    stringstream ss(text);
    string word;
    vector<int> nums;
    while (ss >> word) {
      nums.push_back(stoi(word));
    }
    int sum = 0;
    int total = 0;
    for (const auto &k : nums)
      sum += k;
    for (int i = 0; i <= n; i++)
      total += i;

    cout << total - sum << '\n';
  }
}
