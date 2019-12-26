#include<iostream>
#include<cstring>
using namespace std;

const int MAX_V = 505;
int cost[MAX_V][MAX_V];  //neighbor-Matrix
int d[MAX_V]; // min distance from the source point
int used[MAX_V];  //wether the point has been used/joined
int V;   //number of cities
int teams[MAX_V];  //number of teams of each city
int max_team[MAX_V]; // max number of teams available long the way
int num_way[MAX_V]; //number of paths

void Dijkstra(int s) {
	//source point
  d[s] = 0; //distance to the source point inself
  num_way[s] = 1; //1 path there
  max_team[s] = teams[s];  //max number of team can gather is the number of itself's
  used[s] = 1;  //been used
  for(int i = 0; i < V; i++) {
    if(i == s) {
      continue;  //skip
    }
    if(cost[s][i] != -1) {   //points directly connected with the source point
      d[i] = cost[s][i];   //min distance to the city so far
      max_team[i] = teams[i] + teams[s];
      num_way[i] = 1;
    }
  }
  while(true) {
    int v = -1;
    //pick a point not been used, can be reached so far through the used points, and with min distance
    for(int i = 0; i < V; i++) {
      if(!used[i] && d[i] != -1 && (v == -1 || d[i] < d[v])) {
        v = i;
      }
    }
    //if no such a point(city)
    if(v == -1) {
      break;
    }
    //find such a point
    used[v] = 1;

    for(int i = 0; i < V; i++) {
      if(i == v) {  //skip
        continue;
      }
      if(cost[v][i] != -1) {  //point directly connected with the picked point(v)
      	//points unreachable before or the path can be shorter through the point v
        if(d[i] == -1 || d[v] + cost[v][i] < d[i]) {  
          d[i] = d[v] + cost[v][i];
          max_team[i] = max_team[v] + teams[i];
          num_way[i] = num_way[v];
        }
        //distance of the path-- source-v-i is the same with other path-- source-?-i 
        else if (d[v] + cost[v][i] == d[i]) {
          if(max_team[v] + teams[i] > max_team[i]) {
            max_team[i] = max_team[v] + teams[i];
          }
          num_way[i] += num_way[v];
        }
      }
    }
    
  }

}

int main() {
  //initiate
  memset(cost, -1, sizeof(cost));
  memset(d, -1, sizeof(d));
  memset(max_team, 0, sizeof(max_team));
  memset(num_way, 0, sizeof(num_way));

  //definition
  int M, C1, C2;
  //input
  cin >> V >> M >> C1 >> C2;
  for(int i = 0; i < V; i++) {
    cin >> teams[i];
  }
  int c1, c2, l;
  for(int i = 0; i < M; i++) {
    cin >> c1 >> c2 >> l;
    cost[c1][c2] = l;
    cost[c2][c1] = l;
  }

	//solve
  Dijkstra(C1);
  //output
  cout << num_way[C2] << " " << max_team[C2] << endl;

  return 0;
}
