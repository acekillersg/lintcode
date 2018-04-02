//
// Created by john on 31/3/18.
//

#ifndef LINTCODE_GRAPH_SOLUTION_H
#define LINTCODE_GRAPH_SOLUTION_H

#include <iomanip>

typedef struct AdjListNode {
    int nodeID;
    int weight;
    AdjListNode* next;
}AdjListNode;

typedef struct AdjList_Graph {
    int vertices;
    int edges;
    AdjListNode** headList;
}AdjList_Graph;

class AdjList_Graph_Solution {
private:
    AdjList_Graph* graph;
    void DFS_traverse(int startingNodeID, bool*& visited);

public:
    void initGraph(int v);
    void addEdge(int beginPos, int endPos, int weight=0);
    void destroy();
    void printGraph();
    void DFS();
    void BFS(int startingNodeID = 0);
};

void AdjList_Graph_Solution::initGraph(int v) {

    this->graph = new AdjList_Graph();
    this->graph->vertices = v;
    this->graph->edges = 0;
    this->graph->headList = new AdjListNode*[v]();

    for (int i = 0; i < this->graph->vertices; ++i) {
        this->graph->headList[i] = new AdjListNode();
        this->graph->headList[i]->nodeID = i;
        this->graph->headList[i]->weight = 0;
        this->graph->headList[i]->next = nullptr;
    }
}

void AdjList_Graph_Solution::addEdge(int beginPos, int endPos, int weight) {
    AdjListNode* newNode = new AdjListNode();
    newNode->nodeID = endPos;
    newNode->weight = weight;
    newNode->next = this->graph->headList[beginPos]->next;
    this->graph->headList[beginPos]->next = newNode;
}

void AdjList_Graph_Solution::destroy() {
    AdjListNode* delPtr = nullptr;
    for (int i = 0; i < this->graph->vertices; ++i) {
        delPtr = this->graph->headList[i];
        while (delPtr != nullptr) {
            AdjListNode* temp = delPtr;
            delPtr = delPtr->next;
            delete temp;
        }
    }
    delete[] this->graph->headList;
    delete this->graph;
    this->graph = nullptr;
}

void AdjList_Graph_Solution::printGraph() {
    if (this->graph == nullptr) {
        cout << "Empty graph" << endl;
    } else {
        cout << "AdjList_Graph:" << endl;
        for (int i = 0; i < this->graph->vertices; ++i) {
            AdjListNode* printPtr = this->graph->headList[i];
            while (printPtr != nullptr) {
                cout << "(" << printPtr->nodeID << "," << printPtr->weight << ")-->";
                printPtr = printPtr->next;
            }
            cout << "end" << endl;
        }
    }
}

void AdjList_Graph_Solution::DFS() {
    bool* visited = new bool[this->graph->vertices];
    for (int i = 0; i < this->graph->vertices; ++i) {
        visited[i] = false;
    }

    for (int j = 0; j < this->graph->vertices; ++j) {
        if (visited[j] == false) {
            DFS_traverse(j, visited);
        }
    }
    cout << "end" << endl;
}

void AdjList_Graph_Solution::DFS_traverse(int startingNodeID, bool*& visited) {
    cout << startingNodeID << "-->";
    visited[startingNodeID] = true;

    AdjListNode* ptr = this->graph->headList[startingNodeID]->next;
    while (ptr != nullptr) {
        if (visited[ptr->nodeID] == false)
            DFS_traverse(ptr->nodeID, visited);
        ptr = ptr->next;
    }
}

void AdjList_Graph_Solution::BFS(int startingNodeID) {
    queue<AdjListNode*> nodeQueue;
    bool* visited = new bool[this->graph->vertices];
    for (int i = 0; i < this->graph->vertices; ++i) {
        visited[i] = false;
    }
    nodeQueue.push(this->graph->headList[startingNodeID]);
    visited[startingNodeID] = true;

    while (!nodeQueue.empty()) {
        AdjListNode* frontPtr = this->graph->headList[nodeQueue.front()->nodeID];
        cout << frontPtr->nodeID << "-->";

        while (frontPtr != nullptr) {
            if (visited[frontPtr->nodeID] == false) {
                nodeQueue.push(frontPtr);
                visited[frontPtr->nodeID] = true;
            }
            frontPtr = frontPtr->next;
        }
        nodeQueue.pop();
    }
    cout << "end" << endl;
    delete[] visited;
}

typedef struct AdjMat_Graph {
    int verticesNO;
    int edgesNO;
    int** verticesMat;
}AdjMat_Graph;

class AdjMat_Graph_Solution {
private:
    AdjMat_Graph* graph;
    void DFS_traverse(int startingNodeID, bool*& visited);

public:
    void initGraph(int v);
    void addEdge(int beginPos, int endPos, int weight = 1);
    bool hasEdgeBetween(int beginPos, int endPos);
    void printGraph();
    void DFS();
    void BFS(int startingNodeID = 0);
    void destroy();
};

void AdjMat_Graph_Solution::initGraph(int v) {
    this->graph = new AdjMat_Graph();
    this->graph->edgesNO = 0;
    this->graph->verticesNO = v;
    this->graph->verticesMat = new int*[v]();
    for (int i = 0; i < v; ++i) {
        this->graph->verticesMat[i] = new int[v]();
        for (int j = 0; j < v; ++j) {
            this->graph->verticesMat[i][j] = 0;
        }
    }
}

void AdjMat_Graph_Solution::addEdge(int beginPos, int endPos, int weight) {
    if (beginPos >= 0 && beginPos < this->graph->verticesNO && endPos >= 0 && endPos < this->graph->verticesNO) {
        this->graph->verticesMat[beginPos][endPos] = weight;
    } else {
        cout << "Incorrect input" << endl;
    }
}

void AdjMat_Graph_Solution::printGraph() {
    if (this->graph == nullptr) {
        cout << "Empty graph!" << endl;
    } else {
        cout << "Matrix of AdjMat_Graph:" << endl;
        for (int i = 0; i < this->graph->verticesNO; ++i) {
            for (int j = 0; j < this->graph->verticesNO; ++j) {
                cout << setw(6) << this->graph->verticesMat[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void AdjMat_Graph_Solution::destroy() {
    for (int i = 0; i < this->graph->verticesNO; ++i) {
        delete[] this->graph->verticesMat[i];
    }
    delete[] this->graph->verticesMat;
    delete this->graph;
    this->graph = nullptr;
}

bool AdjMat_Graph_Solution::hasEdgeBetween(int beginPos, int endPos) {
    if (beginPos >= 0 && beginPos < this->graph->verticesNO && endPos >= 0 && endPos < this->graph->verticesNO) {
        if (this->graph->verticesMat[beginPos][endPos] != 0) return true;
        else return false;
    } else {
        cout << "Incorrect input" << endl;
        return false;
    }
}

void AdjMat_Graph_Solution::DFS() {
    bool* visited = new bool[this->graph->verticesNO];
    for (int i = 0; i < this->graph->verticesNO; ++i) {
        visited[i] = false;
    }

    for (int j = 0; j < this->graph->verticesNO; ++j) {
        if (visited[j] == false) {
            DFS_traverse(j, visited);
        }
    }
    cout << "end" << endl;
}

void AdjMat_Graph_Solution::DFS_traverse(int startingNodeID, bool*& visited) {
    cout << startingNodeID << "-->";
    visited[startingNodeID] = true;

    for (int i = 0; i < this->graph->verticesNO; ++i) {
        if (hasEdgeBetween(startingNodeID, i) && visited[i] == false) {
            DFS_traverse(i, visited);
        }
    }
}

void AdjMat_Graph_Solution::BFS(int startingNodeID) {
    queue<int> nodeQueue;
    bool* visited = new bool[this->graph->verticesNO];
    for (int i = 0; i < this->graph->verticesNO; ++i) {
        visited[i] = false;
    }
    nodeQueue.push(startingNodeID);
    visited[startingNodeID] = true;

    while (!nodeQueue.empty()) {
        int frontNodeID = nodeQueue.front();
        cout << frontNodeID << "-->";

        // find all connecting nodes that are not visited yet and push them into queue.
        for (int i = 0; i < this->graph->verticesNO; ++i) {
            if (hasEdgeBetween(frontNodeID, i) && visited[i] == false) {
                nodeQueue.push(i);
                visited[i] = true;
            }
        }

        nodeQueue.pop();
    }

    cout << "end" << endl;
    delete visited;
}
#endif //LINTCODE_GRAPH_SOLUTION_H