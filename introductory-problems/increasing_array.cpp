#include <iostream>
#include <limits>
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
    vector<long> nums;
    while (ss >> word) {
      nums.push_back(stoi(word));
    }
    long moves = 0;
    for (long i = 1; i < nums.size(); i++) {
      long prev = nums[i - 1];
      long curr = nums[i];
      if (prev > curr) {
        nums[i] = curr + (prev - curr);
        moves += prev - curr;
      }
    }
    cout << moves << '\n';
  }
}
