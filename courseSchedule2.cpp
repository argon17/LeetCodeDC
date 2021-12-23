class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses);
        for(auto prerequisite : prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indeg[prerequisite[0]]++;
        }
        queue<int> nodes;
        for(int node = 0; node < numCourses; ++node){
            if(indeg[node] == 0) nodes.push(node);
        }
        vector<int> order;
        int visitedNodes = 0;
        while(nodes.size()){
            int cur = nodes.front();
            nodes.pop();
            ++visitedNodes;
            order.push_back(cur);
            for(auto nbr : adj[cur])
                if(--indeg[nbr] == 0)
                    nodes.push(nbr);
        }
        return visitedNodes == numCourses ? order : vector<int>();
    }
};