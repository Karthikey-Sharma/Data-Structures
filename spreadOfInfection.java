import java.io.*;
import java.util.*;

public class spreadOfInfection {
   static class Edge {
      int src;
      int nbr;

      Edge(int src, int nbr) {
         this.src = src;
         this.nbr = nbr;
      }
   }

    static class Pair{
      int v;
      int t;
      Pair(int v , int t) {
        this.v = v;
        this.t = t;
      }
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
         graph[v1].add(new Edge(v1, v2));
         graph[v2].add(new Edge(v2, v1));
      }

      int src = Integer.parseInt(br.readLine());
      int t = Integer.parseInt(br.readLine());
      
      int[] visited = new int[vtces]; // for storing time
      ArrayDeque<Pair> queue = new ArrayDeque<>();
      queue.add(new Pair(src , 1));
      int count = 0;
      while(queue.size() > 0) {
        Pair rem = queue.remove() ; /// remove

        if(visited[rem.v] > 0) {
          continue;
        }
        if(rem.t > t){
          break;
        }
        visited[rem.v] = rem.t; // mark
        count++;
        for(Edge edge : graph[rem.v]){ //ad
          if(visited[edge.nbr] == 0){
            queue.push(new Pair(edge.nbr , rem.t + 1));
          }
        }
      }
      System.out.println(count);

   }

}