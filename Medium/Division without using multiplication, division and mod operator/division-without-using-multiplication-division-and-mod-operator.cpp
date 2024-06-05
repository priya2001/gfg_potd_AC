//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        
    /* if sign = 1 means +ve and 0 means -ve
     here if both the no. is -ve or +ve then they got cancelled otherwise they do not
       
       int sign = ((dividend < 0) ^ (divisor < 0)) ? 0 : 1;
    
       dividend = abs(dividend);
       divisor = abs(divisor);
    
       int quotient = 0;
    
       while(dividend >= divisor)
       {
             dividend -= divisor;
             quotient++;
       }
    
      if(sign) return quotient;
      else return -quotient;*/
      
    int sign = ((dividend < 0) ^ (divisor < 0)) ? 0 : 1;
    
    dividend = abs(dividend);
    divisor = abs(divisor);
    
    int quotient = 0;
    
    for(int i = 31; i >= 0; i--)
    {
        
        if(dividend >= (divisor << i))
        {
            dividend = dividend - (divisor << i);
            quotient = quotient | (1 << i);
        }
    }
    
    if(sign) return quotient;
    else return -quotient;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends