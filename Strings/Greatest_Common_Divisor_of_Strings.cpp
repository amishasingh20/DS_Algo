/*For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.*/
#include<iostream>
#include<string>
#include <numeric> //used for gcd function

using namespace std;


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 == str2+str1){
            return str1.substr(0,gcd(size(str1),size(str2)));
        }

        return "";
    }
};

int main(){
    string word1, word2;
    cout << "Enter the 2 string " << endl;
    cin >> word1;
    cin >> word2;

    Solution s;
    auto result = s.gcdOfStrings(word1,word2);
    cout << " result is " << result << endl;

    return 0;

}