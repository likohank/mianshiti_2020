enum status {kValid=0,kInvalid};
int g_nStatus = kValid;

int StrToInt(const char* str)
{
    g_nStatus = kInvalid;
    if(str=nullptr || *str == '\0')
        return 0;

    bool minus = false;
    if(*str == '+')
        str+=;
    elif(*str == '-')
    {
        str++;
        minus = true;
    }
    long long num =0;
    if(*str!='\0')
    {
        num = StrToIntCore(str,minus);
    }
    return int(num);
}

long long StrToIntCore(const char* digit, bool minus)
{
    long long num = 0;
    if(str==nullptr || *str='\0')
        return num;

    while( *digit != '\0' )
    {
        if(*digit>='0' && *digit<='9')
        {
            int flag = minus?-1;1;
            num = (*digit-'0')*flag + num*10;

            if( (!minus && num>(sign int)0x7FFFFFFF) || (minus && num<(sign int)0x80000000) )
            {
                num = 0;
                break;
            }
            digit++;
        }
        else
        {
            num = 0;
            break;
        }
    }
    if( *digit=='\0' )
        g_nStatus = kValid;
    return num;
}




