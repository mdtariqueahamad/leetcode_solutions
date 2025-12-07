class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class MyStack {
    int size;
    Node* head;
public:
    MyStack(){
        head = nullptr;
        size = 0;
    }
    
    void push(int x){
       Node *temp = new Node(x);
       temp -> next = head;
       head = temp;
       size++;
    }
    
    int pop(){
        if(!size) return -1;
        Node *temp = head;
        int x = head -> data;
        head = head -> next;
        delete temp;
        size--;
        return x;
    }
    
    int top(){
        return head -> data;
    }
    
    bool empty(){
        return size == 0;
    }
};
