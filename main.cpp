#include <iostream>
#include "SolutionClasses.h"

using namespace std;

int main(int argc, char** argv) {
    int problemID = 1;
    Solution_0_List<int >* solution0 = new Solution_0_List<int>();
    Solution_1_Tree<int>* solution1 = new Solution_1_Tree<int>();
    switch(problemID) {
        case 0: {
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
            cout << endl << "visit in in-order:";
            solution1->inOrder(solution1->root);

            cout << endl << "visit in pre-order:";
            solution1->preOrder(solution1->root);

            cout << endl <<  "visit in post-order:";
            solution1->postOrder(solution1->root);

            cout << endl <<  "visit in layer-order:";
            solution1->layerOrder(solution1->root);

            cout << endl << "delete key: 19";
            solution1->del(19, solution1->root);

            cout << endl << "count of nodes in tree: ";
            cout << solution1->countNumOfNodes(solution1->root);

            cout << endl << "height of tree: ";
            cout << solution1->heightOfTree(solution1->root);

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