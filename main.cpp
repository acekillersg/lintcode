#include <iostream>
#include "SolutionClasses.h"

using namespace std;

int main(int argc, char** argv) {
    int problemID = 0;
    Solution_0_List<int >* solution0 = new Solution_0_List<int>();
    Solution_1_Tree<int>* solution1 = new Solution_1_Tree<int>();
    switch(problemID) {
        case 0: {
            cout << "Solving problem " << problemID << endl;
            ListNode<int> *list = solution0->construct(2);
            solution0->printList(list);
            list = solution0->insert(list, 100, 1);
            solution0->printList(list);
            list = solution0->remove(list,0);
            solution0->printList(list);
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

            cout << solution1->root->right->key << endl;

            cout << "visit in pre-order:";
            solution1->preOrder(solution1->root);

            cout << endl << "visit in in-order:";
            solution1->inOrder(solution1->root);

            cout << endl <<  "visit in post-order:";
            solution1->postOrder(solution1->root);
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