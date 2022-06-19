// If it is possible to divide vertices into 2 mutually exclusive and exhaustive 
//sets such that all edges are across sets
// Every Non-cyclic graph is bipartite
// if cycle is even-sized then it is bipartite
#include <iostream>
#include <vector>
#include <queue>
#include<string>
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

class Pair {
  public:
  int v;
  int l;
  Pair(int v , int l){
    this->v = v;
    this->l = l;
  }
};

bool checkCompBipartiteness(vector<Edge> graph[] , int src , vector<int>& visited) {
  queue<Pair> q;
  q.push(Pair(src , 0));
  while(q.size() > 0) {
    Pair rem = q.front();
    q.pop(); // remove

    if(visited[rem.v] != -1){
      if(rem.l != visited[rem.v]){
        return false;
      }
    }else{
      visited[rem.v] = rem.l; // mark
    }

    for(Edge edge : graph[rem.v]){//add
      if(visited[edge.nbr] == -1){
        q.push(Pair(edge.nbr , rem.l + 1));
      }
    }


  }
  return true;
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
  
  vector<int> visited(vtces , -1); // for seeing the levels of nodes

  for(int v = 0 ; v < vtces ; v++){
    if(visited[v] == -1){
      bool isCompBipartite = checkCompBipartiteness(graph , v , visited);
      if(isCompBipartite == false){
        cout << "false" << endl;
        return 0;
      }
    }
  }
  cout << "true" << endl;

  return 0;
}