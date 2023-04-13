class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        vector<int> stack;
        for (int num: pushed){
            stack.push_back(num);
            while (i < popped.size() && !stack.empty() && stack.back() == popped[i]){
                stack.pop_back();
                i++;
            }
        }
        return stack.empty();
    }
};