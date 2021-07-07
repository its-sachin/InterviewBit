class Solution:
    	# @param A : integer
	# @return a list of integers
    def primesum(self, A):
        spf =[x for x in range(A+1)]
        i=2
        while(i*i<=A):
            if(spf[i]==i):
                j=i*i

                while(j<=A):
                    spf[j]=i;
                    j+=i;
            i+=1

        if(spf[A-2]==A-2):
            return [2,A-2]

        for i in range(3,A-2,2):
            if(spf[i]==i and spf[A-i]==A-i):
                return [i,A-i]
o = Solution
print(Solution.primesum(o,int(input())))