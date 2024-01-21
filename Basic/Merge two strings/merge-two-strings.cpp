//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends



string merge (string S1, string S2)
{
    // your code here
    int n=max(S1.size(),S2.size());
    string temp;
    for(int i=0;i<n;i++)
    {
        if(i<S1.size())
        {
            temp=temp+S1[i];
        }
        if(i<S2.size())
        {
            temp=temp+S2[i];
        }
    }
    return temp;
}