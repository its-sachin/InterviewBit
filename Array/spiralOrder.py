class Solution:
	# @param A : tuple of list of integers
	# @return a list of integers


    def spiralOrder(self, grid):
        n = len(grid)
        m = len(grid[0]) 
        ans = []
        # if(n==1):
        #     return grid[0]
        # elif(m==1):
        #     for i in grid:
        #         ans.append(i[0])
        #     return ans
        i=0
        j=0
        while(i<=(n-1)//2 and j<=(m-1)//2):
    
            for k in range(j,m-j):
                ans.append(grid[i][k])
            for k in range(i+1,n-i):
                ans.append(grid[k][m-i-1])
            if(not i==n-i-1):
                for k in range(m-i-2,i-1,-1):
                    ans.append(grid[n-i-1][k])
            if(not j==m-j-1):
                for k in range(n-i-2,i,-1):
                    ans.append(grid[k][j])

            i+=1
            j+=1
            
        return ans


o = Solution()
A =[
  [133, 241, 22, 258, 187, 150, 79, 207, 196, 401, 366, 335, 198],
  [401, 55, 260, 363, 14, 318, 178, 296, 333, 296, 45, 37, 10],
  [112, 374, 79, 12, 97, 39, 310, 223, 139, 91, 171, 95, 126]
]
print(o.spiralOrder(A))
