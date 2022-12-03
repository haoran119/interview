/*
https://leetcode.com/problems/island-perimeter/
https://mp.weixin.qq.com/s/NcNCG6nzWgvPdDVz7vWrsA

对于一个陆地格子的每条边，它被算作岛屿的周长当且仅当这条边为网格的边界或者相邻的另一个格子为水域。因此，我们可以遍历每个陆地格子，看其四个方向是否为边界或者水域，
如果是，将这条边的贡献（即 1）加入答案 ans 中即可。

时间复杂度：O(nm)，其中 n 为网格的高度，m 为网格的宽度。我们需要遍历每个格子，每个格子要看其周围 4 个格子是否为岛屿，因此总时间复杂度为 O(4nm) = O(nm)。

空间复杂度：O(1)。只需要常数空间存放若干变量。
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const std::vector<int> dx{0, -1, 0, 1};
        const std::vector<int> dy{-1, 0, 1, 0};
        
        auto result{0};
        auto n_row{grid.size()}, n_col{grid.at(0).size()};
        
        for (auto i = 0; i < n_row; ++ i) {
            for (auto j = 0; j < n_col; ++ j) {
                if (grid.at(i).at(j) == 1) {
                    for (auto k = 0; k < 4; ++ k) {
                        auto x{i + dx.at(k)};
                        auto y{j + dy.at(k)};
                        if (x < 0 || x >= n_row || y < 0 || y >= n_col || 
                            (!grid.at(x).at(y))) {
                            result += 1;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};
