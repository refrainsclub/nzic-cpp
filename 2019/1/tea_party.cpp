#include <iostream>
#include <map>

int main() {
  int n, k;
  std::map<char, int> favorites;
  std::map<std::string, int> misses;

  std::cin >> n >> k;

  for (int i = 0; i < n; i++) {
    std::string name;
    char favorite;
    std::cin >> name >> favorite;
    favorites[favorite]++;
  }

  for (int i = 0; i < n; i++) {
    std::string name;
    std::cin >> name;

    for (char c : (std::string) "GCEPLS") {
      int stock;
      std::cin >> stock;
      misses[name] += std::max(0, favorites[c] - stock);
    }
  }

  for (int i = 0; i < k; i++) {
    std::string name;
    std::cin >> name;
    std::cout << name << " ";

    if (misses[name] == 0) {
      std::cout << "Successful\n";
    } else if (misses[name] <= 2) {
      std::cout << "Mildly Successful (" << misses[name] << ")\n";
    } else {
      std::cout << "Disaster (" << misses[name] << ")\n";
    }
  }

  return 0;
}
