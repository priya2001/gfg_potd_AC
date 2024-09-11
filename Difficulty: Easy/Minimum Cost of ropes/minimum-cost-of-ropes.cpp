//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<int,vector<int>,greater<int>>minH;
        long long cost=0;
        for(int i=0;i<arr.size();i++)
        {
            minH.push(arr[i]);
        }
        while(minH.size()>=2)
        {
            long long first=minH.top();
            minH.pop();
            long long second=minH.top();
            minH.pop();
            cost=cost+first+second;
            minH.push(first+second);
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends