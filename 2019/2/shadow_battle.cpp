#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int player_damage = 0;                // accumulated player damage
  vector<int> health(200), damage(200); // 200 positions available

  for (int i = 0; i < n; i++) {
    int pos, dmg;
    cin >> pos >> dmg;

    // zero idx
    pos--;

    damage[pos] = dmg;
    health[pos] = 10;

    player_damage += dmg;
  }

  int shadow_position;
  int shadow_damage;
  cin >> shadow_position >> shadow_damage;

  // zero idx
  shadow_position--;

  int shadow_health = 60;

  vector<int>::iterator left, right;
  left = right = health.begin() + shadow_position;

  bool shadow_alive, players_alive, shadows_turn;
  shadow_alive = players_alive = shadows_turn = true;

  while (shadow_alive && players_alive) {
    if (shadows_turn) {
      // find players to left and right who are alive
      while (left > health.begin() && *left <= 0) {
        left--;
      }

      while (right < health.end() && *right <= 0) {
        right++;
      }

      // damage them
      *left -= shadow_damage;
      *right -= shadow_damage;

      // if they die, negate their dmg from the total
      if (*left <= 0) {
        player_damage -= damage[left - health.begin()];
      }

      if (*right <= 0) {
        player_damage -= damage[right - health.begin()];
      }

      // players still dealt collective damage, therefore some alive
      players_alive = player_damage > 0;
    } else {
      shadow_health -= player_damage;
      shadow_alive = shadow_health > 0;
    }

    shadows_turn = !shadows_turn;
  }

  if (shadow_alive) {
    cout << "Shadow wins!\n";
  } else {
    cout << "We win! Players alive:";

    for (vector<int>::iterator h = health.begin(); h != health.end(); h++) {
      if (*h > 0) {
        int pos = h - health.begin() + 1;
        cout << ' ' << pos;
      }
    }

    cout << "\n";
  }

  return 0;
}
