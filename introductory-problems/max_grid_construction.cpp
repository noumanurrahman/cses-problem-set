#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vector<int> nums;
      for (int k = 0; k < i; k++)
        nums.push_back(grid[k][j]);
      for (int k = 0; k < j; k++)
        nums.push_back(grid[i][k]);
      sort(nums.begin(), nums.end());
      int lowest = n * n;
      if (nums.size() == 0) {
        lowest = 0;
      } else {
        for (int k = 0; k < (int)nums.size(); k++) {
          if (nums[k] != k) {
            lowest = k;
            break;
          }
          lowest = nums[nums.size() - 1] + 1;
        }
      }
      cout << lowest << ' ';
      grid[i][j] = lowest;
    }
    cout << '\n';
  }
}
