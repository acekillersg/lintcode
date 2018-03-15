#include <iostream>
#include "SolutionClasses.h"

using namespace std;

int main(int argc, char** argv) {
    int problemID = 1;
    Solution_0_List solution0(0);
    Solution_1_Tree solution1(1);
    switch(problemID) {
        case 0:
            cout << "Solving problem " << problemID << endl;
            solution0.solve();
            break;
        case 1: {
            cout << "Solving problem " << problemID << endl;
            solution1.solve();
            break;
        }
        default: {
            cout << "Invalid problem ID!" << endl;
            break;
        }
    }
    cout << "Problem solving finished!" << endl;
    return 0;
}