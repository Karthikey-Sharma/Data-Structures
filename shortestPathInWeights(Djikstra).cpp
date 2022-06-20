#include<bits/stdc++.h>
using namespace std;

class Edge
{  
public:
  int src = 0; 
  int nbr = 0;
  int wt = 0;

  Edge(int src, int nbr, int wt)
  {
    this->src = src; 
    this->nbr = nbr;
    this->wt = wt;
  }
};

class Pair {
   public:
   int v;
   string psf;
   int wsf;

   Pair(int v , string psf , int wsf) {
      this->v = v;
      this->psf = psf;
      this->wsf = wsf;
   }
};

struct comp{
   public:
   bool operator()(Pair a , Pair b){
      return a.wsf >= b.wsf;
   }
};
 
 

int main() {                                                                            
 
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  

  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin >> u >> v >> w; 
 
    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));

  } 
  int src;  
  cin >> src;  
    
  vector<bool>visited(vtces , false);

  priority_queue<Pair , vector<Pair>  ,  comp> pq;
  pq.push(Pair(src , to_string(src) + "" , 0));

  while(pq.size() > 0){
     Pair rem = pq.top();
     pq.pop();

     if(visited[rem.v] == true){
        continue;
     }
     visited[rem.v] = true;

     cout << rem.v << " via "<< rem.psf << " @ " << rem.wsf << endl;

     for(Edge edge : graph[rem.v]){
        if(visited[edge.nbr] == false){
           pq.push(Pair(edge.nbr , rem.psf + to_string(edge.nbr) , rem.wsf + edge.wt));
        }
     }


  }

  
  
  return 0;
}