class LRUCache {
public:
    class node {
      public:
      int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node * newnode) {
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deletenode(node * delnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        node* Node=mpp[key];
        deletenode(Node);
        addnode(Node);
        return Node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node* Node=mpp[key];
            Node->val=value;
            deletenode(Node);
            addnode(Node);
        }
        else{
            if(mpp.size()==cap){
                node* Node=tail->prev;
                mpp.erase(Node->key);
                deletenode(Node);
            }
            node* Node=new node(key,value);
            mpp[key]=Node;
            addnode(Node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */