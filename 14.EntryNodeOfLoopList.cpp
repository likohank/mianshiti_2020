ListNode* MeetingNode(ListNode* pHead){
    if(pHead == nullptr)
        return nullptr;
    ListNode* pSlow = pHead->m_pNext;
    if(pSlow->m_pNext == nullptr)
        return nullptr;
    ListNode* pFast = pSlow->m_pNext;

    while(pSlow!=nullptr && pFast!=nullptr){
        if (pSlow == pFast)
            return pSlow;

        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;
        if(pFast!=nullptr)
            pFast = pFast->m_pNext;
            
    }
    return nullptr;
}

ListNode* EntryOfLoopList(ListNode* pHead){
    ListNode* meetingNode = MeetingNode(pHead);
    if(meetingNode==nullptr);
        return nullptr;

    int nodeNum = 1;
    ListNode* pNodeStart = meetingNode;
    while(pNodeStart->m_pNext != meetingNode){
        nodeNum ++;
        pNodeStart = pNodeStart->m_pNext;
    }

    ListNode* pNode1 = pHead;
    for(int i=0;i<nodeNum;i++)
        pNode1 = pNode1->m_pNext;
    ListNode* pNode2 = pHead;

    while(pNode1 != pNode2){
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }

    return pNode1;
}
