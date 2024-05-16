class Solution {
    private int[][] man_dis = new int[400][400];
    private int[][] safe_path = new int[400][400];
    private int[] dx = new int[] {0, 0, -1, 1};
    private int[] dy = new int[] { -1, 1, 0, 0};
    private int n, ans = 0;
    List<List<Integer>> thieves = new ArrayList<>();

    private boolean valid(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    void bfs(List<List<Integer>> grid) {
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                man_dis[i][j] = 1000000000;
                safe_path[i][j] = -1;
                if (grid.get(i).get(j) == 1) {
                    q.add(new int[] {i, j});
                    man_dis[i][j] = 0;
                }
            }
        }
        while (!q.isEmpty()) {
            int x = q.peek()[0], y = q.peek()[1];
            int cur_dis = man_dis[x][y];
            q.poll();
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i], ty = dy[i] + y;
                if (valid(tx, ty) && man_dis[tx][ty] > 1 + cur_dis) {
                    man_dis[tx][ty] = 1 + cur_dis;
                    q.add(new int[] {tx, ty});
                }
            }
        }
    }
    private int Dijkstra() {
        Comparator<int[]> comparator = (a, b) -> Integer.compare(b[0], a[0]);
        PriorityQueue<int[]> q = new PriorityQueue<>(comparator);
        q.add(new int[] {man_dis[0][0], 0, 0});
        safe_path[0][0] = man_dis[0][0];

        int res = safe_path[0][0];
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int safeness = cur[0];
            int x = cur[1], y = cur[2];
            if (x == n - 1 && y == n - 1) {
                res = safeness;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int tx = dx[i] + x, ty = dy[i] + y;
                if (valid(tx, ty) && safe_path[tx][ty] == -1) {
                    safe_path[tx][ty] = Math.min(man_dis[tx][ty], safeness);
                    q.add(new int[] {safe_path[tx][ty], tx, ty});
                }
            }
        }
        return res;
    }

    public int maximumSafenessFactor(List<List<Integer>> grid) {
        n = grid.size();
        bfs(grid);
        return Dijkstra();
    }
}