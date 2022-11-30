# Written by: Jian-Yuan Lin
# Date: 2022.11.30

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        # use the preorder traversal to encode!
        def encode(root, ans):
            if not root:
                ans += "# "
                return ans
            val = root.val
            ans += str(val) + " "
            ans = encode(root.left, ans)
            ans = encode(root.right, ans)
            return ans
        return encode(root, "")

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data_split = data.split(" ")
        
        def decode(data):
            if data[0] == "#":
                data.pop(0)
                return None
            val = int(data[0])
            data.pop(0)
            root = TreeNode(val)
            root.left = decode(data)
            root.right = decode(data)
            return root
        return decode(data_split)