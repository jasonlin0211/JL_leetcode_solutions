// Written by: Jian-Yuan Lin
// Date: 2022.11.18

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordlist(wordList.begin(), wordList.end());
        if (!wordlist.count(endWord)){
            return false;
        }
        queue<string> q;
        q.push(beginWord);
        int steps = 0;
        while (!q.empty()){
            int size = q.size();
            for (int n = 0; n < size; n++){
                string cur = q.front();
                q.pop();
                if (cur == endWord){
                    return steps + 1;
                }
                for(int i = 0; i < cur.size(); i++){
                    char c = cur[i];
                    for(int j = 0; j < 26; j++){
                        cur[i] = 'a' + j;
                        if (wordlist.count(cur)){
                            q.push(cur);
                            wordlist.erase(cur);
                        }
                    }
                    cur[i] = c;
                }
            }
            steps++;
        }

        return 0;   
    }
};