/*
Approach:
Create an empty stack to keep track of opening parentheses.
Loop through each character in the input string.
If the character is an opening parentheses, push it onto the stack.
If the character is a closing parentheses, pop the top element from the stack and check whether it matches the corresponding opening parentheses for the current closing parentheses.
If the stack is empty and all parentheses have been matched, return True. Otherwise, return False.
Intuition:
The key to solving this problem is to recognize that the parentheses must be matched in the correct order. That is, each closing parentheses must match the most recently opened opening parentheses.
We can use a stack to keep track of the opening parentheses as we encounter them in the input string.
When we encounter a closing parentheses, we check whether the top element of the stack matches the corresponding opening parentheses.
If it does, we pop the element from the stack and continue. If it doesn't, the parentheses are not valid and we can return False immediately.
If we reach the end of the input string and the stack is empty, we know that all parentheses have been matched and we can return True.
If the stack is not empty, we know that there is an opening parentheses without a corresponding closing parentheses and we can return False.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for(auto c: s){
            if(c == '(' || c == '[' || c == '{') {
                stck.push(c);
            } else {
                if(stck.empty())
                    return false;
                else if( c==')'&& stck.top()=='(')
                    stck.pop();
                else if( c==']'&& stck.top()=='[')
                    stck.pop();
                else if( c=='}'&& stck.top()=='{')
                    stck.pop();
                else
                    return false;
            }
        }

        return stck.empty();
    }
};