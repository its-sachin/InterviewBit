class Solution:
    	# @param A : integer
	# @return a list of list of integers
    def generateMatrix(self, A):
        n = A
        m = A
        ans = [[0 for i in range(A)] for j in range(A)]
        i=0
        j=0
        l=1
        while(i<=(n-1)//2 and j<=(m-1)//2):

            for k in range(j,m-j):
                ans[i][k]=l
                l+=1
            for k in range(i+1,n-i):
                ans[k][m-i-1]=l
                l+=1
            if(not i==n-i-1):
                for k in range(m-i-2,i-1,-1):
                    ans[n-i-1][k]=l
                    l+=1
            if(not j==m-j-1):
                for k in range(n-i-2,i,-1):
                    ans[k][j]=l
                    l+=1

            i+=1
            j+=1
            
        return ans

o = Solution()
print(o.generateMatrix(int(input())))
