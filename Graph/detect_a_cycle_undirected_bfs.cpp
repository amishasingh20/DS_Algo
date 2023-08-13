/*
Output:  0

Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.

Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool detect(int node, vector<int> adj[], int vis[]){
        vis[node] = 1;
        queue<pair<int,int>> q;
        q.push({node, -1});
        while(!q.empty()){
            int n = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjnode: adj[n]) {
                if(!vis[adjnode]){
                    q.push({adjnode,n});
                    vis[adjnode] = 1;
                } else if(vis[adjnode]){
                    if(adjnode!=parent){
                        return true;
                    }
                }
            }
        }

        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]){
        int vis[V] ={0};
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(detect(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> adj[4] = {{}, {2}, {1,3}, {2}};

    Solution obj;
    auto ans = obj.isCycle(4,adj);
    cout << ans << endl;
    return 0;
}