//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    bool isPossible(int arr[],int mid,int m,int n)
    {
        int sum=0;
        int count=1;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(sum>mid)
            {
                count++;
                sum=arr[i];
            }
            
        }
        if(count<=m)
        {
            return true;
        }
        return false;
    }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n)return -1;
        int ans=-1;
        int maxCapacity=0;
        for(int i=0;i<n;i++)
        {
            maxCapacity+=arr[i];
        }
        int l=*max_element(arr,arr+n);
        int r=maxCapacity;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isPossible(arr,mid,m,n))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
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
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends