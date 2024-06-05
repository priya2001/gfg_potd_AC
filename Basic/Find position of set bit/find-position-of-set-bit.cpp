//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        if(N==0)
        {
            return -1;
        }
        int bit=N;
        int countBit=0;
        int pos=0;
        
        while(N>0)
        {
             N=N&(N-1);
             countBit++;
        }
        if(countBit>1)
       {
           return -1;
       }
        N=bit;
        while(N>0)
        {
            pos++;
            N>>=1;
        }
        return pos;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends