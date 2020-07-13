
while(rs)
{
    buflen = revc(avtiveevents[i].data.fd,buf,sizeof(buf),0);
    if(buflen<0)
    {
        if(errno == EAGAIN)
            break;
        else
            return;

    }
    else if(buflen == 0)
    {
        //对端的socket已经正常关闭
    }

    if(buflen==sizeof(buf))
        rs =1; //再次读取
    else
        rs=0;
}
