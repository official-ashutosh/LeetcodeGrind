# Base=26 fails at testcase 815(single hash)
# Base=29 fails at testcase 816(single hash)
# use double hashing to avoid hash collision
class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        base1=26
        base2=29
        mod1=int(1e9)+7
        mod2=int(1e9)+9
        suffixMatches={}
        minLengthIndex=0
        for i,word in enumerate(wordsContainer):
            if len(wordsContainer[i])<len(wordsContainer[minLengthIndex]):
                minLengthIndex=i
            hash1=hash2=0
            for j in range(len(word)-1,-1,-1):
                hash1=(hash1*base1)%mod1
                hash1=(hash1+ord(word[j])-96)%mod1
                hash2=(hash2*base2)%mod2
                hash2=(hash2+ord(word[j])-96)%mod2
                hashKey=(hash1,hash2)
                if hashKey in suffixMatches:
                    index=suffixMatches[hashKey]
                    if len(wordsContainer[index])>len(wordsContainer[i]):
                        suffixMatches[hashKey]=i
                else:
                    suffixMatches[hashKey]=i
        res=[minLengthIndex]*len(wordsQuery)
        for i,query in enumerate(wordsQuery):
            hash1=hash2=0
            for j in range(len(query)-1,-1,-1):
                hash1=(hash1*base1)%mod1
                hash1=(hash1+ord(query[j])-96)%mod1
                hash2=(hash2*base2)%mod2
                hash2=(hash2+ord(query[j])-96)%mod2
                hashKey=(hash1,hash2)
                if hashKey in suffixMatches:
                    res[i]=suffixMatches[hashKey]
                else: 
                    break     
        return res