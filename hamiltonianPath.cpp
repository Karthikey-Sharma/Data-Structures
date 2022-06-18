#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int nbr;
    int wt;

    Edge(int src , int nbr , int wt){
        this->src = src;
        this->wt = wt;
        this->nbr = nbr;
    }
};

void hamiltonian(vector<Edge> graph[] ,int vtces ,  int src , set<int>&visited , string psf , int osrc){

    if(visited.size() == vtces - 1){
        cout << psf ;
        bool closingEdgeFound = false;
        for(Edge edge : graph[src]){
            if(edge.nbr == osrc){
                closingEdgeFound = true;
            }
        }
        if(closingEdgeFound){
            cout << "*" << endl;
        }else{
            cout << "." << endl;
        }
        return;
    }

    visited.insert(src);
    for(Edge edge : graph[src]){
        if(visited.find(edge.nbr) == visited.end()){ // key not found
            hamiltonian(graph, vtces , edge.nbr , visited , psf + to_string(edge.nbr) , osrc);
        }
    }
    visited.erase(src);
}

int main() {
    int vtces;
    cin >> vtces;
    vector<Edge> graph[vtces];
    int e;
    cin >> e;
    for(int i = 0 ; i < e ; i++){
        int v1 , v2 , wt;
        cin >> v1 >> v2 >> wt;

        graph[v1].push_back(Edge(v1 , v2 , wt));
        graph[v2].push_back(Edge(v2 , v1 , wt));
    }
    int src;
    cin >> src;

    set<int> visited;
    hamiltonian(graph , vtces ,  src , visited , to_string(src) + "" , src);
    return 0;
}