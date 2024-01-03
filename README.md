0x1D. C - Binary Trees
Overview
This is a group project focusing on the implementation and understanding of binary trees in the C programming language.

Learning Objectives
Upon completion of this project, the team is expected to gain knowledge in the following areas:

Understanding what a binary tree is
Differentiating between a binary tree and a Binary Search Tree (BST)
Recognizing the time complexity advantages compared to linked lists
Grasping concepts such as depth, height, and size of a binary tree
Familiarity with various traversal methods for binary trees
Understanding terms like complete, full, perfect, and balanced binary trees
Resources
To successfully complete the project, the team is advised to read or watch materials on the following topics:

Binary tree (note the first line: Not to be confused with B-tree.)
Data Structure and Algorithms - Tree
Tree Traversal
Binary Search Tree
Data structures: Binary Tree
Requirements
General
Allowed Editors: vi, vim, emacs
Compilation: Ubuntu 20.04 LTS using gcc with options -Wall -Werror -Wextra -pedantic -std=gnu89
File Formatting: All files should end with a new line
README.md: A mandatory file at the root of the project folder
Coding Style: Code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Global Variables: Not allowed
Functions per File: No more than 5
Standard Library: Allowed
Main Files: Example main.c files are provided for testing but not required in the repo
Header File: Prototypes of all functions should be included in a header file called binary_trees.h
Header File Guard: All header files should be include guarded
Data Structures
Please use the provided data structures and types for binary trees. They should be included in the header file.

Basic Binary Tree
c
Copy code
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
Binary Search Tree
c
Copy code
typedef struct binary_tree_s bst_t;
AVL Tree
c
Copy code
typedef struct binary_tree_s avl_t;
Max Binary Heap
c
Copy code
typedef struct binary_tree_s heap_t;
Print Function
A print function is provided for visualization purposes. It is not required to be pushed to the repository and may not be used during the correction process.i
