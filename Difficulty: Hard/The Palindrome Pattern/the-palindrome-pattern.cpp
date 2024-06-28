//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
         int n=arr.size();
        // row wise
        for(int i=0;i<n;i++){
            vector<int>temp(arr[i].rbegin(),arr[i].rend());
            if(arr[i]==temp){
                return to_string(i)+" "+"R";
            }
        }
        // column wise
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(arr[j][i]);
            }
            
            vector<int>temp2(temp.rbegin(),temp.rend());
            if(temp2==temp){
                return to_string(i)+" "+"C";
            }
        }
        
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends