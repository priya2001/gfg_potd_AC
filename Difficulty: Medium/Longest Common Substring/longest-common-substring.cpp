//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string S1, string S2) {
        // your code here
        int n=S1.size();
        int m=S2.size();
        int answer=0;
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                curr[j]=S1[i-1]==S2[j-1]?1+prev[j-1]:0;
                answer=max(answer,curr[j]);
            }
            prev=curr;
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends