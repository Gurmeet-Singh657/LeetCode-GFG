struct Node{
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class MyCircularQueue {
public:
    Node* head=NULL;
    Node* tail=NULL;
    int size=0;
    int currsize=0;
    MyCircularQueue(int k) {
        size=k;
    }
    
    bool enQueue(int value) {
        if(currsize==size) return false;
        Node* curr=new Node(value);
        if(head==NULL)
            head=tail=curr;
        else
        {
            tail->next=curr;
            tail=tail->next;
        }
        currsize++;
        return true;
    }
    
    bool deQueue() {
        if(currsize==0)
            return false;
        currsize--;
        if(head->next==NULL)
        {
            head=tail=NULL;
        }
        else
        {
            head=head->next;
        }
        return true;
    }
    
    int Front() {
        if(head==NULL)
            return -1;
        return head->data;
    }
    
    int Rear() {
        if(tail==NULL)
            return -1;
        return tail->data;
    }
    
    bool isEmpty() {
        return currsize==0;
    }
    
    bool isFull() {
        return size==currsize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */