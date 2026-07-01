class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        
        if(s==goal)
        {
            int count[26]={0};
            for(char ch:s)
            {
                count[ch-'a']++;
                if(count[ch-'a']>1) return true;
            }
            return false;
        }
        vector<int> diffIndex;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
            {
                diffIndex.push_back(i);
            }
        }
        if(diffIndex.size()!=2) return false;
        int i=diffIndex[0];
        int j=diffIndex[1];

        return (s[i]==goal[j] && s[j]==goal[i]);
        }
};
