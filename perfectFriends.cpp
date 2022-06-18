#include<bits/stdc++.h>
using namespace std;
class Edge {
  public:
    int src;
    int nbr;
    Edge(int src, int nbr){
      this->src = src;
      this->nbr = nbr;
    }
};

   void drawTreeAndCreateComponents(vector<Edge> graph[] , int src , vector<bool> &visited , vector<int> &comp){
      visited[src] = true;
      comp.push_back(src);
      for(Edge edge : graph[src]){
         if(visited[edge.nbr] == false){
            drawTreeAndCreateComponents(graph , edge.nbr , visited , comp);
         }
      }
   }
   
   int main(){
      int vtces;
      cin>>vtces;
      vector<Edge>graph[vtces];

      int edges;
      cin>>edges;
      for(int i = 0; i < edges; i++){
         int v1 ;
         int v2 ;
         cin>>v1>>v2;
         graph[v1].push_back( Edge(v1, v2));
         graph[v2].push_back( Edge(v2, v1));
      }
      
      vector<bool> visited(vtces , false);
      vector<vector<int>> comps;


      for(int v = 0 ; v < vtces ; v++){
        if(visited[v] == false){
            vector<int> comp;
            drawTreeAndCreateComponents(graph , v , visited , comp);
            comps.push_back(comp);
        }
      }
      int count = 0;
      for(int i = 0 ; i < comps.size() ; i++){
        for(int j = i + 1 ; j < comps.size() ; j++){
          count += comps[i].size() * comps[j].size();
        }
      }
      cout << count << endl;
    }