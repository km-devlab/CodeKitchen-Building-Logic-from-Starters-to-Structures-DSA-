class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        if(find(nums.begin(),nums.end(),k)==nums.end()) return k;

        auto max_value=max_element(nums.begin(),nums.end());
        int prod=1;
        for(int i=1;i<=*max_value;i++)
        {
            prod=k*i;
            if(find(nums.begin(),nums.end(),prod)==nums.end())
            {return prod;}
            else{
                continue;
            }
        }
        return *max_value+k;
}
};
