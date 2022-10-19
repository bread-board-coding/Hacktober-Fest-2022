 ListNode* temphead=nullptr;
    ListNode* temptail=nullptr;
    
    void addfirst(ListNode* node)
    {
        if(temphead==NULL)
        {
            temphead=node;
            temptail=node;
        }
        
        else
        {
            node->next=temphead;
            temphead=node;
        }
        
    }
    
    int length(ListNode* head)
    {
        if(head==NULL)
            return 0;
        
        return length(head->next)+1;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k<=1)
            return head;
        
        int len=length(head);
        ListNode* curr=head;
        ListNode* orihead=nullptr;
        ListNode* oritail=nullptr;
        while(len>=k)
        {
            int count=0;
        
            while(count<k)
            {
                ListNode* forw=curr->next;
                curr->next=NULL;
                addfirst(curr);
                curr=forw;
                count++;
            }
            
            if(orihead==NULL)
            {
                orihead=temphead;
                oritail=temptail;
            }
            else
            {
                oritail->next=temphead;
                oritail=temptail;
            }
            
            temphead=nullptr;
            temptail=nullptr;
            
            len=len-k;
        }
        
        oritail->next=curr;
        oritail=curr;
        return orihead;
    }