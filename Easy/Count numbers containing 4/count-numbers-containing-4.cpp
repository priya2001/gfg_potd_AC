//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   bool iscontain4(int x)
   {
       while(x!=0)
       {
           int r=x%10;
           if(r==4)
           {
               
               return true;
               
           }
           x=x/10;
       }
       return false;
   }
    int countNumberswith4(int n) {
        // code here
       int count=0;
       for(int i=1;i<=n;i++)
       {
            if(iscontain4(i))
            {
                count++;
            }
       }
       return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends