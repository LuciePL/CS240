CS240 Data Structures & Algorithms
Spring 2016
Lab 7 README FILE

Due Date: 4/6/16
Submission Date: 4/4/16
Author(s): Lucie Pierre-Louis
e-mail(s): lpierre3@binghamton.edu

PURPOSE:
Implement the remove method, copy constructor and destructor for a Binary Search Tree

PERCENT COMPLETE:
100%

PARTS THAT ARE NOT COMPLETE:
N/A

BUGS:
N/A

FILES:
lab7.cpp
BSTree.cpp
BSTree.h
makefile
README

SAMPLE OUTPUT:
        TEST #0: Passes all tests from Lab 6

        ========================PASS========================


        TEST #1: Cannot remove node that is not in the tree
 [1]  [2]  [3]  [4]  [5]  [6]  [7]  [8]  [9]  [10]  [11]  [12]  [13]

        ========================PASS========================


        TEST #2: Remove a leaf node
 [2]  [3]  [4]  [5]  [6]  [7]  [8]  [9]  [10]  [11]  [12]  [13]

        ========================PASS========================


        TEST #3: Remove single branch using the Short Circuit algorithm
 [2]  [3]  [4]  [5]  [6]  [8]  [9]  [10]  [11]  [12]  [13]

        ========================PASS========================

Test #4: Remove two branch node promoting a leaf node
 [2]  [3]  [4]  [5]  [6]  [8]  [9]  [11]  [12]  [13]

        ========================PASS========================


        TEST #5: Remove two branch node promoting a 1 branch node using Short Circuit
 [2]  [3]  [4]  [5]  [6]  [8]  [9]  [12]  [13]

        ========================PASS========================


        TEST #6: Remove root with two branches
 [2]  [3]  [4]  [6]  [8]  [9]  [12]  [13]

        ========================PASS========================


        TEST #7: Remove root with one branch
 [8]  [9]  [12]  [13]

        ========================PASS========================


        TEST #8: Remove root as leaf


        ========================PASS========================


        TEST #9: Deep copy for a tree of 100 random values

        ========================PASS========================


        TEST #10: Test deletion and Destructor

        ========================PASS========================


TO RUN:
./lab7

EXTRA CREDIT:
N/A

BIBLIOGRAPHY:
N/A

MISCELLANEOUS:
N/A

