def c(n,k):
    if n<k:
        return 0
    ans = 1
    while n:
        if (n%3)<(k%3):
            return 0
        if ((n%3)==(k%3)) | ((k%3)==0):
            n=n//3
            k=k//3
            continue
        else:
            ans=(ans*2)%3
            n=n//3
            k=k//3
    return ans
def triangle(s):
    m=len(s)
    ans=0
    i=0
    t=0
    while i<m:
        a=c(m-1,i)
        if (s[i]=='B'):
            t=a*2
        elif (s[i]=='G'):
            t=a
        else:
            t=0
        ans=(ans+t)%3
        i=i+1
    return 'RGB'[int(ans if m%2 else (9-ans)%3)]
