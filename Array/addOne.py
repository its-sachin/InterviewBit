class Solution:
    def plusOne(self, digits):

        d=[]
        found=False
        for i in digits:
            if(not found):
                if(i!=0):
                    found=True
                    d.append(i)
            else:
                d.append(i)


        carry =1
        i=len(d)-1
        while(carry ==1 and i>=0):
            d[i]+=1
            if(d[i]==10):
                d[i]=0
                carry=1
            else:
                carry=0
            i-=1

        if(carry==1):
            d=[1]+d
        return d

o = Solution()
a=[0,0,0,9,9,9,9]
print(o.plusOne(a))



  