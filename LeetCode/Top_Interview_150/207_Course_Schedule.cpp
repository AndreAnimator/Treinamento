class Solution {
public:
// Solution is not mine and its intended for educational purposes only
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // First create an adjency list for a directed graph, then use a DFS to search for cycles in the directed Graph.
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        // count indegrees for each node
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto it: adj[i])
                indegree[it]++;
        }
        // create a queue and push to the queue if it has indegree == 0
        vector<int> vis(numCourses);
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        // keep track of the size of topological sort
        int cnt = 0;
        while(!q.empty()){
            // take out front node
            int node = q.front();
            q.pop();
            cnt++;
            // takeout indegrees of all adjacent nodes and if its 0 push to queue
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return cnt == numCourses;
    }
};
