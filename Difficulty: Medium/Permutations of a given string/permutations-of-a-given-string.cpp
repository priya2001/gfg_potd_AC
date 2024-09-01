//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(string S,int i,set<string>&s)
	    {
	        if(i>=S.size())
	        {
	            s.insert(S);
	            
	            return;
	        }
	        for(int j=i;j<S.size();j++)
	        {
	            swap(S[i],S[j]);
	            solve(S,i+1,s);
	            //BACKTRACKING
	            swap(S[i],S[j]);
	           
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string>s;
		    vector<string>ans;
		    int index=0;
		    solve(S,index,s);
		    for(auto &it:s)
		    {
		        ans.push_back(it);
		    }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends