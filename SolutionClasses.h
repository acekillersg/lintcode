//
// Created by john on 15/3/18.
//

#ifndef LINTCODE_SOLUTIONCLASSES_H
#define LINTCODE_SOLUTIONCLASSES_H

struct ListNode{
    int val;
    ListNode* next;
};

class Solution_0_List {
private:
    int problemID;
public:
    Solution_0_List(int problemID);
    ListNode* construct(int len);
    ListNode* remove(int index);
    int get(int index);
    int set(int index);
};

class Solution_1_Tree {
private:
    int problemID;
public:
    Solution_1_Tree(int problemID);
    bool solve();
};

#endif //LINTCODE_SOLUTIONCLASSES_H
