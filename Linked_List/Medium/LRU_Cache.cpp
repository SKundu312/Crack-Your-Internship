
class LRUCache {
public:
class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v){
        key=k;
        val=v;
        prev=NULL;
        next=NULL;
    }
};
    int cap;
    unordered_map<int,Node*> m;
    Node* head =new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* newNode){
        Node* nextt=head->next;
        head->next=newNode;
        newNode->prev=head;

        newNode->next=nextt;
        nextt->prev=newNode;
    }

    void deleteNode(Node* x){
        Node* prevv=x->prev;
        Node* nextt=x->next;

        prevv->next=nextt;
        nextt->prev=prevv;
    }

    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* valNode=m[key];
            int ans=valNode->val;

            deleteNode(m[key]);
            addNode(m[key]);
            m.erase(key);

            m[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* n=new Node(key, value);
        if(m.find(key)!=m.end()){
            Node* dltNode=m[key];
            deleteNode(dltNode);
            m.erase(key);
        }

        if(m.size()==cap){
            Node* leastNode=tail->prev;
            m.erase(leastNode->key);
            deleteNode(leastNode);
        }
        addNode(n);
        m.insert({key,head->next});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
