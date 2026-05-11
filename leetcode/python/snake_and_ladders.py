class Solution:
    def invert(self, x, min_val, max_val):
        return min_val + max_val - x

    def label_to_column_row(self, label):
        n = len(self.board)
        row = (label - 1) // n
        col = (label - 1) % n

        # flip row (bottom → top)
        row = n - 1 - row

        # zigzag columns
        if (n - 1 - row) % 2 == 1:
            col = n - 1 - col

        return row, col

    def label_to_column_row_back(self, label):
        column = label % len(self.board)
        row = label // len(self.board)
        return len(self.board)-1 - row, column

    def update_cost_rec(self, current_label, actual_cost):
        current_row, current_col = self.label_to_column_row(current_label)
        #print(f"label: {current_label} row: {current_row} column: {current_col}")
        if self.cost[current_row][current_col] >= actual_cost:
            self.cost[current_row][current_col] = actual_cost
            
            #print(" UPDATED COSTTTTTT")
            #print(self.cost)
        else:
            return None
        val = self.board[current_row][current_col]
        if(val!=-1):
            self.update_cost_rec(val, actual_cost+1)
        for x in range(current_label+1, min(current_label + 6, len(self.board)**2) + 1):
            self.update_cost_rec(x, actual_cost +1)

    def snakesAndLadders(self, board: List[List[int]]) -> int:
        self.board = board
        n = len(board)

        visited = set()
        queue = deque([(1, 0)])  # (label, moves)
        visited.add(1)

        while queue:
            current_label, moves = queue.popleft()

            if current_label == n * n:
                return moves

            for x in range(current_label + 1, min(current_label + 6, n*n) + 1):
                row, col = self.label_to_column_row(x)

                # snake or ladder
                if board[row][col] != -1:
                    next_label = board[row][col]
                else:
                    next_label = x

                if next_label not in visited:
                    visited.add(next_label)
                    queue.append((next_label, moves + 1))
        return -1