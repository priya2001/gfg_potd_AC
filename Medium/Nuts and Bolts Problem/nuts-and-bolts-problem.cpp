//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
    string s = "!#$%&*?@^";
    string a="",b="",c="";
        for(int i=0;i<n;i++)
        {
            a+=nuts[i];
            b+=bolts[i];
        }
        int x = 0;
        for(int i=0;i<s.size();i++)
        {
            if(a.find(s[i])!=string::npos)
            {
               c+=s[i];
                
            }
        }
         for(int i=0;i<n;i++)
        {
            nuts[i]=c[i];
            bolts[i]=c[i];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends