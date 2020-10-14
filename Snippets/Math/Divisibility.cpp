bool div2(const string &s)
{
    int lastDigit=(s[s.length()-1]-'0');
    if(lastDigit%2==0)
        return true;
    return false;
}
bool div3( const string &s)
{
    int sum=0;
    for(auto ch : s)
        sum+= (ch-'0');
    if(sum%3==0)
        return true;
    return false;
}
bool div4(const string &s)
{
    int len=s.length(),tail=0;

    if(len<3)
        tail=stoi(s);
    else
        tail=stoi(s.substr(len-2));

    if(tail%4==0)
        return true;
    return false;
}
bool div5(const string &s)
{
    int lastDigit=(s[s.length()-1]-'0');
    if(lastDigit == 0 || lastDigit == 5)
        return true;
    return false;
}
bool div6(const string &s)
{
    return isDiv2(s) && isDiv3(s);
}
bool div7(const string &s)
{
    int idx=s.length()-1,sum=0;
    bool flag=true;
    while(idx -2>=0)
    {
        if(flag)
            sum+=stoi(s.substr(idx-2,3));
        else
            sum-=stoi(s.substr(idx-2,3));
        idx-=3;
        flag = !flag;
    }
    if(idx>=0)
    {
        if(flag)
            sum+=stoi(s.substr(0,idx + 1 ));
        else
            sum-=stoi(s.substr(0,idx + 1 ));
    }
    if(sum%7==0)
        return true;
    return false;

}

bool div8(const string &s)
{
    int tail=0,len=s.length();
    if(len<4)
        tail=stoi(s);
    else
        tail=stoi(s.substr(len-3));
    if(tail%8==0)
        return true;
    return false;

}
bool div9( const string &s)
{
    int sum=0;
    for(auto ch : s)
        sum+= (ch -'0');
    if(sum%9==0)
        return true;
    return false;
}

bool div10(const string s)
{
    int lastDigit=(s[s.length()-1] - '0');
    if(lastDigit == 0 )
        return true;
    return false;
}

bool div11(const string &s)
{
    int sum=0;
    bool flag=true;
    for(auto ch : s)
    {
        if(flag)
            sum+=ch-'0';
        else
            sum-=(ch & 15);
        flag = !flag;
    }
    if(sum % 11 == 0)
        return true;
    return false;
}

bool div12(const string &s)
{
    return isDiv3(s) && isDiv4(s);
}
