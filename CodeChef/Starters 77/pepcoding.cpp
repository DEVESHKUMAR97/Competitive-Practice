#include<bits/stdc++.h>
using namespace std;

class LFUCache {
    class Node{
        public:
        int key, value, freq;
        Node* prev;
        Node* next;
        Node(int key, int value) {
            this -> key = key;
            this -> value = value;
            freq = 1;
            prev = NULL;
            next = NULL;
        }
    };
    class LinkedList {
        public:
        Node* head;
        Node* last;
        int size;
        LinkedList() {
            // dummy nodes
            head = new Node(-1, -1);
            last = new Node(-1, -1);
            head -> next = last;
            last -> prev = head;
            size = 0;
        }
    };
    // key -> freq
    unordered_map<int, Node*> keyFreqs;

    //freq -> linkedList
    map<int, LinkedList*> freqList;
    int capacity;
    int cacheSize;


public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        cacheSize = 0;
        keyFreqs.clear();
        freqList.clear();
    }

    // push front of a ll corresponding to freq
    void push_front(LinkedList* list, Node* node) {
        list -> size++;
        Node* head1 = list -> head;
        node -> next = head1 -> next;
        node -> prev = head1;
        head1 -> next = node;
        node -> next -> prev = node;
    }

    // remove argument node from current LL
    void remove_node(LinkedList* list, Node* node) {
        list->size--;
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    LinkedList* getLinkedList(int freq) {
        // create new LL for new frequency if not existed
        if(freqList.find(freq) == freqList.end()) {
            freqList[freq] = new LinkedList();
        }

        // get new LL for new frequency
        return freqList[freq];
    }

    // update the frequency of the node
    void update_freq(Node* node) {
        // getting LL from corresponding frequecy
        LinkedList* list = freqList[node->freq];

        // removing node from current LL
        remove_node(list, node); 

        // if size of current LL becomes zero then remove from freqList
        if(list->size == 0) {
            freqList.erase(node->freq);
        }

        // increment the frequecy of current node
        node->freq++;

        // get new LL for new frequency
        LinkedList* newList = getLinkedList(node->freq);

        // add the node in front of the new LL
        push_front(newList, node);
    }

    
    int get(int key) {
        if(keyFreqs.find(key) == keyFreqs.end()) return -1;

        // getting node for key
        Node* node = keyFreqs[key]; 

        // update the frequency
        update_freq(node);
        
        // return the node value
        return node->value; 
    }
    
    void put(int key, int value) {
        // if this key already present
        if(keyFreqs.find(key) != keyFreqs.end()) {
            // getting node for key
            Node* node = keyFreqs[key]; 

            // update the frequency
            update_freq(node);
            node -> value = value;
            return;
        } else {
            // create new node and store in map
            Node* node = new Node(key, value);
            keyFreqs[key] = node;

            // if cacheSize is less than capacity
            if(cacheSize < capacity) {
                cacheSize++;
                // get new LL for new frequency
                LinkedList* list = getLinkedList(node->freq);

                // push node in the front the LL
                push_front(list, node);
            } else {
                // remove least frequent and least recently
                int leastFreq = freqList.begin() -> first;
                LinkedList*  leastFreqList = freqList[leastFreq];
                
                // least frequent and least recently used node
                Node* oldNode = leastFreqList -> last -> prev;
                remove_node(leastFreqList, oldNode);

                // if size of current LL becomes zero then remove from freqList
                if(leastFreqList->size == 0) {
                    freqList.erase(oldNode->freq);
                }

                // remove this key also
                keyFreqs.erase(oldNode->key);


                // get new LL for new frequency
                LinkedList* list = getLinkedList(node->freq);

                // push node in the front the LL
                push_front(list, node);

            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LFUCache* lfu = new LFUCache(2);
    lfu-> put(1, 1);
    lfu-> put(2, 2);
    cout << lfu -> get(1) << endl;
    lfu-> put(3, 3);
    // cout << lfu -> get(2) << endl;
    // cout << lfu -> get(3) << endl;
    cout << "hello";
    return 0;
}