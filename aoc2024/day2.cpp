#include <bits/stdc++.h>
#include <x86intrin.h>

using namespace std;

// int bigshit = 0;

bool // __attribute__((noinline))
safe(const auto& v) {
  // bigshit *= 2;
  bool inc = 0, dec = 0;
  for (size_t i = 0; i + 1 < v.size(); ++i) {
    int a = v[i];
    int b = v[i + 1];
    if (a < b) inc = 1;
    if (a > b) dec = 1;
    if (a == b) return false;
    if (inc and dec) return false;
    int c = a - b;
    if (c < -3 or c > 3) return false;
  }
  return true;
}

int64_t // __attribute__((noinline))
solve(const auto& vv) {
  int64_t sum = 0;
  for (const auto& v : vv)
    if (safe(v)) ++sum;
  return sum;
}

int main() {
  ifstream file("day2.txt", ios::in);
  vector<vector<int>> vv;

  if (file.good()) {
    string str;
    while (getline(file, str)) {
      istringstream ss(str);
      int num;
      vector<int> v;
      while (ss >> num) { v.push_back(num); }
      vv.push_back(v);
    }
  }

  int64_t shit = 0;

  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100000; ++i) shit += solve(vv);

  auto finish = std::chrono::high_resolution_clock::now();

  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() /
                   1'000'000
            << "ms\n";

  cout << shit << endl;
  return 0;
}
