import java.io.*;
import java.util.*;


public class Solution {

    static class TreeDP {
          int n;
        int[] nodeValue;
        List<List<Integer>> adj;
        int[][] dp;
        boolean[] visited;
        
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int Q = Integer.parseInt(br.readLine().trim());

        TreeDP solver = new TreeDP(100000);
        int t = 1;

        for (int i = 0; i < Q; i++)
        {
            String[] input = br.readLine().trim().split(" ");
            char op = input[0].charAt(0);
        }
    
        for (int i = 0; i < Q; i++) {
        String[] input = br.readLine().trim().split(" ");
        char op = input[0].charAt(0);
        
        switch (op) {
            case 'A': {
                int a = Integer.parseInt(input[1]);
                solver.nodeValue[t++] = a;
                break;
            }
            case 'B': {
                int a = Integer.parseInt(input[1]);
                int b = Integer.parseInt(input[2]);
                solver.adj.get(a).add(b);
                solver.adj.get(b).add(a);
                break;
            }
            case 'C': {
                int a = Integer.parseInt(input[1]);
                solver.dfs(a, a);
                solver.nodeValue[t++] = Math.max(solver.dp[a][0], solver.dp[a][1]);
                break;
            }
        }
        }
    
    }
}
