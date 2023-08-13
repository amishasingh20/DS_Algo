/*You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, 
starting with word1. If a string is longer than the other, append the additional letters onto the end 
of the merged string.
Return the merged string.*/
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0;
        while(i < word1.length() || i < word2.length()){
            if(i < word1.length()){
                ans+=word1[i];
            }
            if(i<word2.length()){
                ans+=word2[i];
            }
            i++;
        }
        return ans;
    }
};

int main(){
    string word1, word2;
    cout << "Enter the 2 string " << endl;
    cin >> word1;
    cin >> word2;

    Solution s;
    auto result = s.mergeAlternately(word1,word2);
    cout << " result is " << result << endl;

    return 0;

}