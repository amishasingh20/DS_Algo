/*
Output:

2 2 2
2 2 0 
2 0 1
Time Complexity: O(NxM + NxMx4) ~ O(N x M)

For the worst case, all of the pixels will have the same colour, so DFS function will be called for (N x M) nodes and for every node we are traversing for 4 neighbours, so it will take O(N x M x 4) time.

Space Complexity: O(N x M) + O(N x M)

O(N x M) for copied input array and recursive stack space takes up N x M locations at max. 
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int initColor, int newColor, int delrow[], int delcol[]){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && nrow < n && ncol>=0 && ncol < m && image[nrow][ncol] == initColor && ans[nrow][ncol]!=newColor){
               dfs(nrow, ncol, image, ans,initColor, newColor, delrow,delcol);
            } 
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor){
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        dfs(sr,sc,image,ans,initColor, newColor, delrow, delcol);
        return ans;
    }
};

int main() {
    vector<vector<int>> image{
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    Solution obj;
    auto ans = obj.floodFill(image, 1,1,2);
    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        }
        cout<<"\n";
    }

    return 0;
}