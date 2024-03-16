// most of this code was copied from solutions pdf
// could do do the second part (with large canvas size)
// want to study and play, likely wont submit yet

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

struct rect {
  int x1, y1, x2, y2;
  char color;
};

int lower_idx(std::vector<int> *vec, int val) {
  return lower_bound(vec->begin(), vec->end(), val) - vec->begin();
}

int main() {
  int height, width, n;
  std::cin >> height >> width >> n;

  std::vector<rect> rectangles;
  std::vector<int> col, row;

  for (int i = 0; i < n; i++) {
    int centre_x, centre_y, spread;
    char color;
    std::cin >> centre_x >> centre_y >> spread >> color;

    // upper left corner
    int x1 = std::max(0, centre_x - spread);
    int y1 = std::max(0, centre_y - spread);

    // bottom right corner
    int x2 = std::min(width, centre_x + spread + 1);
    int y2 = std::min(height, centre_y + spread + 1);

    rect rectangle = {
        .x1 = x1,
        .y1 = y1,
        .x2 = x2,
        .y2 = y2,
        .color = color,
    };

    // add for processing
    rectangles.push_back(rectangle);
    col.push_back(x1);
    col.push_back(x2);
    row.push_back(y1);
    row.push_back(y2);
  }

  // sort non descending
  std::sort(col.begin(), col.end());
  std::sort(row.begin(), row.end());

  // deduplicate
  col.erase(std::unique(col.begin(), col.end()), col.end());
  row.erase(std::unique(row.begin(), row.end()), row.end());

  // compressed canvas
  // see https://stackoverflow.com/questions/29528935/coordinate-compression
  char canvas[100][100];

  // color canvas
  for (rect r : rectangles) {
    for (int y = lower_idx(&row, r.y1); y < lower_idx(&row, r.y2); y++) {
      for (int x = lower_idx(&col, r.x1); x < lower_idx(&col, r.x2); x++) {
        canvas[y][x] = r.color;
      }
    }
  }

  char color;
  std::cin >> color;

  // count color occurences in canvas
  long long count = 0;
  for (std::size_t y = 0; y < row.size() - 1; y++) {
    for (std::size_t x = 0; x < col.size() - 1; x++) {
      if (canvas[y][x] == color) {
        long long rows = row[y + 1] - row[y];
        long long columns = col[x + 1] - col[x];
        count += rows * columns;
      }
    }
  }

  std::cout << count << '\n';
}
