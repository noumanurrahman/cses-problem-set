#include <iostream>
#include <string>
using namespace std;

int main() {
  string seq;
  cin >> seq;

  int largest = 1;
  int current = 1;

  for (int i = 1; i < seq.size(); i++) {
    if (seq[i] == seq[i - 1])
      current++;
    else
      current = 1;

    if (current > largest) {
      largest = current;
    }
  }

  cout << largest << '\n';
}
