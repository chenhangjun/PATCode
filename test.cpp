#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int mem[10];

int Fibo(int n) {
  cout << n << " ";
  if( n <= 1) {
    return n;
  }
  if( mem[n] != 0 ) {
    return mem[n];
  }
  return mem[n] = Fibo(n - 1) + Fibo(n - 2);
}

int main() {
  int n;
  cin >> n;
  int ans = Fibo(n);
  cout << endl << ans << " " << mem[2] <<endl;
  return 0;
}
