class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> distro = vector<int>(size, 1);

        for (int i = 0; i < size; i++){
          if (i > 0 && ratings[i] > ratings[i - 1]){
            distro[i] = max(distro[i], distro[i - 1] + 1);
          }
        }

        for (int j = size - 1; j > -1; j--){
          if (j < size - 1 && ratings[j] > ratings[j + 1]){
            distro[j] = max(distro[j], distro[j + 1] + 1);
          }
        }

        return accumulate(distro.begin(), distro.end(), 0);
    }
};