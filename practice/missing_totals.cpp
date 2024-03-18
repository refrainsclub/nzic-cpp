#include <algorithm>
#include <iostream>

int main() {
  int n, p, d;
  std::cin >> n;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> p >> d;
    int final = std::max(0, p - d);
    sum += final;
  }

  std::cout << sum << '\n';
  return 0;
}
