class MyLinkedList {
public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int x): val(x),next(NULL) {}
    };

    LinkedNode* head;
    int size;

    MyLinkedList() {
        head = NULL; //unfix
        size=0;
    }
    int get(int index) {
        if(index < 0) return -1;
        LinkedNode* temp = head;
        int pos=0;
        while(temp){
            if(pos == index){
                return temp->val;
            }
            pos++;
            temp = temp->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        size++;
        LinkedNode* newnode = new LinkedNode(val);
        newnode->next = head;
        head = newnode;
    }
    
    void addAtTail(int val) {
        size++;
        LinkedNode* newnode = new LinkedNode(val);
        if( !head){
            head = newnode;
            return;
        }
        
        LinkedNode* curr = head;
        while(curr->next) curr = curr->next;
        curr->next = newnode;
        
    }
    
    void addAtIndex(int index, int val) {
        if( size < index || index < 0){
            return;
        }
        size++;
        LinkedNode* dummy = new LinkedNode(0);
        dummy->next = head;
        LinkedNode* pre = dummy;
        LinkedNode* curr = head;
        LinkedNode* newnode = new LinkedNode(val);

        for(int i=0;i<index;i++){
            pre = curr;
            curr = curr->next;
        }
        pre->next = newnode;
        newnode->next = curr;
        head = dummy->next;
        return;

    }
    
    void deleteAtIndex(int index) {
         if( size <=  index || index < 0){
            return;
        }
        size--;
        LinkedNode* dummy = new LinkedNode(0);
        LinkedNode* pre = dummy;
        dummy->next = head;
        LinkedNode* curr = head;
        for(int i=0;i<index;i++){
            pre = curr;
            curr = curr->next;
        }
        pre->next = curr->next;
        delete curr;
        head = dummy->next;
        return;
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
 */707. Design Linked List
