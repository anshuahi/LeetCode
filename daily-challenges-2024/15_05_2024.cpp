/*
LeetCode-POTD: 2812. Find the Safest Path in a Grid

POTD Link - https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/

Approach
    1. create safeness matrix(minimum distance from any thief) using dfs/bfs
    2. find the path with maximum safeness
*/

class Solution
{
public
    int maximumSafenessFactor(List<List<Integer>> grid)
    {
        int row = grid.size();
        int col = grid.get(0).size();

        if (grid.get(0).get(0) == 1 || grid.get(row - 1).get(col - 1) == 1)
        {
            return 0;
        }

        int[][] safeness = new int[row][col];
        for (int[] rowArr : safeness)
        {
            Arrays.fill(rowArr, -1);
        }

        Deque<int[]> q = new ArrayDeque<>();

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid.get(r).get(c) == 1)
                {
                    safeness[r][c] = 0;
                    q.offer(new int[]{0, r, c});
                }
            }
        }

        int[][] direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.isEmpty())
        {
            int[] current = q.poll();
            int dis = current[0], r = current[1], c = current[2];
            for (int[] dir : direction)
            {
                int nr = r + dir[0], nc = c + dir[1];
                if (0 <= nr && nr < row && 0 <= nc && nc < col && safeness[nr][nc] == -1)
                {
                    safeness[nr][nc] = dis + 1;
                    q.offer(new int[]{dis + 1, nr, nc});
                }
            }
        }

        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b)->b[0] - a[0]);
        heap.offer(new int[]{safeness[0][0], 0, 0});
        Set<String> seen = new HashSet<>();
        seen.add(0 + "," + 0);

        while (!heap.isEmpty())
        {
            int[] current = heap.poll();
            int dis = current[0], r = current[1], c = current[2];
            if (r == row - 1 && c == col - 1)
            {
                return dis;
            }

            for (int[] dir : direction)
            {
                int nr = r + dir[0], nc = c + dir[1];
                if (0 <= nr && nr < row && 0 <= nc && nc < col && !seen.contains(nr + "," + nc))
                {
                    int safe = Math.min(dis, safeness[nr][nc]);
                    heap.offer(new int[]{safe, nr, nc});
                    seen.add(nr + "," + nc);
                }
            }
        }

        return -1;
    }
}
