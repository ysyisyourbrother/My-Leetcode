class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        if len(matrix) <=0 or len(matrix[0]) <= 0:
            return res
        self.N, self.M = len(matrix), len(matrix[0])
        dist_seq = [[0, 1], [1, 0], [0, -1], [-1, 0]]

        i, j, dist = 0, 0, 0
        while True:
            res.append(matrix[i][j])
            matrix[i][j] = "/"
            next_i, next_j = i + dist_seq[dist][0], j + dist_seq[dist][1]
            if not self.legal(next_i,next_j,matrix):
                if len(res) == self.N * self.M:
                    return res
                # 换方向
                dist = (dist + 1) % len(dist_seq)
                next_i, next_j = i + dist_seq[dist][0], j + dist_seq[dist][1]
            i, j = next_i, next_j
    
    def legal(self, i , j, matrix):
        if i<0 or i>=self.N or j<0 or j>=self.M or matrix[i][j] == "/":
            return False
        return True