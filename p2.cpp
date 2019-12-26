#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main() {
  int total = 0;
  double a[1005];
  memset(a, 0, sizeof(a));
  
  int num, e, max;
  double coe;
  max = 0;
  cin >> num;
  //cout << num << endl;
  for(int i = 0; i < num; i++) {
    cin >> e;
    cin >> a[e];
    max = max > e ? max : e;
  }
  total = num;
  cin >> num;
  //cout << num << endl;
  for(int i = 0; i < num; i++) {
    cin >> e >> coe;
    if(a[e] == 0) {
      a[e] = coe;
      total++;
    } else {
      a[e] += coe;
      if(a[e] == 0) {
      	total--;
      }
    }
    max = max > e ? max : e;
  }

  cout << total;
  for(int i = max; i >= 0; i--) {
    if(a[i] != 0) {
      //cout << " " << i << " " << a[i];
      printf(" %d %.1lf", i, a[i]);
    }
  }
  cout << endl;
    
  
  return 0;
}
