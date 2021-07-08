class Solution:
    	# @param A : integer
	# @return a strings

    def intToRoman(self, num: int)->str:
        d = {1: ['I', 'X', 'C', 'M'], 2: ['II', 'XX', 'CC', 'MM'], 3: ['III', 'XXX', 'CCC', 'MMM'], 4: ['IV', 'XL', 'CD'], 5: ['V', 'L', 'D'], 6: ['VI', 'LX', 'DC'], 7: ['VII', 'LXX', 'DCC'], 8: ['VIII', 'LXXX', 'DCCC'], 9: ['IX', 'XC', 'CM']}
        ans = ""
        i=0
        while(num!=0):
            digit = num%10
            if(digit!=0):
                ans = d.get(digit)[i]+ans
            i+=1
            num=num//10
        return ans
