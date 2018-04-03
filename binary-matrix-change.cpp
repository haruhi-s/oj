#include <bits/stdc++.h>

using namespace std;
int N, M;



int main() {
  cin >> N >> M;
  vector<vector<bool>> A(N, vector<bool>(M));
  vector<bool> row(N,1);
  vector<bool> col(M,1);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      bool cell;
      cin >> cell;
      A[i][j] = cell;
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(!A[i][j]){
        row[i]=0;
        col[j]=0;
      }
    }
  }

  for (int i = 0; i < N ; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << row[i]*col[j] << " ";
    }
    cout << "\n";
  }
}
