#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef pair<int, int> point;

const vector<point> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
  int x, y;
  cin >> x >> y;
  vector<string> building(x);
  for (int i = 0; i < x; i++)
    cin >> building[i];
  int rooms = 0;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (building[i][j] == '#')
        continue;
      rooms++;
      stack<point> st;
      st.push({i, j});
      while (!st.empty()) {
        point p = st.top();
        st.pop();
        for (point move : moves) {
          int nx = p.first + move.first;
          int ny = p.second + move.second;
          if (0 <= nx && nx < x && 0 <= ny && ny < y &&
              building[nx][ny] == '.') {
            building[nx][ny] = '#';
            st.push({nx, ny});
          }
        }
      }
    }
  }
  cout << rooms << '\n';
}
