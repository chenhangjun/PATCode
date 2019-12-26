#include<iostream>
using namespace std;

int sqe[3][100];

int GetLevel(int node) {
  int level = 0;
  if(sqe[0][node] == 0) {
    return -1;
  } else {
    level++;
    while(sqe[0][node] != 1) {
      node = sqe[0][node];
      level++;
    }
    return level;
  }
}

int GetLeafNum(int level) {
  int ans = 0;
  for(int i = 0; i < 100; i++) {
    if(sqe[2][i] == level && sqe[1][i] == 0) {
      ans++;
    }
  }
  return ans;
}

int MaxLevel() {
  int level = -1;
  for(int i = 0; i < 100; i++) {
    if(sqe[2][i] > level) {
      level = sqe[2][i];
    }
  }
  return level;
}


int main() {
  int N, M, id, k, temp, maxLevel;
  /*
  int sqe[3][100];
  //init
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 100; j++) {
      sqe[i][j] = 0;
    }
  }
  */

  //input and prepare
  cin >> N >> M;
  if(N == 0) {
  } else {
    for(int i = 0; i < M ;i++) {
      cin >> id >> k;
      for(int j = 0; j < k; j++) {
        cin >> temp;
        sqe[0][temp] = id;
      }
      sqe[1][id] = 1;
    }
    //get its level
    for(int i = 0; i < 100; i++) {
      sqe[2][i] = GetLevel(i);
    }
    sqe[2][1] = 0;
    //solve
    //cout << sqe[0][2] << " " << sqe[1][2] << " " << sqe[2][2] << endl;
    int level = 0;
    maxLevel = MaxLevel();
    //cout << maxLevel << endl;
    int ans[100];
    while(level < maxLevel) {
      cout << GetLeafNum(level) << " ";
      level++;
    }
    cout << GetLeafNum(maxLevel) << endl;
  }


  return 0;
}
