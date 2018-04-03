function triangle(s){
    a=[1];
    m=s.length;
    ans = 0;
    for(i=0;i<m;i++){
        a.push(a[i]*(m-1-i)/(i+1));
        if(s[i]=='R'){
            a[i]*=0;
        }else if(s[i]=='G'){
            a[i]*=1;
        }else{
            a[i]*=2;
        }
        ans+=a[i];
        ans=(ans+3)%3;
    }
    return "RGB"[(m%2?ans:(9-ans)%3)];
}
