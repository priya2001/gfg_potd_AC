//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int firstOccurrences(int arr[], int n , int x)
    {
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        int ans=-1;
        while(start<=end)
        {
            if(arr[mid]==x)
            {
               ans=mid;
               end=mid-1;
            }
            else if(arr[mid]<x)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
     int lastOccurrences(int arr[], int n , int x)
    {
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        int ans=-1;
        while(start<=end)
        {
            if(arr[mid]==x)
            {
               ans=mid;
               start=mid+1;
            }
            else if(arr[mid]<x)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
    
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first=firstOccurrences(arr,n,x);
        int last=lastOccurrences(arr,n,x);
        return {first,last};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends