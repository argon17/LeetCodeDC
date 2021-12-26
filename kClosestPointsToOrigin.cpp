// NLOGK + K

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for(vector<int> &point : points){
            pq.push(point);
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
private:
    struct compare{
        bool operator()(vector<int> &p, vector<int> &q){
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};

// NLOGN

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](vector<int> &p, vector<int> &q){
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>> (points.begin(), points.begin() + k);
    }
};