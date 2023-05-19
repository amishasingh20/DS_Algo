/*
Approach
Use sliding window with hashset, use left and right pointers to move the window .
If the set doesn't contains character then first add into the set and calculate the maxLength hand-in-hand...
if character already present in the set that means you have to move your sliding window by 1 , before that you have to remove all the characters that are infront of the character that is present already in window before.
Now you have to remove that character also and move the left pointer and also add the new character into the set.
EASY APPROACH USING SIMPLE HASHSET+SLIDING WINDOW

Complexity
Time complexity: O(n)
Space complexity: O(k), where k is the number of distinctive characters prsent in the hashset.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> charSet;
        int l = 0, res = 0;
        for(int r = 0; r < s.length(); r++){
            while(charSet.find(s[r]) != charSet.end()){
                charSet.erase(s[l++]);
            }
            charSet.insert(s[r]);

            res = max(res,r-l+1);
        }

        return res;
    }
};