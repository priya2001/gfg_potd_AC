//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        // sort(arr,arr+n);
        // int count=0;
        // int start=0,end=n-1;
        // while(start<end)
        // {
        //     if(arr[start]+arr[end]==k)
        //     {
        //         count++;
        //         start++;
        //     }
        //     else if(arr[start]+arr[end]<k)
        //     {
        //         start++;
        //     }
        //     else
        //     {
        //         end--;
        //     }
        // }
        // return count;
        
        // #############################2nd method################################
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<n;i++)
        {
            int b=k-arr[i];
            if(mp[b])
            {
                count=count+mp[b];
            }
            mp[arr[i]]++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends