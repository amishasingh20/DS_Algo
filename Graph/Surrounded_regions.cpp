
/*
https://takeuforward.org/graph/surrounded-regions-replace-os-with-xs/
Output:

X X X X
X X X X
X X X X
X X X X
X X O O

Time Complexity: O(N) + O(M) + O(NxMx4) ~ O(N x M), For the worst case, every element will be marked as ‘O’ in the matrix, and the DFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. Also, we are running loops for boundary elements so it will take O(N) + O(M).

Space Complexity ~ O(N x M), O(N x M) for the visited array, and auxiliary stack space takes up N x M locations at max. 
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    void dfs(int r, int c,vector<vector<char>>& mat, vector<vector<int>>& vis, int delrow[], int delcol[]){
        vis[r][c] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i<4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];
            if(nr>=0 && nr < n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc]=='O'){
                dfs(nr,nc,mat,vis,delrow,delcol);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat){
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        //if a O is travered through an edge/boundary then we can't mark it as X
        //First and last colums 
        for(int i = 0; i<n; i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,mat,vis,delrow,delcol);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,mat,vis,delrow,delcol);
            }
        }
        //first and the last row
        for(int i = 0; i<m; i++){
            if(!vis[0][i] && mat[0][i]=='O'){
                dfs(0,i,mat,vis,delrow,delcol);
            }
            if(!vis[n-1][i] && mat[n-1][i]=='O'){
                dfs(i,m-1,mat,vis,delrow,delcol);
            }
        }

        for(int i =0; i<n; i++){
            for(int j =0; j<m;j++){
                if(!vis[i][j]&&mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }

        return mat;
    }
};

int main(){
    vector<vector<char>> mat{
         {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };

    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}