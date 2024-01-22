//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int l= S.length();
         string str="", nstr="";
        for(int i=0; i<l; i++){
            if(S[i]!='.')
            str=str+S[i];
            else if(S[i]=='.'){
                nstr='.'+str+nstr;
                str="";
            }
        }
        nstr=str+nstr;
        return nstr;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends