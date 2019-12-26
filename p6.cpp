/* Problem:     1006 Sign In and Sign Out
 * Date:        08/04/2019
 * Author:      Chen
 * Description: At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.
 */

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//struct to store the info of ID, sign_in_time and sign_out_time
struct Rec {
  string ID;
  string inTime;
  string outTime;
}recs[10000];

// sort according to cmp1 -- in an ascending order of inTime
bool cmp1(Rec A, Rec B) {
  int A_hh = (A.inTime[0] - '0') * 10 + (A.inTime[1]);
  int A_mm = (A.inTime[3] - '0') * 10 + (A.inTime[4]);
  int A_ss = (A.inTime[6] - '0') * 10 + (A.inTime[7]);
  int B_hh = (B.inTime[0] - '0') * 10 + (B.inTime[1]);
  int B_mm = (B.inTime[3] - '0') * 10 + (B.inTime[4]);
  int B_ss = (B.inTime[6] - '0') * 10 + (B.inTime[7]);
  if(A_hh == B_hh) {
  	if(A_mm == B_mm) {
  		return A_ss < B_ss;
  	}
  	return A_mm < B_mm;
  }
  return A_hh < B_hh;
}

// sort according to cmp2 -- in an descending order of outTime
bool cmp2(Rec A, Rec B) {
  int A_hh = (A.outTime[0] - '0') * 10 + (A.outTime[1]);
  int A_mm = (A.outTime[3] - '0') * 10 + (A.outTime[4]);
  int A_ss = (A.outTime[6] - '0') * 10 + (A.outTime[7]);
  int B_hh = (B.outTime[0] - '0') * 10 + (B.outTime[1]);
  int B_mm = (B.outTime[3] - '0') * 10 + (B.outTime[4]);
  int B_ss = (B.outTime[6] - '0') * 10 + (B.outTime[7]);
  if(A_hh == B_hh) {
  	if(A_mm == B_mm) {
  		return A_ss > B_ss;
  	}
  	return A_mm > B_mm;
  }
  return A_hh > B_hh;
}

int main() {
  int m;
  string s1, s2;   //output
  cin >> m;
  //input
  for(int i = 0; i < m; i++) {
    cin >> recs[i].ID >> recs[i].inTime >> recs[i].outTime;
  }

  sort(recs, recs + m, cmp1);
  s1 = recs[0].ID;
  
  sort(recs, recs + m, cmp2);
  s2 = recs[0].ID;

  cout << s1 << " " << s2 << endl;
  
  return 0;
}



