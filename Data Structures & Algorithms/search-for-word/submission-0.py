class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.board = board
        # self.visited = set() # or in c++, a 2d array of size = board
        self.word = word
        for i in range(len(board)):
            for j in range(len(board[0])):
                if word[0] == board[i][j]:
                    if self.dfs(i, j, 1):
                        return True
        
        return False

    
    def dfs(self, i, j, idx):
        if idx == len(self.word): # everything has matched
            return True

        to_restore = self.board[i][j]
        self.board[i][j] = "!"
        for ki, kj in self.kids(i, j):
            if self.board[ki][kj] == self.word[idx]:
                if self.dfs(ki, kj, idx + 1):
                    return True

        self.board[i][j] = to_restore
        return False

    def kids(self, i, j):
        m = len(self.board)
        n = len(self.board[0])
        result = []
        if i + 1 < m:
            result.append((i + 1, j))
        if i - 1 >= 0:
            result.append((i - 1, j))
        if j + 1 < n:
            result.append((i, j + 1))
        if j - 1 >= 0:
            result.append((i, j - 1))

        return result
