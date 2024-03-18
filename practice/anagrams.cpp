#include <iostream>
#include <map>
#include <string>

std::map<char, int> count(std::string str) {
  std::map<char, int> count;

  for (char c : str) {
    count[c]++;
  }

  return count;
}

int main() {
  std::string a;
  std::string b;
  std::cin >> a >> b;

  if (count(a) == count(b)) {
    std::cout << "yes\n";
  } else {
    std::cout << "no\n";
  }

  return 0;
}
