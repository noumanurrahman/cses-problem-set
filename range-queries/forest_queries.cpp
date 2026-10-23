#include <iostream>
#include <vector>

using namespace std;

int range(int x1, int x2, int y1, int y2, vector<vector<int>> &prefix) {
  return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] +
         prefix[x1 - 1][y1 - 1];
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char x;
      cin >> x;
      if (x == '*')
        forest[i][j] = 1;
    }
  }
  vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                     prefix[i - 1][j - 1] + forest[i][j];
    }
  }
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << range(x1, x2, y1, y2, prefix) << '\n';
  }
}
