//
// Created by john on 15/3/18.
//

#ifndef LINTCODE_SOLUTIONCLASSES_H
#define LINTCODE_SOLUTIONCLASSES_H

#include <iostream>
#include <set>
#include <queue>

using namespace std;

template <typename T>
struct ListNode{
    T val;
    ListNode<T>* next;
};

template <typename T>
class Solution_0_List {
public:
    Solution_0_List(){};
    ~Solution_0_List(){};

    ListNode<T>* construct(int len);
    ListNode<T>* insert(ListNode<T>* head, T val, int index);
    ListNode<T>* remove(ListNode<T>* head, int index);
    ListNode<T>* reverseList(ListNode<T>* head);
    void printList(ListNode<T>* head);
    void printReverseList(ListNode<T>* head);
    int getListLen(ListNode<T>* head);
    bool hasCircle(ListNode<T>* head);
};

template <typename T>
struct TreeNode {
    T key;

    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T key){
        this->key = key;
    }
    ~TreeNode(){};
};

template<typename T>
class Solution_1_Tree {
public:
    TreeNode<T> *root;
public:
    Solution_1_Tree(){
        root = nullptr;
    }
    ~Solution_1_Tree(){}

    void insert(T key);
    void insert(T key, TreeNode<T>*& root);
    void del(T key, TreeNode<T>*& root);
    void preOrder(TreeNode<T>* root);
    void inOrder(TreeNode<T>* root);
    void postOrder(TreeNode<T>* root);
    void layerOrder(TreeNode<T>* root);
    bool isFound(T key, TreeNode<T>* root);
    TreeNode<T>* findMin(TreeNode<T>* root);
    int countNumOfNodes(TreeNode<T>* root);
    int heightOfTree(TreeNode<T>* root);

    TreeNode<T>* transformToList(TreeNode<T>* root);

private:
    TreeNode<T>* transformToListImpl(TreeNode<T>* root, TreeNode<T>*& pHead, TreeNode<T>*& pTail);
};

// Solution_0
template <typename T>
ListNode<T>* Solution_0_List<T>::construct(int len) {
    ListNode<T> *head = new ListNode<T>;
    ListNode<T> *ptr = head;
    ptr->val = 0;
    ptr->next = NULL;

    for (int i = 1; i < len; ++i) {
        ListNode<int>* node = new ListNode<T>;
        ptr->next = node;
        ptr = ptr->next;

        ptr->val = i;
        ptr->next = NULL;
    }
    return head;
}
// insert num after node index
template <typename T>
ListNode<T>* Solution_0_List<T>::insert(ListNode<T>* head, T val, int index) {
    ListNode<T>* ptr = head;
    int idx = 0;
    while(idx < index && ptr != NULL) {
        idx++;
        ptr = ptr->next;
    }
    if(idx == index && ptr != NULL) {
        ListNode<T>* newNode = new ListNode<T>;
        newNode->next = ptr->next;
        ptr->next = newNode;
        newNode->val = val;
        cout << "Insertion successful!" << endl;
    } else {
        cout << "Out of index" << endl;
    }
    return head;
}

template <typename T>
ListNode<T>* Solution_0_List<T>::remove(ListNode<T>* head, int index) {
    ListNode<T>* ptr = head;
    int idx = 0;
    if(index == 0) { // remove head node
        head = head->next;
        delete ptr;
    }
    else { // remove following nodes
        while (idx < index - 1 && ptr->next) {
            idx++;
            ptr = ptr->next;
        }
        if (idx == index - 1 && ptr->next) {
            ListNode<T>* tempPtr = ptr->next;
            ptr->next = ptr->next->next;
            delete tempPtr;
        } else {
            cout << "Out of index" << endl;
        }
    }
    return head;
}

template <typename T>
ListNode<T>* Solution_0_List<T>::reverseList(ListNode<T> *head) {
    ListNode<T>* newHead = nullptr;

    if(head == nullptr || head->next == nullptr)
        newHead = head;
    else {
        ListNode<T>* prevPtr = head;
        ListNode<T>* nextPtr = prevPtr->next;
        head->next = nullptr;

        while (nextPtr != nullptr) {
            ListNode<T>* tempPtr = nextPtr->next;
            nextPtr->next = prevPtr;
            prevPtr = nextPtr;
            nextPtr = tempPtr;
        }
        newHead = prevPtr;
    }
    return newHead;
}

