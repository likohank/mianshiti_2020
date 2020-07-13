
#define IPADDRESS "127.0.0.1"
#define PORT 8787
#define MAXSIZE 1024
#define LISTENQ  5
#define FDSIZE 1000
#define EPOLLEVENTS 100

listenfd = socket_bind(IPADDRESS,PORT);

struct epoll_event ev[EPOLLEVENTS];

efd = epoll_create(FSSIZE);

add_event(efs,listenfd,EPOLLIN);

for(;;){
    ret = epoll_wait(efd,ev,EPOLLEVENTS,-1);
    handle_event(efd,ev,ret,listenfd,buf);
}

static void handle_event(int efd,struct epoll_event ev,int ev_num, int listenfd)
{
    int i;
    int fd ;

    for (i=0;i<ev_num;i++)
    {
        fd = ev[i].data.fd
        if((fd == listenfd) && (ev[i].event & EPOLLIN))
        {
            handle_accept(efd,listenfd);
        }
        else if(ev[i].event & EPOLLIN)
        {
            do_read(efd,fd,buf);
        }
        else if(ev[i].event & EPOLLOUT)
        {
            do_write(efd,fd,buf);
        }
    }
}

static void handle_accept(int efd,int listenfd)
{
    int clifd;
    struct sockaddr_in addr;
    socklen_t cliaddrlen;

    clifd = accept(listenfd,(struct socketaddr*)&addr,&cliaddrlen);

    if(clifd == -1)
        perror("accept error");
    else
    {
        printf("Add a new client");
        add_event(efd,clifd,EPOLLIN);
    }
}

static void do_read(int efd, int clifd,char* readbuf)
{
    int len;
    len = read(clifd,readbuf,MAXSIZE);

    if(len == -1)
    {
        perror("read error");
        close(clifd);
        delete_event(efd,clifd,EPOLLIN);
    }
    else if(len ==0 )
    {
        perror("client has close");
        close(clifd);
        delete_event(efd,clifd,EPOLLIN);
    }
    else{
        printf("message is %s\n",buf);
        modify_event(efd,fd,EPOLLOUT);
    }
}

static void do_write(int efd,int clifd,char* buf)
{
    int len ;
    len = write(clifd,buf,strlen(buf));

    if (len==-1){
        perror("write failed");
        close(clifd);
        delete_event(efd,clifd,EPOLLOUT);
    }
    else{
        modify_event(efd,clifd,EPOLLIN);       
    }
    memset(buf,0,MAXSIZE);
}

static void add_event(int efd,int fd,int status)
{
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.event = status;

    epoll_ctl(efd,EPOLL_CTL_ADD,fd,&ev);
}


static void delete_event(int efd,int fd,int status)
{
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.event = status;

    epoll_ctl(efd,EPOLL_CTL_DEL,fd,&ev);
}

static void modify_event(int efd, int fd,int status)
{
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.event = status;

    epoll_ctl(efd,EPOLL_CTL_MOD,fd,&ev);
}
