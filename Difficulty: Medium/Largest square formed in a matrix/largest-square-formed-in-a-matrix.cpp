//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
    
    if (n == 0 || m == 0) return 0;

    // Condition when there is only one row or one column
    if (n == 1 || m == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) return 1;
            }
        }
        return 0;
    }
    
    int maxSquare = 0;
    // Check the last row and update the maxSquare accordingly
    for (int i = 0; i < m; i++) {
        if (mat[n-1][i] == 1) {
            maxSquare = 1;
            break;
        }
    }
    // Check the last column and update the maxSquare accordingly
    for (int j = 0; j < n; j++) {
        if (mat[j][m-1] == 1) {
            maxSquare = 1;
            break;
        }
    }
    
    // Traversing the rest of the matrix from bottom-right to top-left
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            if (mat[i][j] == 0) continue;
            int minVal = min(mat[i][j+1], min(mat[i+1][j], mat[i+1][j+1])) + 1;
            mat[i][j] = minVal;
            maxSquare = max(maxSquare, minVal);
        }
    }
    
    return maxSquare;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends