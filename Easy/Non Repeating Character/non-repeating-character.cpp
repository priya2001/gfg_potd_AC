//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       unordered_map<char,int>mp;
       char str;
       for(int i=0;i<S.size();i++)
       {
           mp[S[i]]++;
           
       }
       for(int i=0;i<S.size();i++)
       {
           for(auto it:mp)
           {
            if(S[i]==it.first)
            {
                if(it.second==1)
                {
                    str=S[i];
                    return str;
                }
            }
           }
       }
      return '$';
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends