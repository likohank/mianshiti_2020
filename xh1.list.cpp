private Node head;
private Node last;
private int size;

public void insert(int data,int index) throw Exception
{
    if(index<0 || index>size)
        throw new Exception("out of size");
    Node inode = new Node(data);
    if(size == 0){
        head = inode;
        last = inode;
    } else if(index == 0)
    {
        inode.next = head;
        head = inode;
    } else if(index ==  size)
    {
        last.next = inode;
        last = inode;
    } else
    {
        preNode = find(index-1);
        inode.next = preNode.next;
        preNode.next = inode;
    }

    size++;
}

public Node find(int index) throw Exception
{
    if(index<0 || index>size)
        throw new Exception("out of size");
    Node temp= head;
    for(int i=0;i<inext;i++)
    {

    }
}
