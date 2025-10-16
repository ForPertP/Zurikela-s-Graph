import java.io.*;
import java.util.*;


public class Solution {

    static class TreeDP {
        int n;
        int[] nodeValue;
        List<List<Integer>> adj;
        int[][] dp;
        boolean[] visited;

        TreeDP(int size) {
            n = size;
            nodeValue = new int[size + 1];
            adj = new ArrayList<>(size + 1);
            for (int i = 0; i <= size; i++) {
                adj.add(new ArrayList<>());
            }
            dp = new int[size + 1][2];
            visited = new boolean[size + 1];
        }

        void dfs(int u, int parent) {
            visited[u] = true;
            dp[u][0] = 0;
            dp[u][1] = nodeValue[u];

            for (int v : adj.get(u)) {
                if (v == parent) continue;
                dfs(v, u);
                dp[u][0] += Math.max(dp[v][0], dp[v][1]);
                dp[u][1] += dp[v][0];
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int Q = Integer.parseInt(br.readLine().trim());

        TreeDP solver = new TreeDP(100000);
        int t = 1;

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

        int result = 0;
        for (int i = 1; i <= t; i++) {
            if (!solver.visited[i]) {
                solver.dfs(i, i);
                result += Math.max(solver.dp[i][0], solver.dp[i][1]);
            }
        }

        System.out.println(result);
    }
}
