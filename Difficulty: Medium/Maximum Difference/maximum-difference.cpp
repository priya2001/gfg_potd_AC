//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        stack<int>st;
        vector<int>left(n,0),right(n,0);
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&st.top()>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                left[i]=st.top();
            }
            st.push(arr[i]);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                right[i]=st.top();
            }
            st.push(arr[i]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,abs(left[i]-right[i]));
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends