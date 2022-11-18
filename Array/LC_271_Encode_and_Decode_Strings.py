# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        # give string length and "#" as seperation
        # ["Hello", "World"] -> 5#Hello5#World
        result = ""
        for string in strs:
            result += str(len(string)) + "#" + string
        return result
            
        

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        ans = []
        i = 0
        while i < len(s):
            j = i
            while j < len(s) and s[j] != "#":
                j += 1
            lens = int(s[i:j])
            ans.append(s[j+1:j+1+lens]) # word starts from j+1, since str[j] is #
            i = j+1+lens
        return ans


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))