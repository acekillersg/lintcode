//
// Created by john on 15/3/18.
//

#ifndef LINTCODE_SOLUTIONCLASSES_H
#define LINTCODE_SOLUTIONCLASSES_H

#include <iostream>
#include <set>
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
    void printList(ListNode<T>* head);
    int getListLen(ListNode<T>* head);
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
    void del(T key);
    void preOrder(TreeNode<T>* root);
    void inOrder(TreeNode<T>* root);
    void postOrder(TreeNode<T>* root);
    void layerOrder(TreeNode<T>* root);
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
int Solution_0_List<T>::getListLen(ListNode<T> *head) {
    ListNode<T>* ptr = head;
    int len = 0;
    while(ptr) {
        len++;
        ptr = ptr->next;
    }
    return len;
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
void Solution_1_Tree<T>::inOrder(TreeNode<T>* root) {
    if(this->root == nullptr) {
        cout << "Empty tree!" << endl;
    } else {
        if(root->left != nullptr) {
            inOrder(root->left);
        }
        cout << root->key << " ";
        if(root->right != nullptr) {
            inOrder(root->right);
        }
    }
}

template <typename T>
void Solution_1_Tree<T>::preOrder(TreeNode<T>* root) {
    if(this->root == nullptr) {
        cout << "Empty tree!" << endl;
    } else {
        cout << root->key << " ";
        if(root->left != nullptr) {
            preOrder(root->left);
        }
        if(root->right != nullptr) {
            preOrder(root->right);
        }
    }
}

template <typename T>
void Solution_1_Tree<T>::postOrder(TreeNode<T> *root) {
    if(this->root == nullptr) {
        cout << "Empty tree!" << endl;
    } else {
        if(root->left != nullptr) {
            postOrder(root->left);
        }
        if(root->right != nullptr) {
            postOrder(root->right);
        }
        cout << root->key << " ";
    }
}

template <typename T>
void Solution_1_Tree<T>::del(T key) {

}

#endif //LINTCODE_SOLUTIONCLASSES_H
