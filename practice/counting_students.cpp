#include <iostream>
#include <map>

int main() {
  int n, x;
  std::map<int, int> nums;

  // read user input
  std::cin >> n;

  // store occurences
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    nums[x]++;
  }

  // print duplicates
  for (auto &[key, value] : nums) {
    if (value > 1) {
      std::cout << key << '\n';
    }
  }
}
