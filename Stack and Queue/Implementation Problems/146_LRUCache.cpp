class LRUCache {
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
    };

public:
    unordered_map<int, Node*> mp;
    int capacity;
    Node *head, *tail;

    void insertAfterHead(Node* add) {
        Node* temp = head->next;
        head->next = add;
        add->prev = head;
        add->next = temp;
        temp->prev = add;
    }

    void deleteNode(Node* add) {
        Node* p = add->prev;
        Node* n = add->next;
        p->next = n;
        n->prev = p;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val; // ✅ return value, not key
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if ((int)mp.size() == capacity) {
                Node* node = tail->prev;
                mp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* node = new Node(key, value);
            insertAfterHead(node);
            mp[key] = node;
        }
    }
};
