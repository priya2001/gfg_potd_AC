//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) 
    {
        // code here
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>> diff(n,vector<int>(m,1e9));
        diff[0][0]=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        int dr[]= {-1,0,1,0};
        int cr[]= {0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int curr_diff=diff[row][col];
            

            
            for(int i=0;i<4;i++)
            {
                int nrow=row+dr[i];
                int ncol=col+cr[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int new_diff=max(curr_diff,abs(heights[nrow][ncol]-heights[row][col]));
                    if(new_diff<diff[nrow][ncol])
                    {
                        diff[nrow][ncol]=new_diff;
                        q.push({nrow,ncol});
                    }
                }
            }
            
        }
        
        return diff[n-1][m-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends