//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        map<int,int> mp;
        int s = 0, cnt = 0;
        for(auto &ch:str)
        {
            if(ch!= ' ')
            {
                mp[ch-'a']++;
                s++;
            }
        }
        
        for(int i=0; i<26; i++)
        {
            if(mp[i]==0)
            {
                cnt++;
            }
        }
        
        return (cnt<=k) && s>=26;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends