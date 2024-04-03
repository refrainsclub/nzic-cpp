#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // no. knives on sale, max no. knives can hold
  int n, k;
  cin >> n >> k;

  vector<int> durabilities;

  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;

    durabilities.push_back(d);
  }

  // sort descending order
  sort(durabilities.rbegin(), durabilities.rend());

  int sum = 0;
  for (int i = 0; i < k; ++i)
    sum += durabilities[i];

  cout << sum << endl;

  return 0;
}
