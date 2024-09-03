//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
    #define ll long long 
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	  ll n=str1.length();
        ll m=str2.length();
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
          for(ll i=n;i>=0;i--){
                for(ll j=m;j>=0;j--){
                       
                      if(i==n &&  j==m){
                            dp[i][j]=0;
                      }
                      else if(i==n){
                             dp[i][j]=m-j;
                      }
                      else if(j==m){
                             dp[i][j]=n-i;
                      }
                      else if(str1[i]==str2[j]){
                              dp[i][j]=dp[i+1][j+1];
                      }
                      else {
                            ll op1=1+dp[i+1][j];
                            ll op2=1+dp[i][j+1];
                           
                            dp[i][j]=min(op1,op2);
                      }
                }
          }
          return dp[0][0];
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends