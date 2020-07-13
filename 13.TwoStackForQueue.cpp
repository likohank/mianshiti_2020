#include<cstdio>
#include<cstring>

template<typename T> class CQueue
{
    public:
        CQueue(void);
        ~CQueue(void);

        void push(const T& node);
        T pop();

    private:
        static<T> stack1;
        static<T> stack2;
};

template<typename T> void CQueue::push(const T& node){
    stack1.push(node);
}

template<typename T> T CQueue::pop(){
    if(stack2.size() == 0){
        while(!stack1.empty()){
            T& cur = stack1.top();
            stack2.push(cur);
            stack1.pop();
        }
    }

    if(stack2.empty){
        throw std::exception("CQueue is empty");
    }
    T head = stack2.top();
    stack2.pop();
    return head;
}


// 两个队列实现一个栈
template<typename T> class CStack{
    public:
        CStack(void);
        ~CStack(void);

        void push(T& node);
        void pop();
        T& top();

    private:
        queue<T> queue1;
        queue<T> queue2;
};

template<typename T> void CStack<T>::push(T& node){
    if(queue1.empty())
    {
        queue2.push(node);
    }
    else
    {
        queue1.push(node);
    }
}


template<typename T> void CStack<T>::pop(){
    if(queue1.empty()){
        int size = queue2.size();
        while(size>1){
            queue1.push(queue2.front());
            queue2.pop();
            --size;
        }
        queue2.pop();
    }
    else {
        int size = queue1.size();
        while(size>1){
            queue2.push(queue1.front());
            queue1.pop();
            --size;
        }
        queue1.pop();
    }
}

template<typename T> T& CStack<T>::top(){
    if(queue1.empty() && queue2.empty()){
        throw std::exception("CStack is empty");
    }
    if(!queue1.empty())
        return queue1.back();
    else
        return queue2.back()
}

