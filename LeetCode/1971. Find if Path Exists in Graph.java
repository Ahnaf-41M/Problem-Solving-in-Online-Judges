class Solution {
    private int[] parent = new int[200001];
    private int[] rank = new int[200001];

    private int find_par(int cur) {
        if (parent[cur] == -1) return cur;
        return parent[cur] = find_par(parent[cur]);
    }

    private void union(int a, int b) {
        if (a == b)
            return;
        if (rank[a] > rank[b]) {
            parent[b] = a;
            rank[a] += rank[b];
        } else {
            parent[a] = b;
            rank[b] += rank[a];
        }
    }

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        int m = edges.length;
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            int x = find_par(edges[i][0]);
            int y = find_par(edges[i][1]);
            union(x, y);
        }
        return find_par(source) == find_par(destination);
    }
}