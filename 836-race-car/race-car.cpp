class Solution {
public:
    int racecar(int target) {
        queue<pair<int,int>> q;
        set<pair<int,int>> vis;
        q.push({0,1});
        vis.insert({0,1});
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> p = q.front();
                q.pop();
                int pos = p.first;
                int speed = p.second;
                if(pos == target) return steps;
                int newPos = pos + speed;
                int newSpeed = speed * 2;
                if(abs(newPos) <= 2 * target && vis.count({newPos,newSpeed}) == 0){
                    vis.insert({newPos,newSpeed});
                    q.push({newPos,newSpeed});
                }
                int revSpeed = speed > 0 ? -1 : 1;
                if(vis.count({pos,revSpeed}) == 0){
                    vis.insert({pos,revSpeed});
                    q.push({pos,revSpeed});
                }
            }
            steps++;
        }return -1;
    }
};