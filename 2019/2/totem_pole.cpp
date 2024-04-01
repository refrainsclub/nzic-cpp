#include <algorithm>
#include <iostream>

int main() {
  int n, positions;
  std::cin >> n >> positions;

  bool taken[positions];
  std::fill(taken, taken + positions, false);

  int res = 0;

  for (int i = 0; i < n; i++) {
    int height;
    std::cin >> height;

    height = std::min(positions, height - 1);

    while (height && taken[height])
      height--;

    if (taken[height])
      continue;

    taken[height] = true;
    res++;
  }

  std::cout << res << '\n';
  return 0;
}
