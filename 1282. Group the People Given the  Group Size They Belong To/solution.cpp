class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hashmap;
        vector<vector<int>> res;

        for (int i = 0; i < groupSizes.size(); i++){
            int key = groupSizes[i];
            if (hashmap.find(key) != hashmap.end()){
                hashmap[key].push_back(i);
            }
            else{
                hashmap[key] = {i};
            }
            if (hashmap[key].size() == key){
                res.push_back(hashmap[key]);
                hashmap.erase(key);
            }

        }


        return res;
        
    }
};