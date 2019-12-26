/*  Problem:     1005 Spell It Right
 *  Date:        08/04/2019
 *  Author:      Chen
 *  Description: Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.
 */

#include<iostream>
#include<cstring>
using namespace std;

int main() {
  //definition
  string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  string input;
  int ans = 0;
  int ans_sqe[3];
  int ans_len = 0;
  cin >> input;
  
  //process
  for(int i = 0; i < input.length(); i++) {
    ans += input[i] - '0';
  }
  while(ans > 0) {
    ans_sqe[ans_len] = ans % 10;
    ans_len++;
    ans /= 10;
  }

  //output
  for(int i = ans_len - 1; i > 0; i--) {
    cout << num[ans_sqe[i]] << " ";
  }
  cout << num[ans_sqe[0]] << endl;

  return 0;
}
