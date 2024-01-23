//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int countSubstr (string S)
	{
	    // your code here
	    int ans=0;
	    int temp=0;
	    for(int i=0;i<S.length();i++)
	    {
	        if(S[i]=='1')
	        {
	           ans=ans+temp;
	           temp++;
	        }
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        
        cout << ob.countSubstr (s) << '\n';
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends