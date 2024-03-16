#include <iostream>

int main() {
  int s, d, c, p;
  std::cin >> s >> d >> c >> p;

  int days = (p - s) / (d - c);
  std::cout << days << '\n';
  return 0;
}
