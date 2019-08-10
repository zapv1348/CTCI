#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

/**************************************************************************************************
 * Robot in a Grid
 * A robot starts in the top left corner of a c by r grid
 * it can only move right and down, some cells are blocked with a 'b'
 * figure out it's path to the bottom right.
 * Similar to leetcode 63
 ***********************************************************************************/
class RobotGrid {
private:

public: 
    /**********************************************************************
     * returns a sequence of r and d moves that will get
     * the robot to the bottom right cell
     * grid is a grid of the c by r course where 1 indicates an obstacle
     **********************************************************************/
    vector<char> roboRouting(vector<vector<int>>& grid) {
        // start by building up a map that tells you the number of ways
        // to get to a given spot on the grid. 0 indicates it is not
        // possible to get to that spot.
        auto x = grid.size();
        auto y = grid[0].size();
        auto sol = vector<vector<int>>(x+1, vector<int>(y+1,0));

        sol[0][1] = 1;
        for (auto i=1; i<=x; ++i) {
            for (auto j=1; j<=y; ++j) {
                if (!grid[i-1][j-1]) {
                    sol[i][j] = sol[i-1][j] + sol[i][j-1];
                }
            }
        }

        // now that we have that, start at the ending cell and just go to any cell that is non-zero.
        // Then at the end reverse the vector.
        // this part is equal to O(n+m)
        vector<char> ret;
        int m = x;
        int n = y;
        if (sol[m][n] == 0) return ret;
        while (n != 1 && m != 1) {
            if (sol[m-1][n] != 0) {
                --m;
                ret.push_back('r');
            } else if (sol[m][n-1] != 0) {
                --n;
                ret.push_back('d');
            } else {
                // ASSERT, EXCEPTION
                return vector<char>(1, 'a');
            }
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};
