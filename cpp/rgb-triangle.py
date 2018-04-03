def triangle(s):
    a=[1]
    m=len(s)
    ans=0
    i=0
    while i<m:
        a.append(a[i]*(m-1-i)/(i+1))
        if s[i]=='R':
            a[i]=0;
        elif (s[i]=='B'):
            a[i]=a[i]*2
        ans=(ans+a[i])%3
        i=i+1
    return 'RGB'[(ans if m%2 else (9-ans)%3)]
