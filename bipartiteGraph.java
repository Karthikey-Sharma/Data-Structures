// If it is possible to divide vertices into 2 mutually exclusive and exhaustive 
//sets such that all edges are across sets
// Every Non-cyclic graph is bipartite
// if cycle is even-sized then it is bipartite

import java.io.*;
import java.util.*;

public class bipartiteGraph {
   static class Edge {
      int src;
      int nbr;
      int wt;

      Edge(int src, int nbr, int wt) {
         this.src = src;
         this.nbr = nbr;
         this.wt = wt;
      }
   }

   static class Pair {
     int v;
     String psf;
     int l; // level

     Pair(int v , String psf , int l){
       this.v = v;
       this.psf = psf;
       this.l = l;
     }
   }

   public static boolean checkComponentForBipartiteness(ArrayList<Edge>[] graph , int src ,int[] visited) {
    ArrayDeque<Pair> queue = new ArrayDeque<>();
    queue.push(new Pair(src , src + "" , 0));

    while(queue.size() > 0) {
      Pair rem = queue.remove(); // remove
      if(visited[rem.v] != -1) {
        if(rem.l != visited[rem.v]) { // this implies odd cycle
          return false;
        }
      }else {
        visited[rem.v] = rem.l; // mark
      }

      for(Edge edge : graph[rem.v]) {
        if(visited[edge.nbr] == -1) {
          queue.push(new Pair(edge.nbr , rem.psf + edge.nbr , rem.l + 1));
        }
      }
    }
    return true;
   }

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int vtces = Integer.parseInt(br.readLine());
      ArrayList<Edge>[] graph = new ArrayList[vtces];
      for (int i = 0; i < vtces; i++) {
         graph[i] = new ArrayList<>();
      }

      int edges = Integer.parseInt(br.readLine());
      for (int i = 0; i < edges; i++) {
         String[] parts = br.readLine().split(" ");
         int v1 = Integer.parseInt(parts[0]);
         int v2 = Integer.parseInt(parts[1]);
         int wt = Integer.parseInt(parts[2]);
         graph[v1].add(new Edge(v1, v2, wt));
         graph[v2].add(new Edge(v2, v1, wt));
      }

      int[] visited = new int[vtces]; // isme levels store karunga
      Arrays.fill(visited , -1);

      for(int i = 0 ; i < vtces ; i++){
        if(visited[i] == -1){
          boolean isCompBipartite = checkComponentForBipartiteness(graph , i , visited );
          if(isCompBipartite == false) { //  Ek bhi component agar bipartite nhi hua , to complete graph bipartite nhi hoga
            System.out.println(false); 
            return;
          }
        }
      }
      System.out.println(true);
   }
}