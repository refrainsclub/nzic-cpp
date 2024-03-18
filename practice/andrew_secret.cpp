#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::string ln;
  std::getline(std::cin, ln);

  std::string token;
  std::stringstream ss(ln);
  std::vector<int> nums;

  while (std::getline(ss, token, ' ')) {
    nums.push_back(std::stoi(token));
  }

  int min = *std::min_element(nums.begin(), nums.end());
  int max = *std::max_element(nums.begin(), nums.end());
  int avg = std::accumulate(nums.begin(), nums.end(), 0) / nums.size();
  std::cout << min << ' ' << max << ' ' << avg << '\n';
  return 0;
}
