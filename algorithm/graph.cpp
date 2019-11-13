#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// Author: https://blog.csdn.net/DarkRabbit
// Minimum Spanning Tree
// 小根堆插入，首下标从1开始
// params:
//      btTree:     堆树
//      val:        插入的值
void BinaryInsertWithOne(std::vector<KruskalEdge>& btTree, KruskalEdge& val)
{
    if (btTree.size() == 0) // 下标从1开始，最少要有一个元素
    {
        btTree.push_back(KruskalEdge());
        btTree.push_back(val);
        return;
    }

    int index = btTree.size(); // 插入后的下标
    btTree.push_back(val); // 插入数值

    int parent = index / 2; // 父结点下标

    while (parent > 0 && btTree[index].weight < btTree[parent].weight) // 如果子结点小
    {
        std::swap(btTree[index], btTree[parent]); // 交换父结点与当前结点
        index = parent; // 重新设定下标
        parent /= 2; // 重新计算父结点
    }
}
// Author: https://blog.csdn.net/DarkRabbit
// Minimum Spanning Tree

#include "abstract_graph.h"
#include "adjacency_matrix.h"

#include "minimum_spanning_tree.h"

#include <vector>
#include <unordered_map>

#include <iomanip>
#include <iostream>
using namespace std;

typedef Graphs::AMVertexNode<int> AMVertexInt;
typedef Graphs::AdjacencyMatrix<int> AMGraphInt;

void TestAdjacencyMatrix();
void TestKruskal();
void TestPrim();

int main()
{
    //TestAdjacencyMatrix();

    TestKruskal();
    TestPrim();

    system("pause");
    return 0;
}

// 打印邻接矩阵
template<class TGraph>
void PrintMatrix(TGraph& graph);

// 克鲁斯卡尔 Kruskal
void TestKruskal()
{
    AMGraphInt* graph = new AMGraphInt({ 0, 1, 2, 3, 4, 5, 6 }, false); // 无向图 0-6
    graph->InitializeWeights(
        { {0, 1}, {0, 5}, {1, 2}, {1, 6}, {2, 3}, {3, 4}, {3, 6}, {4, 5}, {4, 6} },
        { 25, 9, 16, 13, 11, 22, 19, 23, 24 }); // 初始化边

    vector<Graphs::MinimumSpanningTree::KruskalEdge> edges;
    AMGraphInt* minTree = Graphs::MinimumSpanningTree::Kruskal(graph, edges);

    cout << "----------克鲁斯卡尔 Kruskal----------" << endl;
    cout << "无向图：" << endl;
    cout << "邻接矩阵：" << endl;
    PrintMatrix(*graph);
    cout << endl;

    cout << "克鲁斯卡尔最小生成树的图：" << endl;
    PrintMatrix(*minTree);
    cout << endl;

    cout << "生成边顺序为：" << endl;
    for (int i = 0; i < edges.size(); i++)
    {
        cout << (char)(edges[i].second + 'A');
        cout << " ---" << edges[i].weight << "--- ";
        cout << (char)(edges[i].first + 'A') << endl;
    }
    cout << "--------------------" << endl;

    delete graph;
    delete minTree;

    cout << endl;
}

// 普利姆 Prim
void TestPrim()
{
    AMGraphInt* graph = new AMGraphInt({ 0, 1, 2, 3, 4, 5, 6 }, false); // 无向图 0-6
    graph->InitializeWeights(
        { {0, 1}, {0, 5}, {1, 2}, {1, 6}, {2, 3}, {3, 4}, {3, 6}, {4, 5}, {4, 6} },
        { 25, 9, 16, 13, 11, 22, 19, 23, 24 }); // 初始化边

    vector<Graphs::MinimumSpanningTree::PrimEdge> edges;
    AMGraphInt* minTree = Graphs::MinimumSpanningTree::Prim(graph, 0, edges);

    cout << "----------普利姆 Prim----------" << endl;
    cout << "无向图：" << endl;
    cout << "邻接矩阵：" << endl;
    PrintMatrix(*graph);
    cout << endl;

    cout << "普利姆最小生成树的图：" << endl;
    PrintMatrix(*minTree);
    cout << endl;

    cout << "生成边顺序为：" << endl;
    for (int i = 0; i < edges.size(); i++)
    {
        cout << (char)(edges[i].first + 'A');
        cout << " ---" << edges[i].weight << "--- ";
        cout << (char)(edges[i].second + 'A') << endl;
    }
    cout << "--------------------" << endl;

    delete graph;
    delete minTree;

    cout << endl;
}
