#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;

  Edge(int src, int nbr)
  {
    this->src = src; 
    this->nbr = nbr;
  }
};

bool isCyclic(vector<Edge> graph[] , int src , vector<bool>visited){
  queue<int> q;
  q.push(src);

  while(q.size() > 0){
    int rem = q.front();
    q.pop();// remove
    if(visited[rem] == true){
      return true;
    }
    visited[rem] = true; // mark

    for(Edge edge : graph[rem]){ //add
      if(visited[edge.nbr] == false){
        q.push(edge.nbr);
      }
    }
  }

  return false;
}
  
  
int main() {                                                                        
  int vtces;
  cin >> vtces;
  vector<Edge> graph[vtces];
  
  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin >> u >> v >> w;
 
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));

  } 
 
  vector<bool> visited(vtces , false);
  for(int v = 0 ; v < vtces ; v++){
    if(visited[v] == false){
      bool cycle = isCyclic(graph , v , visited);
      if(cycle) {
        cout << "true" << endl;
        return 0;
      }
    }
  }
  cout << "false" << endl;
  return 0;
}