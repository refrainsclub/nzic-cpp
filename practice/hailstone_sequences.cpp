#include <iostream>

int main() {
  int n;

  while (std::cin >> n && n) {
    int count = 0;

    while (n != 1) {
      if (n % 2) {
        n = 3 * n + 1;
      } else {
        n /= 2;
      }

      count++;
    }

    std::cout << count << '\n';
  }

  return 0;
}
