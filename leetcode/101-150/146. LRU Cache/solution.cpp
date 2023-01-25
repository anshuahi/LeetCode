
class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        data = d;
        next = prev = NULL;
    }
};

void printAll(Node*  r){
    while(r){
        cout << r->data << " ";
        r = r->next;
    }
    cout << endl;
}


class LRUCache {
public:
    map<int, int> mp;
    unordered_map<int, Node*> np;
    Node* st, *en;
    int n;
    int count;

    LRUCache(int capacity) {
        n = capacity;
        en = NULL; st = NULL;
        count = 0;
    }

    void insert(int k){
        if(!en) {
            en = new Node(k);
            st = en;
            np[k] = st;
            return;
        }
        Node* p = new Node(k);
        en->next = p;
        p->prev = en;
        en = p;
        np[k] = p;
    }

    void update(int key){

        if(st == en){
            return;
        }
        
        Node* p = np[key];
        if(!p){
            return;
        }
        // cout << "first ";
        // printAll(st);
        if(p == st){
            st = st->next;
            if(st)
                st->prev = NULL;
        }
        else if(p != en) {
            Node* pre = p->prev;
            if(pre){
                pre->next = p->next;
                pre->next->prev = pre;
            }
        }
        else {
            return;
        }

        insert(key);
        
        // Node* z = new Node(key);
        // en->next = z;
        // z->prev = en;
        // en = z;
        // np[key] = z;
        
        // cout << "last ";
        // printAll(st);
    }

    // void deleteNode()

    int get(int key) {
        if(n == 1){
            if(st && st->data == key){
                return mp[key];
            }
            return -1;
        }
        // cout << key << " get ---- \t" ;printAll(st);
        if(mp.find(key) != mp.end()){
            if(mp[key] == -1){
                return -1;
            }
            update(key);
            // printAll(st);
            return mp[key];
        }
        return -1;
    }
    void put(int key, int value) {
        if(n == 1){
            if( st && st->data == key){
                mp[key] = value;
                return;
            }
            st = new Node(key);
            en = st;
            // st->data = key;
            mp[key] = value;
            return ;
        }
        if(mp.find(key) != mp.end()){
            if(mp[key] != -1){
                // continue;
                update(key);
                mp[key] = value;
                return ;
            }
        }
        if(count < n){
            
            // cout << key << " put \t" ;
            insert(key);
            // printAll(st);
            mp[key] = value;
        }
        else {
            // cout << key << " \t" ;
            // printAll(st);
            if(st){
                mp[st->data] = -1;
                np[st->data] = NULL;
                st = st->next;
                if(st)
                    st->prev = NULL;                
            }
            insert(key);
            mp[key] = value;
        }
        count++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */