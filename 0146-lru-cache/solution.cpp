class LRUCache {

    class Node{
    public:
        int key, val;
        Node *prev, *next;
        Node(int key = 0, int val = 0) {
            this->key = key;
            this->val = val;
            prev = next = NULL;
        }
    };

    size_t size;
    unordered_map<int, Node*> mpp;
    Node *head = NULL, *tail = NULL;
public:
    LRUCache(int capacity) {
        this->size = capacity;
    }
    
    int get(int key) {
        
        if(mpp.find(key) == mpp.end()) return -1;

        Node *temp = mpp[key];

        if(temp == head) return head->val;
        else if(temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            temp->prev = nullptr;
            head->prev = temp;
            temp->next = head;
            head = temp;
            return head->val;
        }

        Node *pv = temp -> prev, *nx = temp -> next;
        pv->next = nx; nx->prev = pv;

        head -> prev = temp;
        temp -> next = head;
        head = temp;
        temp->prev = NULL;

        return head->val;
    }
    
    
    void put(int key, int val) {
        if(size == 0) return;

        if(mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            temp->val = val;

            if(temp == head) return;

            if(temp == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            temp->prev = nullptr;
            temp->next = head;
            head->prev = temp;
            head = temp;
            return;
        }

        Node* temp = new Node(key, val);

        if(mpp.size() == size) {
            Node* old = tail;
            mpp.erase(old->key);

            if(head == tail) {
                head = tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
            }

            delete old;
        }

        mpp[key] = temp;

        if(!head) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */