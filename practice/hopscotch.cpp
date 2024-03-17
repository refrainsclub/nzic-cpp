#include <iostream>

bool impossible(char cur, char last) {
  switch (last) {
  case 'S':
    // fall through
  case 'N':
    return cur == 'N';
  case 'E':
    return cur != 'N';
  }

  return false;
}

int main() {
  int states;
  char state, last;

  std::cin >> states;

  for (int i = 0; i < states; i++) {
    std::cin >> state;

    if (impossible(state, last)) {
      std::cout << "impossible\n";
      return 0;
    }

    last = state;
  }

  std::cout << "plausible\n";
  return 0;
}
