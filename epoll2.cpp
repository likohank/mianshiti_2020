#define IPADDRESS "127.0.0.1"
#define PORT 8787
#define MAXSIZE 1024
#define LISTENQ 5
#define FDSIZE 1000
#define EPOLLENVENTS 100


listenfd = socket_bind(IPADDRESS,PORT);
struct epoll_event events[EPOLLEVENTS];

//创建一个描述符
epolfd = epoll_create(FDSIZE);

//添加监听描述符事件
add_event(epollfd,listenfd,EPOLLIN);

//循环等待
for(;;)
{
    //该函数返回已经准备好的描述符事件shumu 
    ret = epoll_wait(epollfd,events,EPOLLEVENTS,-1);
    //处理接收到的连接
    handle_events(epollfd,events,ret,listenfd,buf);
}

//事件处理函数
static void handle_events(int epollfd, struct epoll_event *events,int num,int listenfd,char*bug)
{
    int i;
    int fd;

    //进行遍历.这里只要遍历已经准备好的IO时间，num并不是当初epoll_create 时的 FDSIZE
    for(i=0;i<num;i++)
    {
        fd = events[i].data.fd;
        if((fd == listenfd) && (events[i].events & EPOLLIN))
            handle_accept(epollfd,listenfd);
        else if (events[i].events & EPOLLIN)
            do_read(epollfd,fd,buf);
        else if(events[i].events & EPOLLOUT)
            do_write(epollfd,fd,buf);
    }
}

static void add_event(int epollfd,int fd,int state){
    struc epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctr(epollfd,EPOLL_CTL_ADD,fd,&ev);
}

static void handle_accept(int epollfd,int listenfd)
{
    int clifd;
    struct sockaddr_in cliaddr;
    socklen_t cliaaddrlen;

    clifd = accept(listenfd, (struct sockaddr*)&cliaddr，&cliaddrlen);

    if(clifd == -1)
        perror("accept error")
    else
    {
        printf("Add a new client");
        add_event(epollfd,clifd,EPOLLIN);
    }
}

static void do_read(int epollfd,int fd,char* buf){
    int nread;
    nread = read(fd,buf,MAXSIZE);
    if(nread == -1){
        perror("read error");
        close(fd);
        delete_event(epollfd,fd,EPOLLIN);
    }
    else if(nread == 0)
    {
        fprintf(strerr，"client close");
        close(fd);
        delete_event(epollfd,fd,EPOLLIN);
    }
    else{
        printf("read message if :%s",buf);
        modify_event(epollfd,fd,EPOLLOUT);
    }
}

static void delete_event(int epollfd,int fd,int state) {
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,&ev);
}

static void modify_event(int epollfd,int fd,int state) {
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&ev);
}