template <typename T>
void Solution_0_List<T>::printList(ListNode<T> *head) {
    if (head == NULL) {
        cout << "Empty list" << endl;
    } else {
        ListNode<T> *ptr = head;
        while (ptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
    }
    cout << endl;
}

template <typename T>
void Solution_0_List<T>::printReverseList(ListNode<T> *head) {
    if(head != nullptr) {
        printReverseList(head->next);
        cout << head->val << " ";
    }
}

template <typename T>
int Solution_0_List<T>::getListLen(ListNode<T> *head) {
    ListNode<T>* ptr = head;
    int len = 0;
    while(ptr) {
        len++;
        ptr = ptr->next;
    }
    return len;
}

template <typename T>
bool Solution_0_List<T>::hasCircle(ListNode<T> *head) {
    if(head == nullptr || head->next == nullptr) return false;
    else {
        ListNode<T>* fastPtr, *slowPtr = head;
        while(fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(fastPtr == slowPtr)
                return true;
        }
        return false;
    }
}

// Solution_1
template <typename T>
void Solution_1_Tree<T>::insert(T key, TreeNode<T>*& root) {
    if(this->root == nullptr) {
        this->root = new TreeNode<T>(key);
    } else {
        if(root == nullptr) {
            root = new TreeNode<T>(key);
        } else if(key < root->key) {
            insert(key, root->left);
        } else if(key > root->key) {
            insert(key, root->right);
        }
    }
}

template <typename T>
void Solution_1_Tree<T>::preOrder(TreeNode<T>* root) {
    if(this->root == nullptr) {
        cout << "Empty tree!" << endl;
    } else {
        if (root != nullptr) {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
}

template <typename T>
void Solution_1_Tree<T>::inOrder(TreeNode<T>* root) {
    if(this->root == nullptr) {
        cout << "Empty tree!" << endl;
    } else {
        if(root != nullptr) {
            inOrder(root->left);
            cout << root->key << " ";
            inOrder(root->right);
        }
    }
}

template <typename T>
void Solution_1_Tree<T>::postOrder(TreeNode<T> *root) {
    if(this->root == nullptr) {
        cout << "Empty tree!" << endl;
    } else {
        if(root != nullptr) {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->key << " ";
        }
    }
}

template <typename T>
bool Solution_1_Tree<T>::isFound(T key, TreeNode<T>* root) {
    if (this->root == nullptr) return false;
    else if(root == nullptr) return false;
    else if(key < root->key) return isFound(key, root->left);
    else if(key > root->key) isFound(key, root->right);
    else return true;
}

template <typename T>
TreeNode<T>* Solution_1_Tree<T>::findMin(TreeNode<T> *root) {
    if(root->left != nullptr) return findMin(root->left);
    else return root;
}

template <typename T>
void Solution_1_Tree<T>::del(T key, TreeNode<T>*& root) {
    if(this->root == nullptr) cout << "Empty tree!" << endl;
    else if(root == nullptr) cout << "Not found" << endl;
    else if(key < root->key) del(key, root->left);
    else if(key > root->key) del(key, root->right);
    else {
        if(root->left == nullptr && root->right == nullptr) {
            TreeNode<T>* ptr = root;
            root = nullptr;
            delete ptr;
        }
        else if(root->left != nullptr && root->right != nullptr) {
            root->key = findMin(root->right)->key;
            del(root->key, root->right);
        }
        else {
            TreeNode<T>* ptr = root;
            root = (root->left == nullptr ? root->right : root->left);
            delete ptr;
        }
    }
}

template <typename T>
int Solution_1_Tree<T>::countNumOfNodes(TreeNode<T> *root) {
    if(this->root == nullptr)
        return 0;
    else {
//        if(root != nullptr) {
//            return 1 + countNumOfNodes(root->left) + countNumOfNodes(root->right);
//        }
//        else return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        else if (root->left != nullptr && root->right != nullptr)
            return 1 + countNumOfNodes(root->right) + countNumOfNodes(root->left);
        else
            return 1 + (root->left == nullptr ? (countNumOfNodes(root->right)) : (countNumOfNodes(root->left)));
    }
}

template <typename T>
int Solution_1_Tree<T>::heightOfTree(TreeNode<T> *root) {
    if(this->root == nullptr)
        return 0;
    else {
        if (root != nullptr) {
            return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
        }
        else return 0;
    }
}

template <typename T>
void Solution_1_Tree<T>::layerOrder(TreeNode<T> *root) {
    if(this->root == nullptr)
        cout << "Empty tree!" << endl;
    else {
        queue<TreeNode<T>*> queue;
        queue.push(root);
        while(!queue.empty()) {
            TreeNode<T>* treeNode = queue.front();
            cout << treeNode->key << " ";
            queue.pop();

            if (treeNode->left != nullptr)
                queue.push(treeNode->left);
            if (treeNode->right != nullptr)
                queue.push(treeNode->right);
        }
    }
}

template <typename T>
TreeNode<T>* Solution_1_Tree<T>::transformToListImpl(TreeNode<T> *root, TreeNode<T> *&pHead, TreeNode<T> *&pTail) {
    if (root == nullptr) {
        pHead = nullptr;
        pTail = nullptr;
    }
    else if (root->left == nullptr && root->right != nullptr) {
        pHead = root;
        transformToListImpl(root->right, pHead, pTail);
    }
    else if (root->left != nullptr && root->right == nullptr) {
        pHead = root->left;
        pTail = root;
    }
    else {
        transformToListImpl(root->left, pHead, root);
        transformToListImpl(root->right, root->right, pTail);
    }
}

template <typename T>
TreeNode<T>* Solution_1_Tree<T>::transformToList(TreeNode<T> *root) {
    if(this->root == nullptr) return nullptr;
    else {
        TreeNode<T> *pHead, *pTail = nullptr;
        return transformToListImpl(this->root, pHead, pTail);
    }
}
#endif //LINTCODE_SOLUTIONCLASSES_H
