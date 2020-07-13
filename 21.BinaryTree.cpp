#include<cstdio>
#include<cstring>

struct TreeNode{
    int m_nValue;
    TreeNode* m_pLeft;
    TreeNode* m_pRight;
};

void preOrder(TreeNode* root){
    if(root!=nullptr)
    {
        printf("%d",root->m_nValue);
        preOrder(root->m_pLeft);
        preOrder(root->m_pRight);
    }
}

void preOrder(TreeNode* root){
    std::stack<TreeNode*> stack;
    TreeNode* pNode = root;

    while(pNode!=nullptr || !stack.empty()){
        if(pNode!=nullptr){
            printf("%d ",pNode->m_nVal);
            stack.push(pNode);
            pNode = pNode->pLeft;
        }
        else{
            pNode = stack.top();
            stack.pop();
            pNode = pNode->pRight;
        }
    }
}


void preOrder(TreeNode* root){
    if(root == nullptr)
        return;

    std::stack<TreeNode*> stack;
    TreeNode* pNode = root;
    stack.push(pNode);

    while(!stack.empty()) {
        pNode = stack.top();
        printf("%d ",pNode->m_nVal);

        if(pNode->m_pRight)
            stack.push(pNode->m_pRight);
        if(pNode->m_pLeft)
            stack.push(pNode->m_pLeft);
    }

}


void inOrder(TreeNode * root){
    std::stack<TreeNode*> stack;
    TreeNode* pNode = root;

    while(pNode!=nullptr || !stack.empty()){
        if(pNode!=nullptr){
            stack.push(pNode);
            pNode = pNode->mLeft;
        }
        else{
            pNode = stack.top();
            stack.pop();
            printf("%d ",pNode->m_nVal);
            pNode = pNode->pRight;
        }
    }
}

//标记实现后序遍历
void afterOrder(TreeNode* root){
    std::stack<TreeNode*> stack;
    TreeNode* cur = nullptr;
    TreeNode* pre = root;

    if(root == nullptr)
        return;

    stack.push(root);

    while(!stack.empty()){
        cur = stack.top();
        if( (cur->m_pLeft == nullptr && cur->m_pRight==nullptr) || (cur->m_pLeft == pre || cur->m_pRight==pre) )
        {
            printf("%d ",cur->m_nVal);
            pre = cur;
            stack.pop();
        }
        else{
            if(cur->m_pRight)
                stack.push(cur->m_pRight);
            if(cur->m_pLeft)
                stack.push(cur->m_pLeft);
        }
    }
}

//双栈实现 后序遍历
//https://baijiahao.baidu.com/s?id=1652242076931729515&wfr=spider&for=pc
void afterOrder(TreeNode* root){
    if(root==nullptr)
        return;

    std::stack<TreeNode*> stack1;
    std::stack<TreeNode*> stack2;
    TreeNode* pNode = root;

    s1.push(root);
    while(!s1.empty()){
        pNode = s1.top();
        s1.pop();

        s2.push(pNode);
        if(pNode->m_pLeft)
            s1.push(pNode->m_pLeft);
        if(pNode->m_pRight)
            s1.push(pNode->m_pRight);
    }

    while(!s2.empty()){
        printf("%d ",s2.top()->m_nVal);
        s2.pop();
    }
}
