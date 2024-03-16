#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  int k;
  map<char, int> favorites;
  map<string, int> misses;

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    string name;
    char favorite;
    cin >> name >> favorite;
    favorites[favorite]++;
  }

  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;

    for (char c : "GCEPLS"s) {
      int stock;
      cin >> stock;
      misses[name] += max(0, favorites[c] - stock);
    }
  }

  for (int i = 0; i < k; i++) {
    string name;
    cin >> name;
    cout << name << " ";

    if (misses[name] == 0) {
      cout << "Successful" << endl;
    } else if (misses[name] <= 2) {
      cout << "Mildly Successful (" << misses[name] << ")" << endl;
    } else {
      cout << "Disaster (" << misses[name] << ")" << endl;
    }
  }

  return 0;
}
