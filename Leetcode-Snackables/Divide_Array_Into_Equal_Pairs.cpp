class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> pairs;
        for(int x:nums)
        {
            pairs[x]++;
        }
        for(auto x:pairs)
        {
            if(x.second%2!=0)
            {
                return false;
            }
        }
        return true;
    }
};
