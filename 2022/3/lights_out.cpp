#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  bool lights[n];
  for (int i = 0; i < n; ++i)
    lights[i] = false;

  for (int i = 1; i <= m; ++i)
    for (int j = i - 1; j < n; j += i)
      lights[j] = !lights[j];

  int count = 0;

  for (int i = 0; i < n; ++i)
    if (lights[i])
      count++;

  cout << count << endl;
  return 0;
}
