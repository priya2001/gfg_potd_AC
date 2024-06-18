//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int diameter = r << 1;
        int diameterSquare = diameter * diameter;
        
        int rectanglesCount = 0;
        int left = 1;
        int right = diameter;
        
        while (left < diameter && right >= 1) {
            if ((left * left) + (right * right) <= diameterSquare) 
            {
                rectanglesCount += right;
                left++;
            } 
            else 
            {
                right--;
            }
        }
        return rectanglesCount;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends