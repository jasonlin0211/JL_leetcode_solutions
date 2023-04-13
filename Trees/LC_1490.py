class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        mapping = collections.defaultdict(dict)

        def dfs(root, height):
            if not root:
                return root
            mapping[height][root.val] = Node(root.val)
            for nxt in root.children:
                mapping[height][root.val].children.append(dfs(nxt, height+1))
            return mapping[height][root.val]
        return dfs(root, 0)