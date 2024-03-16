#include <iostream>

using namespace std;

int main() {
  int max_idx, max = 0;

  for (int i = 0; i < 9; i++) {
    int n;
    cin >> n;

    if (n > max) {
      max = n;
      max_idx = i;
    }
  }

  cout << "Pet " << max_idx + 1 << "\n";
  return 0;
}
