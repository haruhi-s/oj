#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
  return {l.first + r.first, l.second + r.second};
}

pii turn(pii face) {
  auto [i, j] = face;
  if (i == 1) return {0, -1};
  if (j == -1) return {-1, 0};
  if (i == -1) return {0, 1};
  return {1, 0};
}

int faceint(pii x) { return x.first * 2 + x.second + 2; }

bool inrange(pii pos, size_t size) {
  auto [i, j] = pos;
  if (i < 0 or i >= size) return false;
  if (j < 0 or j >= size) return false;
  return true;
}

int solve2(const auto& vs) {
  pii start{0, 0};
  for (int i = 0; i < vs.size(); ++i)
    for (int j = 0; j < vs[0].length(); ++j)
      if (vs[i][j] == '^') start = {i, j};

  set<pii> visited{};
  {
    pii pos = start;
    pii face{-1, 0};
    while (1) {
      pii next = pos + face;
      if (!inrange(next, vs.size())) break;
      if (vs[next.first][next.second] == '#') {
        face = turn(face);
        continue;
      }
      if (next != start) visited.emplace(next);
      pos = next;
    }
  }

  int sum = 0;
  array<array<array<int, 5>, 130>, 130> h;
  for (const auto& v : visited) {
    memset(&h, 0, sizeof(h));
    pii pos = start;
    pii face{-1, 0};
    while (1) {
      pii next = pos + face;
      if (!inrange(next, vs.size())) break;
      if (vs[next.first][next.second] == '#' or next == v) {
        face = turn(face);
        if (h[pos.first][pos.second][faceint(face)]) {
          ++sum;
          break;
        } else {
          h[pos.first][pos.second][faceint(face)] = 1;
        }
        continue;
      }

      pos = next;
    }
  }
  return sum;
}

int main() {
  ifstream file("day6.txt", ios::in);
  vector<string> vs;

  if (file.good()) {
    string str;
    while (getline(file, str)) vs.push_back(str);
  }

  cout << solve2(vs) << endl;
}
