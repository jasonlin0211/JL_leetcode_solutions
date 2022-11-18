// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // use number + "#" to indicate the length of single str
        // ex ["Hello", "World"] -> 5#Hello5#World
        string result = "";
        for (string str: strs){
            string size = to_string(str.size());
            result += size + "#" + str;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }
            // substr(start, length) --> equal to s[start: start + length]
            int size = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j+1, size));
            i = j + 1 + size;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));