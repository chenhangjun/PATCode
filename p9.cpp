#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct poly {
  int exp;
  double coe;
}in1[11], in2[11], out[105], fin[25];

bool cmp(poly A, poly B) {
  return A.exp > B.exp;
}


int main() {
  int K1, K2;
  cin >> K1;
  for(int i = 0; i < K1; i++) {
    //first raw is exp, second raw is coeff;
    cin >> in1[i].exp >> in1[i].coe;
  }
  cin >> K2;
  for(int i = 0; i < K2; i++) {
    cin >> in2[i].exp >> in2[i].coe;
  }
  //calculate
  int k = 0;
  for(int i = 0; i < K1; i++) {
    for(int j = 0; j < K2; j++) {
      out[k].exp = in1[i].exp + in2[j].exp;
      out[k].coe = in1[i].coe * in2[j].coe;
      k++;
    }
  }
  sort(out, out + k, cmp);
  
  int cnt = 0;
  fin[0].exp = out[0].exp;
  fin[0].coe = out[0].coe;
  for(int i = 1; i < k; i++) {
    if(out[i].exp == out[i - 1].exp) {
      fin[cnt].coe += out[i].coe;
    } else {
      if(fin[cnt].coe != 0.0) {
        cnt++;
      }
      fin[cnt].exp = out[i].exp;
      fin[cnt].coe = out[i].coe;
    }
  }
  cnt++;
  //output
  cout << cnt << " ";
  for(int i = 0; i < cnt - 1; i++) {
    cout << fin[i].exp << " " << fixed << setprecision(1) << fin[i].coe << " ";
  }
  cout << fin[cnt - 1].exp << " " << fixed << setprecision(1) << fin[cnt - 1].coe << endl;

  return 0;
}

