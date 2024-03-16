#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  char prev = 'A';
  int sum = s.length();

  for (char c : s) {
    int left = (prev - c + 26) % 26;
    int right = (c - prev + 26) % 26;

    sum += std::min(left, right);
    prev = c;
  }

  std::cout << sum << '\n';
  return 0;
}
