//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet
{

public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
          int n=grid.size();
        DisjointSet ds(n*n);
        // step1
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int dr[]={-1,0,1,0};
                    int cr[]={0,1,0,-1};
                    for(int x=0;x<4;x++){
                        int ni=i+dr[x];
                        int nj=j+cr[x];
                        
                        if(ni>=0 && nj>=0 && ni<n &&nj<n){
                            if(grid[ni][nj]==1){
                                int node_i=ni*n+nj;
                                int old_node=i*n+j;
                                ds.unionBySize(old_node,node_i);
                            }
                        }
                    }
                }
            }
        }
        // step2
        int ans=0;
        
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                if(grid[i][j]==0){
                    int dr[]={-1,0,1,0};
                    int cr[]={0,1,0,-1};
                    set<int> s;
                    for(int x=0;x<4;x++){
                        int ni=i+dr[x];
                        int nj=j+cr[x];
                        
                        if(ni>=0 && nj>=0 && ni<n &&nj<n){
                            if(grid[ni][nj]==1){
                                int node_i=ni*n+nj;
                                
                                s.insert(ds.findUPar(node_i));
                            }
                        }
                    }
                    int temp=1;
                    for(auto it:s){
                        temp+=ds.size[it];
                    }
                    ans=max(temp,ans);
                }
            }
        }
        if(ans==0){
            return n*n;
        }
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends