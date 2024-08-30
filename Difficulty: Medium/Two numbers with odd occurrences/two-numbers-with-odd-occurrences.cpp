//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long int>ans;
        long long int Xor=0;
        for(int i=0;i<N;i++)
        {
            Xor=Xor^Arr[i];
        }
        long long int rightmost=(Xor&(Xor-1))^Xor;
        long long int b1=0,b2=0;
        for(int i=0;i<N;i++)
        {
            if(Arr[i]&rightmost)
            {
                b1=b1^Arr[i];
            }
            else
            {
                b2=b2^Arr[i];
            }
        }
        ans.push_back(b1);
        ans.push_back(b2);
        sort(ans.begin(),ans.end(),greater<long long int>());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends