Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.


Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2

**********************************
//dfs

class Solution
{
    private:
    void dfs(int start,bool visited[],stack<int>&s,vector<int> adj[]){
        visited[start]=true;
        for(auto it:adj[start]){
            if(!visited[it]){
                dfs(it,visited,s,adj);
            }
        }
        s.push(start);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>v;
	    stack<int>s;
	    bool visited[V]={false};
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i,visited,s,adj);
	        }
	    }
	    while(!s.empty()){
	        v.push_back(s.top());
	        s.pop();
	    }
	    return v;
	}
};
***************************************

//Kahn's Algo(BFS)

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>v;
	    queue<int>q;
	    int inorder[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            inorder[it]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(inorder[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int front=q.front();
	        q.pop();
	        v.push_back(front);
	        for(auto it:adj[front]){
	            inorder[it]--;
	            if(inorder[it]==0)q.push(it);
	        }
	        
	    }
	    return v;
	}
};
