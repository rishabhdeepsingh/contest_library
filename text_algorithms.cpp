vector<int> kmp (string & s)
{
    vector<int>P;
    P.push_back(0);
    int t=0;
    for(int i=1;i<(int)s.length();i++)
    {
        while(t>0 && s[t]!=s[i])
            t=P[t-1];
        if(s[t]==s[i])
            t++;
        P.push_back(t);
    }
    return P;
}
vector<int> pref(string & s)
{
    int last=0,lastbeg;
    vector<int>res;
    res.push_back(0);
    for(int i=1;i<s.length();i++)
    {
        int tmp=0;
        if(i<last)
            tmp=min(res[i-lastbeg],last-i);
        while(i+tmp<s.length() &&s[tmp]==s[i+tmp])
            tmp++;
        if(i+tmp>last)
        {
            last=i+tmp;
            lastbeg=i;
        }
        res.push_back(tmp);
    }
    return res;
}
//testowac
vector<int> manacher(string &s)
{
    string t;
    for(int i=0;i<s.length()-1;i++)
    {
        t+=s[i]
        t+=(char)7; //symbol ktorego nie ma w tekscie
    }
    t+=s[s.length()-1];
    int n= t.length();
    vector<int> res;
    int furthest=-1, center;
    for(int i=0;i<n;i++)
    {
        int tmp=0;
        if( i<=furthest)
            tmp = furthest-i;
        while(i-tmp-1 >=0 && i+tmp+1 <n && t[i-tmp-1]==t[i+tmp+1])
            tmp++;
        res
    }


}
vector<int> suffix_array(string & s)
{
    int k=0;
    vector<int> labels;
    for(string :: iterator i = s.begin();i!=s.end();i++)
        labels.push_back((int)*i);
    while(1 << k < (int)s.length())
    {
        vector<pair<pair<int,int>,int > > tmp;
        for(int i = 0; i < (int)s.length();i++)
            tmp.push_back(make_pair(make_pair(labels[i],i+(1<<k) < (int)s.length() ? labels[i+(1<<k)] : 1<<30),i));
        sort(tmp.begin(),tmp.end());
        int l=0;
        for(int i=0;i <(int) tmp.size();i++)
        {
            if(i>0 && tmp[i].first!= tmp[i-1].first)
                l++;
            labels[tmp[i].second]=l;
        }
        k++;
    }
    vector<int> sa;
    sa.resize(s.length());
    for(int i=0;i <(int) labels.size();i++)
        sa[labels[i]]=i;
    return sa;
}
vector<int> lcp(string & s,vector<int> & sa)
{
    vector<int> lcp,rank;
    rank.resize(sa.size());
    lcp.resize(sa.size());
    for(int i=0;i<sa.size();i++)
        rank[sa[i]]=i;
    int l=0;
    for(int i=0;i<sa.size();i++)
    {
        if(rank[i]==sa.size()-1)
            lcp[rank[i]]=0;
        else
        {
            while(i+l < s.length() && sa[rank[i]+1]+l < s.length() && s[i+l]==s[sa[rank[i]+1]+l])
                l++;
            lcp[rank[i]]=l;
        }
        l=max(0,l-1);
    }
    return lcp;
}

