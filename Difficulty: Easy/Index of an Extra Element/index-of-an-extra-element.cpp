//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        int XOR=0;
        for(int i=0;i<n;i++)
        {
            XOR=XOR^arr1[i];
        }
        for(int i=0;i<n-1;i++)
        {
            XOR=XOR^arr2[i];
        }
        int extra_element=XOR;
        for(int i=0;i<n;i++)
        {
            if(arr1[i]==extra_element)
            {
                return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends