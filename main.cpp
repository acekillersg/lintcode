#include <iostream>
#include <bitset>
#include <algorithm>
#include "SolutionClasses.h"
#include "Algorithms.h"
#include "STL_Solution.h"
#include "AdjList_Graph_Solution.h"

using namespace std;

int main(int argc, char** argv) {
    int problemID = 1;
    switch (problemID) {
        case 0: {
            Solution_0_List<int> *solution0 = new Solution_0_List<int>();
            cout << "Solving problem " << problemID << endl;

            cout << "construct a new list: " << endl;
            ListNode<int> *list = solution0->construct(10);
            solution0->printList(list);

            cout << "insert a new node into list: " << endl;
            list = solution0->insert(list, 100, 1);
            solution0->printList(list);

            cout << "remove a node from the list: " << endl;
            list = solution0->remove(list, 0);
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

            Solution_1_Tree<int> *solution1 = new Solution_1_Tree<int>();
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
            cout << endl << "visit in post-order:";
            solution1->postOrder(solution1->root);

            cout << endl << "Reversing the left and right children trees!" << endl;
            solution1->reverseTree();
            cout << "visit in pre-order:";
            solution1->preOrder(solution1->root);
            cout << endl << "visit in in-order:";
            solution1->inOrder(solution1->root);
            cout << endl << "visit in post-order:";
            solution1->postOrder(solution1->root);

            Solution_1_Tree<int> *solution2 = new Solution_1_Tree<int>();
            solution2->insert(2, solution2->root);
            solution2->insert(1, solution2->root);
            solution2->insert(6, solution2->root);
            solution2->insert(5, solution2->root);
            solution2->insert(4, solution2->root);
            solution2->insert(3, solution2->root);
            solution2->insert(7, solution2->root);
            solution2->insert(8, solution2->root);
            solution2->insert(9, solution2->root);
            solution2->insert(0, solution2->root);
            solution2->insert(9, solution2->root);
            solution2->insert(2, solution2->root);
            solution2->insert(13, solution2->root);
            solution2->insert(16, solution2->root);
            solution2->insert(14, solution2->root);
            solution2->insert(17, solution2->root);
            solution2->insert(19, solution2->root);
            solution2->insert(12, solution2->root);

            cout << endl << "visit in pre-order:";
            solution1->preOrder(solution1->root);

            cout << endl << "visit in in-order:";
            solution1->inOrder(solution1->root);

            cout << endl << "visit in post-order:";
            solution1->postOrder(solution1->root);

            cout << endl << "find certain key: ";
            cout << solution1->isFound(9, solution1->root);

            cout << endl << "delete key: 7";
            solution1->del(7, solution1->root);

            cout << endl << "visit in in-order:";
            solution1->inOrder(solution1->root);

            cout << endl << "visit in pre-order:";
            solution1->preOrder(solution1->root);

            cout << endl << "visit in post-order:";
            solution1->postOrder(solution1->root);

            cout << endl << "visit in layer-order:";
            solution1->layerOrder(solution1->root);

            cout << endl << "delete key: 19";
            solution1->del(19, solution1->root);

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

            cout << endl << "Longest distance in tree: ";
            int leftSubTree, rightSubTree = 0;
            cout << solution2->maxDistanceInTree(solution2->root, leftSubTree, rightSubTree);

            Solution_1_Tree<int> *solution3 = new Solution_1_Tree<int>();
            cout << endl << "Creating new binary tree!" << endl;
            solution3->generate_interact(solution3->root);

            cout << endl << "visit in in-order: ";
            solution3->inOrder(solution3->root);

            cout << endl << "visit in post-order: ";
            solution3->postOrder(solution3->root);

            cout << endl << "visit in pre-order: ";
            solution3->preOrder(solution3->root);

            cout << endl << "transform to list: ";
            TreeNode<int> *pHead, *pTail, *ptr = nullptr;
            solution1->transformToList(solution1->root, pHead, pTail);
            ptr = pHead;
            while (ptr != nullptr) {
                cout << ptr->key << " ";
                ptr = ptr->right;
            }
            cout << endl;

            Solution_1_Tree<char> *solution4 = new Solution_1_Tree<char>();
            solution4->generate_pre_order(solution4->root);

            cout << endl << "visit in in-order: ";
            solution4->inOrder(solution4->root);

            cout << endl << "visit in post-order: ";
            solution4->postOrder(solution4->root);

            cout << endl << "visit in pre-order: ";
            solution4->preOrder(solution4->root);

            Solution_1_Tree<char> *solution5 = new Solution_1_Tree<char>();
            solution5->regenerate(solution5->root);

            cout << endl << "visit in in-order: ";
            solution5->inOrder(solution5->root);

            cout << endl << "visit in post-order: ";
            solution5->postOrder(solution5->root);

            cout << endl << "visit in pre-order: ";
            solution5->preOrder(solution5->root);
            cout << endl;

            break;
        }
        case 2: {
            Adder *adder = new Adder();
            cout << "adding result: " << bitset<8>(0 - adder->add(12, 14));
            break;
        }
        case 3: {
            Sorter<int> *sorter = new Sorter<int>;
            cout << "sorting results: " << endl;
            int array[] = {4, 5, 2, 3, 9, 0};
            size_t size = sizeof(array) / sizeof(array[0]);
            int count = sorter->merge_sorter(array, 0, size - 1, true);
            for (int i = 0; i < size; ++i) {
                cout << array[i] << " ";
            }
            cout << endl << "The position of target element: " << sorter->binary_search(array, size, 4);
            cout << endl << "Number of reserve pairs: " << count;
            break;
        }
        case 4: {
            STL_Solution<int> *solution4 = new STL_Solution<int>();
            solution4->vec.push_back(4);
            solution4->vec.push_back(5);
            for (vector<int>::iterator itr = solution4->vec.begin(); itr != solution4->vec.end(); itr++) {
                cout << *itr << " " << endl;
            }

            priority_queue<Node, vector<Node>, Cmp> pq;
            pq.push(Node(14, 14));
            pq.push(Node(13, 13));
            pq.push(Node(15, 15));
            while (!pq.empty()) {
                auto p = pq.top();
                cout << p.x << " " << p.y << endl;
                pq.pop();
            }

            vector<int> num = {9, 6, 2, 4, 7, 1, 8, 14, 3, 5};
            make_heap(num.begin(), num.end(), less<int>());
            cout << "Maximum: " << *num.begin() << endl;


            MaxHeap<int> *maxHeap = new MaxHeap<int>();
            maxHeap->insert(10);
            maxHeap->insert(8);
            maxHeap->insert(20);
            maxHeap->insert(30);
            maxHeap->insert(15);
            maxHeap->insert(7);
            maxHeap->display();

            cout << endl;
            maxHeap->del(20);
            maxHeap->del(7);
            maxHeap->display();

            maze_solution();
            break;
        }
        case 5: {
            AdjList_Graph_Solution *algs = new AdjList_Graph_Solution();
            algs->initGraph(9);
            algs->addEdge(0, 1);
            algs->addEdge(0, 5);
            algs->addEdge(1, 0);
            algs->addEdge(1, 2);
            algs->addEdge(1, 6);
            algs->addEdge(1, 8);
            algs->addEdge(2, 1);
            algs->addEdge(2, 3);
            algs->addEdge(2, 8);
            algs->addEdge(3, 2);
            algs->addEdge(3, 4);
            algs->addEdge(3, 6);
            algs->addEdge(3, 7);
            algs->addEdge(3, 8);
            algs->addEdge(4, 3);
            algs->addEdge(4, 5);
            algs->addEdge(4, 7);
            algs->addEdge(5, 0);
            algs->addEdge(5, 4);
            algs->addEdge(5, 6);
            algs->addEdge(6, 1);
            algs->addEdge(6, 3);
            algs->addEdge(6, 5);
            algs->addEdge(6, 7);
            algs->addEdge(7, 3);
            algs->addEdge(7, 4);
            algs->addEdge(7, 6);
            algs->printGraph();

            cout << "DFS: " << endl;
            algs->DFS();

            cout << "BFS: " << endl;
            algs->BFS(0);

            cout << "Destroying graph!" << endl;
            algs->destroy();
            algs->printGraph();

            AdjMat_Graph_Solution *amgs = new AdjMat_Graph_Solution();
            amgs->initGraph(9);
            amgs->addEdge(0, 1);
            amgs->addEdge(0, 5);
            amgs->addEdge(1, 0);
            amgs->addEdge(1, 2);
            amgs->addEdge(1, 6);
            amgs->addEdge(1, 8);
            amgs->addEdge(2, 1);
            amgs->addEdge(2, 3);
            amgs->addEdge(2, 8);
            amgs->addEdge(3, 2);
            amgs->addEdge(3, 4);
            amgs->addEdge(3, 6);
            amgs->addEdge(3, 7);
            amgs->addEdge(3, 8);
            amgs->addEdge(4, 3);
            amgs->addEdge(4, 5);
            amgs->addEdge(4, 7);
            amgs->addEdge(5, 0);
            amgs->addEdge(5, 4);
            amgs->addEdge(5, 6);
            amgs->addEdge(6, 1);
            amgs->addEdge(6, 3);
            amgs->addEdge(6, 5);
            amgs->addEdge(6, 7);
            amgs->addEdge(7, 3);
            amgs->addEdge(7, 4);
            amgs->addEdge(7, 6);
            amgs->printGraph();

            cout << "DFS: " << endl;
            amgs->DFS();

            cout << "BFS: " << endl;
            amgs->BFS(0);

            cout << "Destroying graph!" << endl;
            amgs->destroy();
            amgs->printGraph();

            break;
        }
        case 6: {
            // String matching problem (KMP algorithm)
//            string sentence = "ABCABCDABDCABCDABDAB";
//            string pattern = "ABCDABD";
//            cout << "Position: " << KMP(sentence, pattern);

            // Find the sub-array in an array that has the maximum sum
//            int number1[] = {1, -2, 3, 10, -4, 7, 2, -5};
//            int number2[] = {-6, 2, 4, -7, 5, 3, 2, -1, 6, -9, 10, -2};
//            int number3[] = {-2, 11, 8, -4, -1, 16, 5, 0};
//            maxSumInArray(number1, sizeof(number1) / sizeof(int));
//            maxSumInArray(number2, sizeof(number2) / sizeof(int));
//            maxSumInArray(number3, sizeof(number3) / sizeof(int));

            // Eight queen problem
//            eight_queen(8);

            // Hanoi checkerboard placement problem
//            hanoi(20);

            // Parentheses matching problem
//            cout << "Stack implementation:" << endl;
//            parentheses_match("(abc((adfd(dfd)dfdfd)fdfd)fdfd)");
//            parentheses_match("())(");
//
//            cout << "Recursive implementation:" << endl;
//            parentheses_match_rec("(abc((adfd(dfd)dfdfd)fdfd)fdfd)");
//            parentheses_match_rec("())(()");

            // Counting of islands with different shapes
            island_search();
            break;
        }
        default: {
            cout << "Invalid problem ID!" << endl;
            break;
        }
    }
    cout << "Problem solving finished!";
    return 0;
}