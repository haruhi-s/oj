#include <bits/stdc++.h>
using namespace std;


int findDuplicate(const vector<int>& v) {
  return 0;
}

int main() {
  int N;
  cin >> N;

  vector<int> v;
  for (int i = 0; i <= N; ++i) {
    int val;
    cin >> val;
    v.push_back(val);
  }

  cout << findDuplicate(v) << "\n";
  return 0;
}
