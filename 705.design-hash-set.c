/*
 * @lc app=leetcode id=705 lang=c
 *
 * [705] Design HashSet
 */

// @lc code=start



typedef struct {
    bool value;
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet *table = calloc(1000001, sizeof(MyHashSet));
    return table;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (!obj) {
        return;
    }
    obj[key].value = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if (!obj) {
        return;
    }
    obj[key].value = false;
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    if (!obj) {
        return;
    }
    return obj[key].value;
}

void myHashSetFree(MyHashSet* obj) {
    if (!obj) {
        return;
    }
    free(obj);
    obj = NULL;
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/
// @lc code=end

