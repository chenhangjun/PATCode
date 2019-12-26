#include<iostream>
using namespace std;

int main() {
  int n, a[1000];
  cin >>n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = a[0] * 6;
  for(int i = 1; i < n; i++) {
    if(a[i] - a[i - 1] < 0) {
      ans += (a[i - 1] - a[i]) * 4;
    } else {
      ans += (a[i] - a[i - 1]) * 6;
    }
  }
  ans += 5 * n;

  cout << ans << endl;

  return 0;
}
