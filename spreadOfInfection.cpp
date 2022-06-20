#include <iostream>
#include <vector>
#include <queue>

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

class Pair{
  public:
  int v;
  int t;
  Pair(int v , int t){
    this->v = v;
    this->t = t;
  }
};


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
  int src,t; 
  cin >> src;
  cin >> t; 
    
  vector<int> visited(vtces , 0);

  queue<Pair> q;
  q.push(Pair(src , 1));
  int count = 0;
  while(q.size() > 0) {
    Pair rem = q.front();
    q.pop(); // remove

    if(visited[rem.v]  > 0) {
      continue;
    }

    if(rem.t > t) {
      break;
    }

    visited[rem.v] = rem.t; // mark
    count++;

    for(Edge edge : graph[rem.v]){
      if(visited[edge.nbr] == 0){
        q.push(Pair(edge.nbr , rem.t + 1));
      }
    }
  }
  cout << count << endl;

 
  return 0;
}