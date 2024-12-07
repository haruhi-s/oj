#include <bits/stdc++.h>

using namespace std;

array<array<int, 100>, 100> t;

bool cmp(int a, int b) { return t[a][b]; }

int solvefast(const auto& vv) {
  int sum = 0;
  for (auto& v : vv) {
    auto vs = v;
    sort(vs.begin(), vs.end(), cmp);
    if (v != vs) sum += vs[vs.size() / 2];
  }
  return sum;
}

int solve(const auto& in) {
  auto vv = in;
  int sum = 0;
  for (auto& v : vv) {
    bool sorted = 0;
    for (size_t i = 0; i < v.size(); ++i)
      for (size_t j = i; j < v.size(); ++j)
        if (t[v[j]][v[i]]) sorted = 1, swap(v[i], v[j]);
    if (sorted) sum += v[v.size() / 2];
  }
  return sum;
}

int main() {
  ifstream file("day5.in", ios::in);
  vector<vector<int>> vv;

  if (file.good()) {
    string str;
    bool seq = 0;
    while (getline(file, str)) {
      istringstream ss(str);
      int num;
      vector<int> v;
      while (ss >> num) v.push_back(num);
      if (not v.size()) seq = 1;
      if (not seq and v.size())
        t[v[0]][v[1]] = 1;
      else
        vv.push_back(v);
    }
  }

  int shit = 0;

  auto start = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < 1000; ++i) shit += solve(vv);
  auto finish = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() /
                   1'000'000
            << "ms" << endl;
  cout << shit << endl;
  return 0;
}
