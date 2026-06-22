class Solution {
public:
    int maxNumberOfBalloons(string text) {
       unordered_map<char,int> frequency;
       for(char ch:text)
       {
        frequency[ch]++;
       }
       int b=frequency['b'];
       int a=frequency['a'];
       int l=frequency['l']/2;
       int o=frequency['o']/2;
       int n=frequency['n'];

       return min({b,a,l,n,o});
    }
};
