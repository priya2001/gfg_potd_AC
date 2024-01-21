//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S)
{
    // your code here
    unordered_map<char,int>freq;
    for(int i=0;i<S.size();i++)
    {
        freq[S[i]]++;
    }
    int oddcount=0;
    for(auto i:freq)
    {
        if(i.second%2)
        {
            oddcount++;
        }
    }
    if(oddcount>1)
    {
        return 0;
    }
    return 1;
}