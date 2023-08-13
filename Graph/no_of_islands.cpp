/*
Output: 2

Time Complexity ~ O(N² + NxMx9), N² for the nested loops, and NxMx9 for the overall BFS of the matrix, that will happen throughout if all the cells are filled with 1.

Space Complexity: O(N²) for visited array max queue space O(N²), If all are marked as 1 then the maximum queue space will be N².
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int deltarow = -1; deltarow<=1; deltarow++){
                for(int deltacol = -1; deltacol<=1; deltacol++){
                    int nrow = row+deltarow;
                    int ncol = col + deltacol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid){
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector(m,0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<char>> input{
        {'0','1','1','1','0','0','0'},
        {'0','0','1','1','0','1','0'}
    };

    Solution obj;
    cout << obj.numIslands(input) << endl;
    return 0;
}