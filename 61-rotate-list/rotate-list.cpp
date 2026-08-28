class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)
            return head;

        int n = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            n++;
            temp = temp->next;
        }

        k = k % n;

        for(int i=0;i<k;i++){
            ListNode* prev=NULL;
            ListNode* curr=head;

            while(curr!=NULL && curr->next!=NULL){
                prev=curr;
                curr=curr->next;
            }
            
            curr->next=head;
            prev->next=NULL;
            head=curr;
        }

        return head;
    }
};