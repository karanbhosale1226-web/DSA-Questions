class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class MyLinkedList {
    Node* head;
    Node* tail; 
public:
    MyLinkedList() {
        head=NULL;
        tail=NULL;
    }
    
    int get(int index) {
        if(head==NULL){
            return -1;
        }
        Node* temp=head;
        int cnt=0;
        while(cnt<index){
            temp=temp->next;
            cnt++;
            if(temp==NULL){
                return -1;
            }
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        if(head==NULL && tail==NULL){
            Node* temp=new Node(val);
            head=temp;
            tail=temp;
        }
        else{
            Node* temp=new Node(val);
            temp->next=head;
            head=temp;
        }
    }
    
    void addAtTail(int val) {
        if(head==NULL && tail==NULL){
            Node* temp=new Node(val);
            head=temp;
            tail=temp;
        }
        else{
            Node* temp=new Node(val);  
            tail->next=temp;
            tail=temp;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        int cnt=0;
        Node* curr=head;
        Node* prev=NULL;
        while(cnt<index){
            if(curr==NULL){
                return;
            }
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        
        Node* temp=new Node(val);
        prev->next=temp;
        temp->next=curr;
        if(curr==NULL){
            tail=temp;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index==0){
            Node* temp=head;
            head=head->next;
            delete temp;

            if(head==NULL){
                tail=NULL;
            }
            return;
        }
        if(head==NULL){
            return;
        }
        Node* curr=head;
        Node* prev=NULL;
        int cnt=0;
        while(cnt<index){
            if(curr==NULL){       
                return;           
            }
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr==NULL){
                return;
            }
        if(curr==tail){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */