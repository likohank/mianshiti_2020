void PrintFromTopToBottom(BTreeNode* pRoot){
    if(pRoo==nullptr)
        return;

    std::deque<BTreeNode*> deq;

    deq.push(pRoot);

    while(deq.size()){
        BTreeNode* pNode = deq.front();
        deq.pop_front();
        printf("%d ",pNode->m_nVal);

        if(pNode->m_pLeft)
            deq.push_back(pNode->m_pLeft);
        if(pNode->m_pRight)
            deq.push_back(pNode->m_pRight);
    }
}
