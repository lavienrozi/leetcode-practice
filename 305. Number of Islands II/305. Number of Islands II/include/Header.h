#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

template<typename T> void LOG(T x) { std::cout << x << std::endl; }


class Solution1 {
public:
    // X and Y vectors are used to iterate the neighbors of a cell
    std::vector<int> X = { -1, 1, 0, 0 };
    std::vector<int> Y = { 0, 0, -1, 1 };

    // root: will store the root (parent) for each connected component
    // ans:  will contain the result to be returned
    std::vector<int> root, ans;

    // find with path compression
    int find(int x) {
        return x == root[x] ? x : root[x] = find(root[x]);
    }

    std::vector<int> numIslands2(int m, int n, std::vector<std::vector<int>>& positions) {
        int N = positions.size(), islands = 0;

        // grid will store info if a cell (i, j) has land or not
        // it will be used to connect (union) neighboring cells later on
        std::vector<std::vector<bool>> grid(m, std::vector<bool>(n, 0));

        // we are going to serialize a 2d index into fit in a 1d array
        // the max value of the serialized 1d array is m * n
        root.resize(m * n + 2);

        // initialize array with its index
        std::iota(root.begin(), root.end(), 0);

        // checks if (i, j) is out of bounds
        auto valid = [&](int i, int j) {
            return (0 <= i and i < m and 0 <= j and j < n);
        };

        // serialize 2d index for 1d array
        auto index = [&](int x, int y) {
            return x * n + y;
        };

        for (auto& pos : positions) {
            int x = pos[0], y = pos[1];

            // if this check is not present, 
            // duplicate nodes will get added as separate islands
            if (grid[x][y]) {
                ans.push_back(islands);
                continue;
            }

            // increment number of island
            islands++;

            // iterate over the neighboring cells (xNext, yNext)
            for (int k = 0; k < 4; k++) {
                int xNext = x + X[k], yNext = y + Y[k];

                // if cell is out of bounds or land is not present, do nothing
                if (!valid(xNext, yNext) or !grid[xNext][yNext])
                    continue;

                // find the roots of cell and its neighbor
                int rootA = find(index(x, y));
                int rootB = find(index(xNext, yNext));

                // if roots are not same, islands will reduce on union
                if (rootA != rootB) {
                    root[rootB] = rootA;
                    islands--;
                }
            }

            // mark the cell, because it contains land
            grid[x][y] = 1;

            // update the ans with islands
            ans.push_back(islands);
        }

        return ans;
    }
};
