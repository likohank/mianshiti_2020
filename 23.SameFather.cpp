/////////////////////////////普通树求 最小公共祖先

bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*> path){
    if(pRoot == pNode){
        path.push_back(pNode);
        return true;
    }

    path.push_back(pRoot);
    bool found = false;

    vector<TreeNode*>::iterator pChild = pRoot->m_nChildren.begin();
    while(!found && pChild != pRoot->m_nChildre.end()){
        found = GetNodePath(pChild,pNode,path)
        pChild++;
    }

    if(found == false)
    {
        path.pop_back();
    }
    return found;
}

TreeNode* GetLastCommon(list<TreeNode*> path1,list<TreeNode*> path2){
    if(path1 == nullptr || path2 == nullptr)
        return nullptr;

    list<TreeNode*>::iterator it1 = path1.begin();
    list<TreeNode*>::iterator it2 = path2.begin();
    TreeNode* last = nullptr;

    //path1  ABCDX ,path2 ABCER
    //按下表逐个遍历， 两个路径相同位置一样， 就看下一个， 最后循环结束 存的 last 就是最后一个一样的节点
    while(it1!=path1.end() && it2!=path2.end()){
        if(*it1 == *it2)
        {
            last = *it1;
        }
        it1++;
        it2++;
    }
}

TreeNode* GetLastCommonNode(TreeNode* pRoot,TreeNode* pNode1,TreeNode* pNode2){
    if(pRoot==nullptr || pNode1==nullptr || pNode2==nullptr)
        return nullptr;

    std::list<TreeNode*> list1;
    std::list<TreeNode*> list2;

    GetNodePath(pRoot,pNode1,list1);
    GetNodePath(pRoot,pNode2,list2);

    return GetLastCommon(path1,path2);
}


////////////////////////// 平衡二叉搜索书  求最小祖先
TreeNode* BSearchTreeSameFather(BTreeNode* pRoot,BTreeNode* p,BTreeNode* q){
    if(pRoot || p || q)
        return nullptr;

    while( (pRoot->m_nVal - p->m_nVal) * (pRoot->m_nVal-q->m_nVal) > 0 ){
        pRoot->m_nVal > p->m_nVal ? pRoot = pRoot->m_pLeft? pRoot= pRoot->m_pRight;
    }
    return pRoot;
}

//平衡二叉搜索书另一种写法
Node* FindLowestCommonAncestor(Node* root, Node* n1, Node* n2)
{
    //参数有一个为空返回NULL
    if (root == NULL || n1 == NULL || n2 == NULL)
        return NULL;

    if (root->data > n1->data && root->data > n2->data)
        return FindLowestCommonAncestor(root->left, n1, n2);
    else if (root->data < n1->data && root->data < n2->data)
        return FindLowestCommonAncestor(root->right, n1, n2);
    else
        return root;
}


// https://blog.csdn.net/xy913741894/article/details/70548415

// 有指向父节点的 树， 找最小公共祖先
Node* FindLowestCommonAncestor(Node* root, Node* n1, Node* n2)
{
    //参数有一个为空返回NULL
    if (root == NULL || n1 == NULL || n2 == NULL)
        return NULL;

    Node* p1 = n1;
    Node* p2 = n2;
    int count1 = 0; //求n2到根节点的长度
    int count2 = 0; //求n2到根节点的长度
    while (p1 != root)
    {
        ++count1;
        p1 = p1->father;
    }

    while (p2 != root)
    {
        ++count2;
        p2 = p2->father;
    }

    Node* preMove   = (count1>count2)?n1:n2;
    Node* afterMove = (count1>count2)?n2:n1;

   n=abs(count1-count2);
   while (n--)
   {
       preNove = p1->father;
   }

   while (preMove != afterMove)
   {
       preMove = preMove->father;
       afterMove = afterMove->father;
   }
   return preMove;
}

