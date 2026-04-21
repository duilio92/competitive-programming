class TrieNode:
    def __init__(self, char):
        self.char = char
        self.children = {}
        self.is_end =False

class Trie:

    def __init__(self):
        self.first_node = TrieNode("")

    def insert(self, word: str) -> None:
        node = self.first_node
        for x in word:
            if x in node.children:
                node = node.children[x]
            else:
                aux = TrieNode(x)
                node.children[x] = aux
                node = aux
        node.is_end = True      

    def search(self, word: str) -> bool:
        node = self.first_node
        for x in word:
            if x in node.children:
                node = node.children[x]
            else:
                return False
        if node.is_end:
            return True
        return False

    def startsWith(self, prefix: str) -> bool:
        node = self.first_node
        for x in prefix:
            if x in node.children:
                node = node.children[x]
            else:
                return False
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)