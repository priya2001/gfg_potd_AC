//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=-1,minDiff=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int left=i+1,right=n-1;
            int sum=0;
            while(left<right)
            {
                sum=arr[i]+arr[left]+arr[right];
                int currDiff=abs(sum-target);
                
                if(currDiff<minDiff)
                {
                    minDiff=currDiff;
                    ans=sum;
                }
                else if(currDiff==minDiff)
                {
                    
                    ans=max(ans,sum);
                }
                if(sum>target)
                {
                    right--;
                }
                else if(sum==target)
                {
                    return target;
                }
                else
                {
                    left++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends