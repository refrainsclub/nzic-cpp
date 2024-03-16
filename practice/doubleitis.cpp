#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  n *= 0.5;

  if (n < m) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}
