class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};
class MinStack{
    int size, m;
    Node *head;
public:
    MinStack(){
        size = 0;
        head = NULL;
    }
    
    void push(int x) {
        Node *newNode = new Node(x);
        newNode -> next = head;
        head = newNode;
        m = size ? min(m,x) : x;
        size++;
    }
    
    void pop(){
        Node *temp = head;
        head = head -> next;
        if(temp -> data == m){
            Node *t = head;
            m = INT_MAX;
            while(t != NULL){
                m = min(m, t -> data);
                t = t -> next;
            }
        }
        delete temp;
        size--;
    }
    
    int top(){
        return head -> data;
    }
    
    int getMin(){
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
