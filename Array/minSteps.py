class Solution:
	# @param A : list of integers
	# @param B : list of integers
	# @return an integer
    def coverPoints(self, A, B):
        if(len(A)!=len(B)):
            return -1
        c=0
        for i in range(1,len(A)):
            c+=max(abs(A[i]-A[i-1]),abs(B[i]-B[i-1]))
        return c
