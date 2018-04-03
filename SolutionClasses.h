//
// Created by john on 15/3/18.
//

#ifndef LINTCODE_SOLUTIONCLASSES_H
#define LINTCODE_SOLUTIONCLASSES_H

#include <iostream>
#include <set>
#include <queue>
#include <string>

using namespace std;

template <typename T>
struct ListNode{
    T val;
    ListNode<T>* next;
    ListNode() : val(0), next(nullptr){}
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

    TreeNode(T key) : left(nullptr), right(nullptr) {
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
    void transformToList(TreeNode<T>* root, TreeNode<T>*& pHead, TreeNode<T>*& pTail);
    int countNumOfNodesAtK(TreeNode<T>* root, int k);
    int countNumOfNodesAtK_Recursive(TreeNode<T>* root, int k);
    int countNumOfNodesAtLeaves(TreeNode<T>* root);
    bool compareTrees(TreeNode<T>* root1, TreeNode<T>* root2);
    bool isAVLTree(TreeNode<T>* root);
    void flipTree(TreeNode<T>* root);
    int maxDistanceInTree(TreeNode<T> *root, int &maxLeftToRoot, int &maxRightToRoot);
    void generate_interact(TreeNode<T>*& root);
    void generate_pre_order(TreeNode<T>*& root);
    void regenerate(TreeNode<T>*& root);

private:
    void generate_pre_order_impl(TreeNode<T>*& root, string str, int& idx);
    void regenerate_impl(TreeNode<T>*& root, string in, string post);
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
void Solution_1_Tree<T>::transformToList(TreeNode<T> *root, TreeNode<T>*& pHead, TreeNode<T>*& pTail) {
    if(this->root == nullptr) {
        pHead = nullptr;
        pTail = nullptr;
    }
    else {
        TreeNode<T>* pLeftTreeHead, *pLeftTreeTail, *pRightTreeHead, *pRightTreeTail = nullptr;
        if (root == nullptr) {
            pHead = nullptr;
            pTail = nullptr;
        }
        else {
            if (root->left == nullptr)
                pHead = root;
            else {
                transformToList(root->left, pLeftTreeHead, pLeftTreeTail);
                pHead = pLeftTreeHead;
                root->left = pLeftTreeTail;
                pLeftTreeTail->right = root;
            }
            if (root->right == nullptr)
                pTail = root;
            else {
                transformToList(root->right, pRightTreeHead, pRightTreeTail);
                pTail = pRightTreeTail;
                root->right = pRightTreeHead;
                pRightTreeHead->left = root;
            }
        }
    }
}

template <typename T>
struct TreeNodeQueue {
    TreeNode<T>* treeNode;
    int layer;
    TreeNodeQueue(TreeNode<T>* treeNode, int layer) {
        this->treeNode = treeNode;
        this->layer = layer;
    }
};

template <typename T>
int Solution_1_Tree<T>::countNumOfNodesAtK(TreeNode<T> *root, int k) {
    if (heightOfTree(this->root) < k || k < 1) {
        cout << "Invalid k value!" << endl;
        return 0;
    }
    else {
        queue<TreeNodeQueue<T>*> treeNodeQueue;
        TreeNode<T>* ptr = root;
        treeNodeQueue.push(new TreeNodeQueue<T>(ptr, 1));
        TreeNodeQueue<T>* frontNode = treeNodeQueue.front();
        while (frontNode->layer < k) {
            if (frontNode->treeNode->left != nullptr)
                treeNodeQueue.push(new TreeNodeQueue<T>(frontNode->treeNode->left, frontNode->layer + 1));
            if (frontNode->treeNode->right != nullptr)
                treeNodeQueue.push(new TreeNodeQueue<T>(frontNode->treeNode->right, frontNode->layer + 1));
            treeNodeQueue.pop();
            frontNode = treeNodeQueue.front();
        }
        return treeNodeQueue.size();
    }
}

template <typename T>
int Solution_1_Tree<T>::countNumOfNodesAtK_Recursive(TreeNode<T> *root, int k) {
    if (heightOfTree(this->root) < k || k < 1) {
        cout << "Invalid k value!" << endl;
        return 0;
    }
    else {
        if (root == nullptr || k < 1) return 0;
        if (k == 1) return 1;
        else return countNumOfNodesAtK_Recursive(root->left, k - 1) + countNumOfNodesAtK_Recursive(root->right, k - 1);
    }
}

template <typename T>
int Solution_1_Tree<T>::countNumOfNodesAtLeaves(TreeNode<T> *root) {
    if (this->root == nullptr) {
        cout << "Empty tree!" << endl;
        return 0;
    }
    else {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        else
            return countNumOfNodesAtLeaves(root->left) + countNumOfNodesAtLeaves(root->right);
    }
}

template <typename T>
bool Solution_1_Tree<T>::compareTrees(TreeNode<T> *root1, TreeNode<T> *root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    else if (root1 == nullptr && root2 != nullptr) return false;
    else if (root1 != nullptr && root2 == nullptr) return false;
    else
        return compareTrees(root1->left, root2->left) && compareTrees(root1->right, root2->right);

}

template <typename T>
bool Solution_1_Tree<T>::isAVLTree(TreeNode<T> *root) {
    if (this->root == nullptr) return true;
    else {
        if (root == nullptr) return true;
        else if ((isAVLTree(root->left) && isAVLTree(root->right)) == false) {
            return false;
        }
        else {
            int leftTreeHeight = heightOfTree(root->left);
            int rightTreeHeight = heightOfTree(root->right);
            if (abs(leftTreeHeight - rightTreeHeight) > 1) return false;
            else return true;
        }
    }
}

template <typename T>
void Solution_1_Tree<T>::flipTree(TreeNode<T> *root) {
    if (root != nullptr) {
        TreeNode<T>* temp = root->left;
        root->left = root->right;
        root->right = temp;
        flipTree(root->left);
        flipTree(root->right);
    }
}

/**
 *
 * @tparam T
 * @param root current root node of tree (subtree)
 * @param maxLeftToRoot longest distance to current root from current root's left subtree
 * @param maxRightToRoot longest distance to current root from current root's right subtree
 * @return the value of longest distance in the tree
 */
template <typename T>
int Solution_1_Tree<T>::maxDistanceInTree(TreeNode<T> *root, int& maxLeftToRoot, int& maxRightToRoot) {
    if (this->root == nullptr) {
        return 0;
    }
    else {
        // ll: max distance to left child node from left child node's left sub-tree
        // lr: max distance to left child node from left child node's right sub-tree
        // rl: max distance to right child node from right child node's left sub-tree
        // rr: max distance to right child node from right child node's right sub-tree
        int ll = 0, lr = 0, rl = 0, rr = 0;
        int maxLeftDist, maxRightDist;
        if (root == nullptr) {
            maxLeftToRoot = 0;
            maxRightToRoot = 0;
            maxLeftDist = 0;
            maxRightDist = 0;
        }
        else {
            if (root->left != nullptr) {
                maxLeftDist = maxDistanceInTree(root->left, ll, lr);
                maxLeftToRoot = max(ll, lr) + 1;
            } else {
                maxLeftDist = 0;
                maxLeftToRoot = 0;
            }
            if (root->right != nullptr) {
                maxRightDist = maxDistanceInTree(root->right, rl, rr);
                maxRightToRoot = max(rl, rr) + 1;
            } else {
                maxRightDist = 0;
                maxRightToRoot = 0;
            }
        }
        return max((maxLeftDist, maxRightDist), maxLeftToRoot + maxRightToRoot);
    }
}

template <typename T>
void Solution_1_Tree<T>::generate_interact(TreeNode<T>*& root) {
    T val = 0;
    cout << "Please input value of root node: ";
    cin >> val;
    if (val != -1) {
        root = new TreeNode<T>(val);

        cout << "Creating left sub tree!" << endl;
        generate_interact(root->left);

        cout << "Creating right sub tree!" << endl;
        generate_interact(root->right);
    }
}

template <typename T>
void Solution_1_Tree<T>::generate_pre_order(TreeNode<T>*& root) {
    string str;
    cout << "Input the string of values in pre-order: ";
    cin.ignore();
    getline(cin, str);
    int idx = 0;
    generate_pre_order_impl(this->root, str, idx);
}

template <typename T>
void Solution_1_Tree<T>::generate_pre_order_impl(TreeNode<T> *&root, string str, int& idx) {
    if (idx < str.length()) {
        if (str.at(idx) == '#') root = nullptr;
        else {
            root = new TreeNode<T>(str.at(idx));
            generate_pre_order_impl(root->left, str, ++idx);
            generate_pre_order_impl(root->right, str, ++idx);
        }
    }
}

template <typename T>
void Solution_1_Tree<T>::regenerate(TreeNode<T>*& root) {
    string in, post;
    cout << endl << "Input the string of values in in-order and post-order, respectively" << endl;
    cout << "In-order: ";
    getline(cin, in);
    cout << "Post-order: ";
    getline(cin, post);
    if (in.empty() || post.empty() || in.length() != post.length())
        cout << __FILE__ << "(" << __LINE__ << "): " << "incorrect input!" << endl;
    else
        regenerate_impl(this->root, in, post);
}

template <typename T>
void Solution_1_Tree<T>::regenerate_impl(TreeNode<T> *&root, string in, string post) {
    if (!in.empty() && !post.empty()) {
        char root_val = post.back();
        int root_pos = in.find_first_of(root_val);
        if (root_pos == string::npos) {
            cout << __FILE__ << " (" << __LINE__ << "): " << "incorrect input!" << endl;
        } else {

            root = new TreeNode<T>(root_val);

            if (in.length() > 1) {
                string in_left = in.substr(0, root_pos);
                string in_right = in.substr(root_pos + 1, in.length() - 1);
                string post_left = post.substr(0, in_left.length());
                string post_right = post.substr(post_left.length(), in_right.length());

                regenerate_impl(root->left, in_left, post_left);
                regenerate_impl(root->right, in_right, post_right);
            }
        }
    }
}
#endif //LINTCODE_SOLUTIONCLASSES_H