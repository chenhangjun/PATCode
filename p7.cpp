/*  Problem:     1007 Maximum Subsequence Sum
 *  Date:        08/04/2019
 *  Author:      Chen
 *  Description: Maximum Subsequence Sum  
 */

#include<iostream>
using namespace std;

int main() {
  //definition
  int k, sqe[10005];
  int max, fir, las, max_temp, fir_temp, las_temp;
  int non_flag = 1;
  //input
  cin >> k;
  for(int i = 0; i < k; i++) {
    cin >> sqe[i];
    if(sqe[i] >= 0) {
      non_flag = 0;   // not all negative
    }
  }
  //process
  max = max_temp = 0;
  fir = fir_temp = las = las_temp = 0;
  for(int i = 0; i < k; i++) {
    if(sqe[i] > 0) {
      max_temp += sqe[i];
      las_temp = i;
    } else if(sqe[i] == 0) {
      if(max_temp > max) {
        max = max_temp;
        fir = fir_temp;
        las = las_temp;
      }
      max_temp += sqe[i];
      las_temp = i;
      if(max ==0 && fir == 0 && las == 0) {
        fir = las = i;
      }
    } else {
      if(max_temp > max) {
        max = max_temp;
        fir = fir_temp;
        las = las_temp;
      } 
      if(max_temp + sqe[i] >= 0) {
        max_temp += sqe[i];
        las_temp = i;
      } else {
        max_temp = 0;
        fir_temp = i + 1;
      }
    }
  }
  if(max_temp > max) {
    max = max_temp;
    fir = fir_temp;
    las = las_temp;
  }

  //output
  if(non_flag == 1) {
    cout << 0 << " " << sqe[0] << " " << sqe[k - 1] << endl;
  } else {
    cout << max << " " << sqe[fir] << " " << sqe[las] << endl;
  }

  return 0;
}




