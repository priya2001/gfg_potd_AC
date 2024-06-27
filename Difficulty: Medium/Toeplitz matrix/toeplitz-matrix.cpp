//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    // code here
    int rows = mat.size();
    int cols = mat[0].size();
    
    for(int i=0; i<rows-1; i++){
        for(int j=0; j<cols-1; j++){
            if(mat[i][j] != mat[i+1][j+1]){
                return false;
            }
        }
    }
    return true;
}