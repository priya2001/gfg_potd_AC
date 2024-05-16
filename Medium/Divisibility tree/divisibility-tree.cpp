//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:

    int components  = 0 ; 

    int  dfs( int src, vector<bool>&visited, vector< int> graph[]  )
    {
         visited[ src] = true;
         int count = 1 ;
         for ( auto adj  : graph [ src ] )
         {
            if ( visited[ adj]==  true )
                continue;
            int res = dfs( adj , visited, graph  );
            // cout << src << " -> " << res << endl;
            if( res %2 == 0 )
            {
                components ++;
            }
            else 
            {
                count += res ;
            }
         }
         return count;
    }
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    
	    vector< int > graph[ n +1 ];
        for ( auto it: edges )
        {
            graph[it[0]].push_back( it[1]);
            graph[it[1]].push_back ( it[0]);
        }
        vector< bool>visited( n + 1 , false ) ;
        dfs ( 1 , visited, graph );
        return components;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends