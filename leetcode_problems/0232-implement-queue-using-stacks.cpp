// LeetCode Problem 0232: Implement Queue using Stacks
// Difficulty: Easy
// Link: https://leetcode.com/problems/implement-queue-using-stacks/
// Language: cpp

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};
class MyQueue {
    int size;
    Node *head, *tail;
public:
    MyQueue(){
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void push(int x){
        if(!size){
            Node *newNode = new Node(x);
            head = newNode;
            tail = head;
        } else{
            tail -> next = new Node(x);
            tail = tail -> next;
        }
        size++;
    }
    
    int pop(){
        if(!size) return -1;
        Node *temp = head;
        head = head -> next;
        int x = temp -> data;
        size--;
        return x;
    }
    
    int peek(){
        return head -> data;
    }
    
    bool empty(){
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */