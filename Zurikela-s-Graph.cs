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




class Solution {
    static string LTrim(string s) {
        return s.TrimStart();
    }

    static string RTrim(string s) {
        return s.TrimEnd();
    }

    static List<string> Split(string s) {
        var parts = new List<string>();
        foreach (var token in s.Split(' ', StringSplitOptions.RemoveEmptyEntries)) {
            parts.Add(token);
        }
        return parts;
    }

    static void Main(string[] args) {
        int Q = int.Parse(LTrim(RTrim(Console.ReadLine())));
        TreeDP solver = new TreeDP(100000);

        int t = 1;
        for (int i = 0; i < Q; i++) {
            string line = Console.ReadLine();
            var parts = Split(RTrim(line));
            char O = parts[0][0];

            switch (O) {
                case 'A': {
                    int a = int.Parse(parts[1]);
                    solver.nodeValue[t++] = a;
                    break;
                }
                case 'B': {
                    int a = int.Parse(parts[1]);
                    int b = int.Parse(parts[2]);
                    solver.adj[a].Add(b);
                    solver.adj[b].Add(a);
                    break;
                }
                case 'C': {
                    int a = int.Parse(parts[1]);
                    solver.Dfs(a, a);
                    solver.nodeValue[t++] = Math.Max(solver.dp[a][0], solver.dp[a][1]);
                    break;
                }
            }
        }

    }
}
