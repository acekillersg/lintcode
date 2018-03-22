#include <iostream>
#include <bitset>
#include "SolutionClasses.h"
#include "Algorithms.h"

using namespace std;

int main(int argc, char** argv) {
    int problemID = 1;
    switch(problemID) {
        case 0: {
            Solution_0_List<int >* solution0 = new Solution_0_List<int>();
            cout << "Solving problem " << problemID << endl;

            cout << "construct a new list: " << endl;
            ListNode<int> *list = solution0->construct(10);
            solution0->printList(list);

            cout << "insert a new node into list: " << endl;
            list = solution0->insert(list, 100, 1);
            solution0->printList(list);

            cout << "remove a node from the list: " << endl;
            list = solution0->remove(list,0);
            solution0->printList(list);

            cout << "reverse the list: " << endl;
            list = solution0->reverseList(list);
            solution0->printList(list);

            cout << "print list from the end to head: " << endl;
            solution0->printReverseList(list);
            break;
        }
        case 1: {
            Solution_1_Tree<int>* solution1 = new Solution_1_Tree<int>();
            cout << "Solving problem " << problemID << endl;
            solution1->insert(3, solution1->root);
            solution1->insert(6, solution1->root);
            solution1->insert(4, solution1->root);
            solution1->insert(7, solution1->root);
            solution1->insert(9, solution1->root);
            solution1->insert(2, solution1->root);
            solution1->insert(13, solution1->root);
            solution1->insert(16, solution1->root);
            solution1->insert(14, solution1->root);
            solution1->insert(17, solution1->root);
            solution1->insert(19, solution1->root);
            solution1->insert(12, solution1->root);

            Solution_1_Tree<int>* solution2 = new Solution_1_Tree<int>();
            cout << "Solving problem " << problemID << endl;
            solution2->insert(3, solution2->root);
            solution2->insert(6, solution2->root);
            solution2->insert(2, solution2->root);
            solution2->insert(7, solution2->root);
            solution2->insert(9, solution2->root);
//            solution2->insert(2, solution2->root);
//            solution2->insert(13, solution2->root);
//            solution2->insert(16, solution2->root);
//            solution2->insert(14, solution2->root);
//            solution2->insert(17, solution2->root);
//            solution2->insert(19, solution2->root);
//            solution2->insert(12, solution2->root);

            cout << "visit in pre-order:";
            solution1->preOrder(solution1->root);

            cout << endl << "visit in in-order:";
            solution1->inOrder(solution1->root);

            cout << endl <<  "visit in post-order:";
            solution1->postOrder(solution1->root);

            cout << endl << "find certain key: ";
            cout << solution1->isFound(9, solution1->root);

//            cout << endl << "delete key: 7";
//            solution1->del(7, solution1->root);
//
//            cout << endl << "visit in in-order:";
//            solution1->inOrder(solution1->root);
//
//            cout << endl << "visit in pre-order:";
//            solution1->preOrder(solution1->root);
//
//            cout << endl <<  "visit in post-order:";
//            solution1->postOrder(solution1->root);
//
            cout << endl <<  "visit in layer-order:";
            solution1->layerOrder(solution1->root);
//
//            cout << endl << "delete key: 19";
//            solution1->del(19, solution1->root);

            cout << endl << "count of nodes in tree: ";
            cout << solution1->countNumOfNodes(solution1->root);

            cout << endl << "height of tree: ";
            cout << solution1->heightOfTree(solution1->root);

            cout << endl << "Compare two trees: ";
            cout << ((solution1->compareTrees(solution1->root, solution2->root)) ? "Yes" : "No");

            cout << endl << "count of nodes at certain layer (normal): ";
            for (int i = 1; i <= 8; ++i) {
                cout << solution1->countNumOfNodesAtK(solution1->root, i) << " ";
            }

            cout << endl << "count of nodes at certain layer (recursive): ";
            for (int i = 1; i <= 8; ++i) {
                cout << solution1->countNumOfNodesAtK_Recursive(solution1->root, i) << " ";
            }

            solution1->del(14, solution1->root);
            cout << endl << "count of nodes at certain layer (leaves): ";
            cout << solution1->countNumOfNodesAtLeaves(solution1->root) << " ";

            cout << endl << "is balanced tree: ";
            cout << (solution1->isAVLTree(solution2->root) ? "Yes" : "No") << " ";

            cout << endl << "flip a tree";
            solution2->flipTree(solution2->root);

            cout << endl << "visit in in-order: ";
            solution2->inOrder(solution2->root);

            cout << endl << "visit in pre-order: ";
            solution2->preOrder(solution2->root);

            cout << endl << "visit in post-order: ";
            solution2->postOrder(solution2->root);


//            cout << endl << "transform to list: ";
//            TreeNode<int> *pHead, *pTail, *ptr = nullptr;
//            solution1->transformToList(solution1->root, pHead, pTail);
//            ptr = pHead;
//            while (ptr != nullptr) {
//                cout << ptr->key << " ";
//                ptr = ptr->right;
//            }
            break;
        }
        case 2:
        {
            Adder* adder = new Adder;
            cout << "adding result: " << bitset<8>(0 - adder->add(12, 14));
            break;
        }
        default: {
            cout << "Invalid problem ID!" << endl;
            break;
        }
    }
    cout << endl << "Problem solving finished!" << endl;
    return 0;
}