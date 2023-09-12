#include <unordered_map>
#include <set>
#include <string>

using namespace std;


// Optimized Solution
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> hashmap;

        for (auto& chr : s){
            if (hashmap.find(chr) != hashmap.end()) 
                hashmap[chr] += 1;

            else
                hashmap[chr] = 1;
        }

        set<int> unique_freq;
        int count = 0;

        for (auto& pair : hashmap){
            int freq = pair.second;

            while (unique_freq.find(freq) != unique_freq.end()){
                freq--;
                count++;
            }

            if (freq > 0) unique_freq.insert(freq);
        }

        return count;
    }
};