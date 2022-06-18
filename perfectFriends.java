import java.io.*;
import java.util.*;

public class perfectFriends {

  static class Edge{
    int v ;
    int n;
    Edge(int v ,int n){
      this.v = v;
      this.n = n;
    }
  }

  public static void drawTreeAndGetComponents(ArrayList<Edge>[] graph , int src , boolean[] visited , ArrayList<Integer> comp){
    visited[src] = true;
    comp.add(src);
    for(Edge edge : graph[src]){
      if(visited[edge.n] == false){
        drawTreeAndGetComponents(graph , edge.n , visited , comp);
      }
    }
  }
   

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int n = Integer.parseInt(br.readLine()); // No. of vertices
      int k = Integer.parseInt(br.readLine()); // No. of edges

      ArrayList<Edge>[] graph = new ArrayList[n];
      for(int i = 0 ; i < n ; i++){
        graph[i] = new ArrayList<>();
      }

      boolean[] visited = new boolean[n];

      for(int e = 0 ; e < k ; e++){
        String line = br.readLine();
        String edges[] = line.split(" ");
        int v1 = Integer.parseInt(edges[0]);
        int v2 = Integer.parseInt(edges[1]);

        graph[v1].add(new Edge(v1 , v2));
        graph[v2].add(new Edge(v2 , v1));
      }
      
      ArrayList<ArrayList<Integer>> comps = new ArrayList<>();

      for(int v = 0 ; v < n ; v++){
        if(visited[v] == false){
          ArrayList<Integer> comp = new ArrayList<>();
          drawTreeAndGetComponents(graph ,  v , visited , comp);
          comps.add(comp);
        }
      }
      int count = 0;
      for(int i = 0 ; i < comps.size() ; i++){
        for(int j = i + 1 ; j < comps.size() ; j++){
          count += comps.get(i).size() * comps.get(j).size();
        }
      }
      System.out.println(count);


   }

}