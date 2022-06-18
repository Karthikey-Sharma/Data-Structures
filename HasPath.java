import java.io.*;
import java.util.*;

public class HasPath {
   static class Edge {
      int src;
      int nbr;
      int wt;

      Edge(int src, int nbr, int wt){
         this.src = src;
         this.nbr = nbr;
         this.wt = wt;
      }
   }

   public static boolean hasPath(ArrayList<Edge>[] graph , int src , int dest , boolean[] visited){
      if(src == dest) {
         return true;
      }

      visited[src] = true;

      for(Edge edge : graph[src]){
         if(visited[edge.nbr] != true){
            boolean hasNbrPath = hasPath(graph , edge.nbr , dest , visited);
            if(hasNbrPath == true){
               return true;
            }
         }
      }
      return false;
   }
   public static void main(String[] args) throws Exception {
      Scanner scn = new Scanner(System.in);
      int vtces = scn.nextInt();
      ArrayList<Edge>[] graph = new ArrayList[vtces];
      for(int i = 0 ; i < vtces ; i++){
         graph[i] = new ArrayList<>();
      }
      int edges = scn.nextInt();
      for(int i = 0 ; i < edges ; i++){
         int v1 = scn.nextInt();
         int v2 = scn.nextInt();
         int wt = scn.nextInt();
         graph[v1].add(new Edge(v1 , v2 , wt));
         graph[v2].add(new Edge(v2 , v1 , wt));
      }
      int src = scn.nextInt();
      int dest = scn.nextInt();
      // write your code here
      boolean[] visited = new boolean[vtces];
      boolean foundPath = hasPath(graph , src , dest , visited);
      if(foundPath){
         System.out.println("true");
      }else{
         System.out.println("false");
      }
    }

}