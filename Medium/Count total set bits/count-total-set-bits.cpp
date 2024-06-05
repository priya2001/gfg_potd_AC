//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int N)
    { 
         //tc :O(n)
         //sc :O(1)
        // int totalBits=0;
        // for(int i=1;i<=n;i++)
        // {
        //     int count1=0;
        //     int temp=i; // Store the original value of i
        //     while(temp!=0)
        //     {
        //         int lastDigit=temp&1;
        //         count1=count1+lastDigit;
        //         temp=temp>>1;
        //     }
        //     totalBits=totalBits+count1;
        // }
        // return totalBits;
        
         if (N == 0)
        return 0;

        int count = 0;
        for (int i = 0; (1 << i) <= N; i++)
        {
        int x = (N + 1) / (1 << (i + 1)) * (1 << i);  // Number of complete groups of size 2^i
        int y = max(0, (N + 1) % (1 << (i + 1)) - (1 << i));  // Number of bits in the incomplete group
        count += x + y;
    }
    return count;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends