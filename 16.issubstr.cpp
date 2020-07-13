int isSubStr(const char* target,const char* source){
    if(target == nullptr || source == nullptr)
        return -1;

    char* pBase = source;
    int cnt = 0;
    int index = 0;
    while(*pBase)
    {
        cnt=0;

        while( *(pBase+cnt) && *(target+cnt))
        {
            if( *(pBase+cnt) != *(target+cnt))
                break;
            cnt ++;
        }

        if( '\0' == *(target+cnt) )
            return index;

        index++;
        pBase++;
    }
}
