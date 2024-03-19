#include <iostream>

typedef unsigned long long int ulli;

int main() {
  ulli a, b, c, d, n, u, v;
  std::cin >> a >> b >> c >> d >> n;

  u = v = 1;

  for (ulli i = 0; i < n; i++) {
    ulli tmp = u;
    u = (a * u + b * v) % 10'000;
    v = (c * tmp + d * v) % 10'000;
  }

  std::cout << u << ' ' << v << '\n';
  return 0;
}
