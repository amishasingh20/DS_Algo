/*
All anagrams entries are lower case.
Approach:
1. use noraml sorting techique to sort strings add to map and return the vector
Using Normal Stl Sort [n∗k∗logk]
*/
vector<vector<string>> groupAnagrams(vector<string>& str) {

    map<string,vector<string>>mp;
    int k=0;
    for(auto x:str){
        string s=x;
        sort(begin(s),end(s));
        mp[s].push_back(x);
    }
    vector<vector<string>>res;
    for(auto x:mp)
        res.push_back(x.second);

    return res;
}

/*2. Use counting sort
Complexity
Time complexity:O(n*k) --> count sort is O(n) and we sort k string sp O(k.n)
Space complexity:O(n*k)
*/
class Solution {
public:
    void  count_sort(string& s){
        int n = s.length();
        vector<int>freq(26,0);
        string ans;
        for(int i = 0; i<n; i++){
            freq[s[i]-'a']++;
        }
        for(int i = 0; i<26; i++){
            /*string (size_t n, char c);
            fill constructor
            Fills the string with n consecutive copies of character c.
            eg, if tatee is the string then freq[t] = 2 and freq[e]=2
            these need to be added twice in sorted string ans = aeet
            */
            ans.append(freq[i],i+'a');
        }
        s=ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> result;
        for(auto x : strs){
            string s = x;
            count_sort(s);
            mp[s].push_back(x);
        }
        for(auto x: mp){
            result.push_back(x.second);
        }
        return result;
    }
};