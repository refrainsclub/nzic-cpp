#include <iostream>

int main() {
  int n, s, c, count;
  std::cin >> n >> s;

  for (int i = 0; i < n; i++) {
    std::cin >> c;

    if (c == s) {
      std::cout << i << '\n';
      return 0;
    }
  }

  return 0;
}
