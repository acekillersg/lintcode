//
// Created by john on 13/3/18.
//
#include <vector>
#include "SolutionClasses.h"

using namespace std;

//// Solution_0
//ListNode* Solution_0_List::construct(int len) {
//    ListNode *head = new ListNode;
//    ListNode *ptr = head;
//    ptr->val = 0;
//    ptr->next = NULL;
//
//    for (int i = 1; i < len; ++i) {
//        ListNode* node = new ListNode;
//        ptr->next = node;
//        ptr = ptr->next;
//
//        ptr->val = i;
//        ptr->next = NULL;
//    }
//    return head;
//}
//// insert num after node index
//ListNode* Solution_0_List::insert(ListNode* head, int num, int index) {
//    ListNode* ptr = head;
//    int idx = 0;
//    while(idx < index && ptr != NULL) {
//        idx++;
//        ptr = ptr->next;
//    }
//    if(idx == index && ptr != NULL) {
//        ListNode* newNode = new ListNode;
//        newNode->next = ptr->next;
//        ptr->next = newNode;
//        newNode->val = num;
//        cout << "Insertion successful!" << endl;
//    } else {
//        cout << "Out of index" << endl;
//    }
//    return head;
//}
//
//ListNode* Solution_0_List::remove(ListNode* head, int index) {
//    ListNode* ptr = head;
//    int idx = 0;
//    if(index == 0) { // remove head node
//        head = head->next;
//        delete ptr;
//    }
//    else { // remove following nodes
//        while (idx < index - 1 && ptr->next) {
//            idx++;
//            ptr = ptr->next;
//        }
//        if (idx == index - 1 && ptr->next) {
//            ListNode* tempPtr = ptr->next;
//            ptr->next = ptr->next->next;
//            delete tempPtr;
//        } else {
//            cout << "Out of index" << endl;
//        }
//    }
//    return head;
//}
//
//void Solution_0_List::printList(ListNode *head) {
//    if (head == NULL) {
//        cout << "Empty list" << endl;
//    } else {
//        ListNode *ptr = head;
//        while (ptr) {
//            cout << ptr->val << " ";
//            ptr = ptr->next;
//        }
//    }
//    cout << endl;
//}
//
//int Solution_0_List::getListLen(ListNode *head) {
//    ListNode* ptr = head;
//    int len = 0;
//    while(ptr) {
//        len++;
//        ptr = ptr->next;
//    }
//    return len;
//}
//
//// Solution_1
//template <class K, class V>
//void Solution_1_Tree<K, V>::insert(K key, V val, TreeNode<K, V>* root) {
//    if(this->root == nullptr) {
//        this->root = new TreeNode<K, V>(key, val);
//    }
//    else {
//        TreeNode<K, V>* ptr = this->root;
//        if(key < ptr->key) {
//            if(ptr->left == nullptr)
//                ptr->left = new TreeNode<K, V>(key, val);
//            else
//                insert(key, val, ptr->left);
//        }
//        else if(key == ptr->key) {
//            ptr->vSet.insert(val);
//        }
//        else {
//            if(key > ptr->key) {
//                if(ptr->right == nullptr)
//                    ptr->right = new TreeNode<K, V>(key, val);
//                else
//                    insert(key, val, ptr->right);
//            }
//        }
//    }
//}
//
//template <class K, class V>
//void Solution_1_Tree<K, V>::inOrder(TreeNode<K, V>* root) {
//    if(this->root == nullptr) {
//        cout << "Empty tree!" << endl;
//    }
//    else {
//        TreeNode<K, V>* parentPtr = root;
//        if(root->left != nullptr) {
//            inOrder(root->left);
//        }
//        else cout << root->key << " " << endl;
//
//        cout << parentPtr->key << " " << endl;
//
//        if(root->right != nullptr) {
//            inOrder(root->right);
//        }
//        else cout << root->key << " " << endl;
//    }
//}