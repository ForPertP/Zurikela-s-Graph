using System;
using System.Collections.Generic;
using System.IO;

class TreeDP {
    public int n;
    public int[] nodeValue;
    public List<int>[] adj;
    public int[][] dp;
    public bool[] visited;

    public TreeDP(int size) {
        n = size;
        nodeValue = new int[size + 1];
        adj = new List<int>[size + 1];
        for (int i = 0; i <= size; i++) adj[i] = new List<int>();
        dp = new int[size + 1][];
        for (int i = 0; i <= size; i++) dp[i] = new int[2];
        visited = new bool[size + 1];
    }

    public void Dfs(int u, int parent) {
        visited[u] = true;
        dp[u][0] = 0;
        dp[u][1] = nodeValue[u];

        foreach (var v in adj[u]) {
            if (v == parent) continue;
            Dfs(v, u);
            dp[u][0] += Math.Max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
}
