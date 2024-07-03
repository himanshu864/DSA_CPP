#include <iostream>
using namespace std;

int main()
{
    cout << "Tree";
    return 0;
}

/*

##Tree: is a collection of nodes(vertices) and Edges. Among those nodes, one node is taken as root Node.
Rest of the nodes are divided into disjoint subsets. And each subset is a tree(Sub-tree) again

##Terminology:
> Root : Top of the tree

> Parent : A node is a parent to it's very next descendants. Or those children who are connected by just one edge

> Sibling : Same parents

> Descendants : The set of all children of a node. All Nodes which can be reached from that node.

> Ancestors : All nodes along the path from that node to root node.

> Degree of Node : No. of children a node is having.
 - minimum degree of a tree is maximum degree of all nodes in it

> Internal/External nodes:
    - Internal / Non-leaf / Non-terminal Nodes : nodes with non-zero degree. (some children)
    - External / Leaf / Terminal Nodes: Nodes with zero degree.

> Level : The no. of ancestors any node is having. Starts from root - 1

> Height : NO. of edges from root to that node. Starts from root - 0

> Forest : A collection of trees


## BINARY TREE:
A tree of degree 2. Deg(T) = 2.
Any node in that tree can have AtMost 2 children {0, 1, 2}: Left and Right Child

*/