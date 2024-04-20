/*
LeetCode-POTD: 1992. Find All Groups of Farmland

POTD Link - https://leetcode.com/problems/find-all-groups-of-farmland/description/

Approach :
    1. find the left-most and right-most corner of farmland
    2. add it to the answer
    3. reset all farmland to forested
*/

import java.util.*;

class Solution
{
public
    int[][] findFarmland(int[][] land)
    {
        List<int[]> result = new ArrayList<>();

        int m = land.length;
        int n = land[0].length;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] == 1)
                {
                    int[] coordinates = findFarmlandCoords(land, i, j);
                    result.add(coordinates);
                }
            }
        }

        return result.toArray(new int[result.size()][]);
    }

private
    int[] findFarmlandCoords(int[][] land, int row, int col)
    {
        int[] coordinates = new int[4];
        coordinates[0] = row;
        coordinates[1] = col;

        int m = land.length;
        int n = land[0].length;

        int r = row;
        int c = col;

        // Finding the bottom-right corner of the farmland group
        while (r < m && land[r][col] == 1)
            r++;
        while (c < n && land[row][c] == 1)
            c++;
        coordinates[2] = r - 1;
        coordinates[3] = c - 1;

        for (int i = row; i < r; i++)
        {
            for (int j = col; j < c; j++)
            {
                land[i][j] = 0;
            }
        }

        return coordinates;
    }
}