//
// Created by john on 29/3/18.
//

#ifndef LINTCODE_STACK_H
#define LINTCODE_STACK_H

#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>

#include <set>
#include <unordered_set>

#include <algorithm>

using namespace std;

template <typename T>
class STL_Solution {
public:
    stack<T> stk;
    deque<T> dqueue;
    queue<T> qqueue;
    list<T> lst;
    vector<T> vec;

    map<T, T> ordered_mp;
    unordered_map<T, T> unordered_mp;

    set<T> ordered_st;
    unordered_set<T> unordered_st;
};

class Person {
public:
    string phone;
    string name;
    string address;

    explicit Person(){}
    explicit Person(string name, string phone, string address) : phone(phone), name(name), address(address) {

    }

    bool operator==(const Person& person) {
        return this->phone == person.phone && this->name == person.name && this->address == person.address;
    }

    friend ostream &operator<<(ostream &os, const Person &person) {
        os << person.name << " " << person.address << " " << person.phone << endl;
        return os;
    }

    friend istream &operator>>(istream &is, Person &person) {
        is >> person.name >> person.phone >> person.address;
        return is;
    }
};

struct Node{
    int x, y;
    Node( int a= 0, int b= 0 ):
            x(a), y(b) {}
};

// overloading () operator makes class cmp a function class because an object of class cmp
// such as Cmp cmp can acts as function call cmp(a, b).
class Cmp {
public:
    bool operator() ( Node a, Node b ) {
        if( a.x == b.x )
            return a.y > b.y;
        return a.x > b.x;
    }
};


template <class T>
class MaxHeap {
private:
    vector<T> myHeap;

    int getIndex(const T data) {
        int pos = -1;
        for (int i = 0; i < myHeap.size(); ++i) {
            if (myHeap.at(i) == data) pos = i;
        }
        return pos;
    }
public:
    bool insert(T data) {
        myHeap.push_back(data);
        int current_idx = myHeap.size() - 1;
        while (current_idx > 0) {
            int parent_idx = (int) floor((current_idx - 1) / 2);
            if (myHeap.at(current_idx) > myHeap.at(parent_idx)) {
                T temp = myHeap.at(parent_idx);
                myHeap.at(parent_idx) = myHeap.at(current_idx);
                myHeap.at(current_idx) = temp;

                current_idx = parent_idx;
            } else break;
        }
        return true;
    }

    bool del(T data) {

        int current_idx = getIndex(data);
        if (current_idx == -1) {
            cout << "No match found!" << endl;
            return false;
        } else {
            myHeap.at(current_idx) = myHeap.back();
            myHeap.erase(myHeap.end() - 1);
            int left_idx = 2 * current_idx + 1;
            int right_idx = 2 * current_idx + 2;

            while (left_idx < myHeap.size()  || right_idx < myHeap.size() ) {
                if (right_idx < myHeap.size()) {
                    int max_idx = (myHeap[left_idx] > myHeap[right_idx]) ? left_idx : right_idx;
                    if (myHeap[current_idx] < myHeap[max_idx]) {
                        T temp = myHeap[max_idx];
                        myHeap[max_idx] = myHeap[current_idx];
                        myHeap[current_idx] = temp;
                        current_idx = max_idx;
                        left_idx = 2 * current_idx + 1;
                        right_idx = 2 * current_idx + 2;
                    } else break;
                } else {
                    if (myHeap[current_idx] < myHeap[left_idx]) {
                        T temp = myHeap[left_idx];
                        myHeap[left_idx] = myHeap[current_idx];
                        myHeap[current_idx] = temp;
                        current_idx = left_idx;

                        left_idx = 2 * current_idx + 1;
                        right_idx = 2 * current_idx + 2;
                    } else break;
                }
            }
            return true;
        }
    }

    void display() {
        for (auto item : myHeap) {
            cout << item << " ";
        }
    }
};

/**
 * Explore a maze with n*n size, each element of which is 0 or 1 representing
 * wall or path. Find a path from top left corner node to bottom right corner
 * node.
 * @param n
 */
void maze_solution() {
    const int N = 4;
    int maze[N][N] = {
            {0, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 1, 1, 1},
            {0, 0, 0, 0}};

    stack<pair<int, int>> reverse_path;
    bool visited[N][N] = {
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false}};

    int row_idx = 0, col_idx = 0;

    if (maze[0][0] == 1 || maze[N-1][N-1] == 1) {
        cout << "Invalid maze" << endl;
    } else {
        reverse_path.push(make_pair(row_idx, col_idx));
        do {

            // After visiting current node at (row_idx, col_idx), mark it true in visited matrix.
            visited[row_idx][col_idx] = true;

            // Judge whether current node is the destination node or not
            if (row_idx + 1 == N && col_idx + 1 == N) break;

            bool proceed = false;
            if (row_idx + 1 < N && maze[row_idx+1][col_idx] == 0) {
                proceed = true;
                reverse_path.push(make_pair(row_idx + 1, col_idx));
            }
            if (col_idx + 1 < N && maze[row_idx][col_idx+1] == 0) {
                proceed = true;
                reverse_path.push(make_pair(row_idx, col_idx + 1));
            }

            // If cannot proceed in current path
            if (!proceed) {
                while (visited[row_idx][col_idx] == true) {
                    reverse_path.pop();
                    if (!reverse_path.empty()) {
                        row_idx = reverse_path.top().first;
                        col_idx = reverse_path.top().second;
                    } else break;
                }
            } else {
                row_idx = reverse_path.top().first;
                col_idx = reverse_path.top().second;
            }
        } while (!reverse_path.empty());

        // reverse the reverse_path to forwarding path
        if (!reverse_path.empty()) {
            cout << "Path found: " << endl;
            stack<pair<int, int>> path;
            while (!reverse_path.empty()) {
                auto item = reverse_path.top();
                if (visited[item.first][item.second] == true)
                    path.push(item);
                reverse_path.pop();
            }

            while (!path.empty()) {
                cout << "(" << path.top().first << "," << path.top().second << ")" << endl;
                path.pop();
            }
        } else cout << "Path not found!" << endl;
    }
}

#endif //LINTCODE_STACK_H
