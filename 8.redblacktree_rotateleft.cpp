static <K,V> TreeNode<K,V> rotateLeft(TreeNode<K,V> root,TreeNode<K,V> p) {
    //root      根节点
    //p         表示要调整的节点
    //r         表示p的右节点
    //pp        表示p的父亲节点
    //rl        表示p的右孩子的左孩子节点

    TreeNode<K,V> r,pp,rl;

    //r判断，如果r为空则旋转没有意义
    if( p!=NULL && (r = p.right) != NULL) {
        //多个等号的连接操作从右往左看，设置rl的父亲
        if((rl = p.right = r.left) != NULL)
            rl.parent = p

        //判断p的父亲，为空，为根节点，根节点的话就设置为黑色
        if((pp = r.parent = p.parent) == NULL)
            (root = r).red = false
        else if(pp.left == p){
            pp.left = r;
        }
        else{
            pp.right = r;
        }

        r.left = p;
        p.parent = r;
    }
    return root;
}
