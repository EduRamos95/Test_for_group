# C - Binary trees
Trees are one of the most fundamental data structures. They are used to store and organize data. A binary tree is a tree data structure composed of nodes, each of which has at most, two children, referred to as left and right nodes. The tree starts off with a single node known as the root.

Each node in the tree contains the following:
- `Data`
- Pointer to the `parent`
- Pointer to the `left child`
- Pointer to the `right child`

In case of a leaf node, the pointers to the left and right child point to null.

<p align=“center”><img src="https://i.pinimg.com/736x/15/ea/c9/15eac95e696f42351f9696df35d70652.jpg"></p>

# Resources
- <a href="https://en.wikipedia.org/wiki/Binary_tree" target="_blank"> Binary tree </a> (note the first line: *`Not to be confused with B-tree.`*)
- <a href="https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm" target="_blank"> Data Structure and Algorithms - Tree </a>
- <a href="https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal.htm" target="_blank"> Tree Traversal </a>
- <a href="https://en.wikipedia.org/wiki/Binary_search_tree" target="_blank"> Binary Search Tree </a>
- <a href="https://www.youtube.com/watch?v=H5JubkIy_p8" target="_blank"> Data structures: Binary Tree </a>

---

# Learning Objectives
## General
- What is a binary tree
- What is the difference between a binary tree and a Binary Search Tree
- What is the possible gain in terms of time complexity compared to linked lists
- What are the depth, the height, the size of a binary tree
- What are the different traversal methods to go through a binary tree
- What is a complete, a full, a perfect, a balanced binary tree

---

# Requirements
## General
- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using <a href="https://github.com/holbertonschool/Betty/blob/master/betty-style.pl" title="betty-style.pl" target="_blank"> betty-style.pl</a> and <a href="https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl" title="betty-doc.pl" target="_blank">betty-doc.pl</a>
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the standard library
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `binary_trees.h`
- Don’t forget to push your header file
- All your header files should be include guarded

## GitHub
**There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.**


# More Info
## Data structures
Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.
### Basic Binary Tree
```
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
```
### Binary Search Tree
```
typedef struct binary_tree_s bst_t;
```
### AVL Tree
```
typedef struct binary_tree_s avl_t;
```
### Max Binary Heap
```
typedef struct binary_tree_s heap_t;
```
**Note:** For tasks 0 to 23 (included), you have to deal with simple binary trees. They are not BSTs, thus they don’t follow any kind of rule.

## Print function
To match the examples in the tasks, you are given this <a href="https://github.com/holbertonschool/0x1C.c" target="_blank"> this function </a>
This function is used only for visualization purposes. You don’t have to push it to your repo. It may not be used during the correction

---

# Tasks
#### Task mandatory

- [x] **`0. New node`**: *Write a function that creates a binary tree node*
- [x] **`1. Insert left`**: *Write a function that inserts a node as the left-child of another node*
- [x] **`2. Insert right`**: *Write a function that inserts a node as the right-child of another node*
- [x] **`3. Delete`** : *Write a function that deletes an entire binary tree*
- [x] **`4. Is leaf`**: *Write a function that checks if a node is a leaf*
- [x] **`5. Is root`**: *Write a function that checks if a given node is a root*
- [x] **`6. Pre-order traversal`**: *Write a function that goes through a binary tree using pre-order traversal*
- [x] **`7. In-order traversal`**: *Write a function that goes through a binary tree using in-order traversal*
- [x] **`8. Post-order traversal`**: *Write a function that goes through a binary tree using post-order traversal*
- [x] **`9. Height`**: *Write a function that measures the height of a binary tree*
- [x] **`10. Depth`**: *Write a function that measures the depth of a node in a binary tree*
- [x] **`11. Size`**: *Write a function that measures the size of a binary tree*
- [x] **`12. Leaves`**: *Write a function that counts the leaves in a binary tree*
- [x] **`13. Nodes`**: *Write a function that counts the nodes with at least 1 child in a binary tree*
- [x] **`14. Balance factor`**: *Write a function that measures the balance factor of a binary tree*
- [x] **`15. Is full`**: *Write a function that checks if a binary tree is full*
- [x] **`16. Is perfect`**: *Write a function that checks if a binary tree is perfect*
- [x] **`17. Sibling`**: *Write a function that finds the sibling of a node*
- [x] **`18. Uncle`**: *Write a function that finds the uncle of a node*

---
#### Authors:
* ##### Edu Ramos: 5162@holbertonstudents.com
* ##### Julian Zea: 5167@holbertonstudents.com

---
