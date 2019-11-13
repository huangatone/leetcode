#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#include <sstream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

class Graph
{
public:
	Graph(int max)
	{
		edges.resize(max);
		nLen = max;
	}
	virtual ~Graph()
	{

	}

	void add(int m,int n)
	{
		edges[m].push_back(n);
		edges[n].push_back(m);
	}

	bool isCycle()
	{
		bool *isVisit = new bool[nLen];
        for (int n=0; n< nLen; n++)
        {
            isVisit[n] = false;
        }
		bool is = isCycle(0,isVisit,-1);
		delete [] isVisit;
        isVisit = 0;
		return is;

	}

	bool isTree()
	{
		bool *isVisit = new bool[nLen];
        for (int n=0; n< nLen; n++)
        {
            isVisit[n] = false;
        }
		bool is = isCycle(0,isVisit,-1);
		if ( is)
		{
            cout << "not cycle: "<< is   << endl; 
			delete [] isVisit;
			return  false;
		}


		for (int u = 0; u < nLen; u++)
			if (!isVisit[u])
			{
                cout << "not v: " << u << endl; 
				delete [] isVisit;
				return false;
			}
		delete [] isVisit;
		return true;
	}

	bool isCycle(int v, bool isVisit[], int p)
	{
		isVisit[v] = true;
		for ( auto i: edges[v])
		{
			if ( !isVisit[i])
			{
				if ( isCycle(i,isVisit,v) )
					return true;
			}
			else if (  i != p)
				return true;
		}
		return false;
	}
    bool print(int v, bool isVisit[],int parent)
    {
        isVisit[v] = true;
        cout << "fist > " << v << endl;
        for (auto i: edges[v])
        {
            if ( !isVisit[i])
			{
				if ( print(i,isVisit,v) )
					return true;
			}
			else if (  i != parent)
				return true;
        }
        cout << endl;
        return false;
    }
    void printTree()
    {
        bool *isVisit = new bool[nLen];
        for (int n=0; n< nLen; n++)
        {
            isVisit[n] = false;
        }
        print(0,isVisit,-1);
    }

    void printGraph()
    {
        int index = 0;
        for (auto lt: edges)
        {
            cout << index << " { ";
            for (auto i: lt)
            {
                cout << i << " ";
            }
            cout << "}"<< endl;
            index++;
        }
    }

    bool dfsfind(int node,int v,bool isVisit[], stack<int> &path)
    {
        cout << "strat at node " << v << endl;
        for (auto i: edges[v])
        {
            cout << "find in node " << i << endl;
            if (isVisit[i])
                continue;
            path.push(i);
            isVisit[i] = true;
            if (i==node)
            {
                cout << "OK -- Find node " << node << endl;
                return true;
            }
            else
            {
                if ( dfsfind(node,i,isVisit,path))
                    return true;
            }
            path.pop();
            isVisit[i] = false;
            
        }
        return false;
    }
    void dfsfind(int node)
    {
        cout << "dfs Start find node " << node << endl;
        stack<int> path;
       
        bool *isVisit = new bool[nLen];
        for (int n=0; n< nLen; n++)
        {
            isVisit[n] = false;
        }

        path.push(0);
        isVisit[0] = true;
        for (auto v: edges[0])
        {
            path.push(v);
            cout << "find in node " << v << endl;
            isVisit[v]= true;
            if (v==node)
            {
                break;
            }
            else
            {
                if (dfsfind(node,v,isVisit,path))
                break;
            }
            path.pop();
            isVisit[v]= false;
            
        }

        while (path.size() >0)
        {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
        
        
    }

    void print(stack<int> path) 
    {
        while (path.size() >0)
        {
            cout << path.top() << " ";
            path.pop();
        }
    }
    bool bfsfind(int node,int v,bool isVisit[], stack<int> &path)
    {
        isVisit[v] = true;

        return false;
    }
    void bfsfind(int node)
    {
        cout << "bfs Start find node " << node << endl;
        stack<int> path;

        bool *isVisit = new bool[nLen];
        for (int n=0; n< nLen; n++)
        {
            isVisit[n] = false;
        }

        path.push(0);
        isVisit[0] = true;
        for (auto v: edges[0])
        {
            path.push(v);
            isVisit[v]= true;
            if (v==node)
            {
                print(path);
                break;
            }
            else
            {
                if (bfsfind( node, v, isVisit, path))
                {
                    print(path);
                }
            }
            
            path.pop();
            isVisit[v]= false;
            
        }

        while (path.size() >0)
        {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }

private:
	vector < vector<int> > edges;
	int nLen;

};

int main()
{
    std::ifstream infile("/dfnet/g.txt");
    std::string line;
    
    std::getline(infile, line);
    int total;
    std::istringstream iss(line);
    iss >> total;
    Graph g(total);
while (std::getline(infile, line))
{
    std::istringstream iss(line);
    int a, b;
    if (!(iss >> a >> b)) 
    { 
        break; 
    } // error
    g.add(a,b);

    // process pair (a,b)
}
    // Graph g(20);
    // g.add(0,1);
    // g.add(0,3);
    // g.add(1,4);
    // g.add(1,7);
    // g.add(1,8);
    // g.add(3,6);
    // g.add(7,2);
    // g.add(8,5);
    // g.add(6,15);
    // g.add(2,9);
    // g.add(2,11);
    // g.add(5,14);
    // g.add(15,16);
    // g.add(9,10);
    // g.add(11,12);
    // g.add(16,17);
    // g.add(16,18);
    // g.add(12,13);
    // g.add(17,19);
   

    cout << "Cycle Is " <<  g.isCycle() << endl;
    auto tree = g.isTree();
    cout << "Tree Is " << tree << endl;
    if (tree)
    {
       // g.printGraph();
        g.dfsfind(10);
    }
    return 0;
}