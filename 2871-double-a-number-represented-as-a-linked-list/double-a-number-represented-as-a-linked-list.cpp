class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {

        head = reverse(head);

        ListNode* temp = head;
        int carry = 0;

        while(temp != NULL){
            int value = temp->val * 2 + carry;

            temp->val = value % 10;
            carry = value / 10;

            temp = temp->next;
        }

        

        head = reverse(head);
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};