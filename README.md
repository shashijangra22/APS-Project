# Project Title : Binomial Heap
## Contents

- [x] <a href="#project-title-binomial-heap">Title of project</a>
- [x] <a href="#technologies-to-be-used">Technologies to be used</a>
- [x] <a href="#deliverables">Deliverables</a>
- [x] <a href="#project-delivery-plan">Project delivery plan</a>
- [x] <a href="#end-user-documentation">End User Documentation</a>
- [x] <a href="#online-resources">Online resources</a>
- [x] <a href="#plan-for-testing">Plan for testing</a>
- [x] <a href="#team-members">Team members</a>


# Binomial Heap

A binomial heap is implemented as a set of binomial trees (compare with a binary heap, which has a shape of a single binary tree), which are defined recursively as follows:
A Binomial Tree of order 0 has 1 node. A Binomial Tree of order k can be constructed by taking two binomial trees of order k-1 and making one as leftmost child or other.
A Binomial Tree of order k has following properties.
- It has exactly 2k nodes.
- It has depth as k.
- There are exactly kCi nodes at depth i for i = 0, 1, . . . , k.
- The root has degree k and children of root are themselves Binomial Trees with order k-1, k-2,.. 0 from left to right.

Because of its unique structure, a binomial tree of order k can be constructed from two trees of order k−1 trivially by attaching one of them as the leftmost child of the root of the other tree. This feature is central to the merge operation of a binomial heap, which is its major advantage over other conventional heaps.

# Deliverables

The project delivers the following functionalities via binomial heap as an api to the user : 

| Function  | Syntax | Parameters | Description | Complexity |
| ------------- | ------------- | ------------- | ------------- | ------------- |
| Create Heap | create() | None | returns root pointer of newly created heap | O(1) |
| Insert | H.insert(x) | key to insert | insert a key x to heap | O(log(n)) |
| Get Minimum  | H.getMin() | None | returns minimum element in the heap | O(1) |
| Delete  | H.delete(x) | key to delete | deletes the key x in the heap | O(log(n)) |
| Extract Minimum  | H.extractMin()  | None | deletes minimum element in the heap | O(log(n)) |
| Decrease Key  | H.decreaseKey(x,y) | key to be modified, new value to update | decreases the key x by value y | O(log(n)) |
| Merge  | H.merge(X) | heap root pointer to merge with | merges the 2 heaps H and X | O(log(n)) |

Along with above mentioned functionalities,this projects aims to provide comparative analysis on below major operations with that of AVL tree:-
  - Insertion
  - Deletion
  - Search

Also, we have implemented Prim's Algorithm using Binomial heap.The basic method to finding a Minimum Spanning Tree is based on a greed approach. From a particular vertex ,the next vertex is so chosen so that it can be connected to the current tree
using the edge of the lowest weight. Repeating this process until all the nodes are included yields the Minimum Spanning Tree. The Prim’s Algorithm is based on the above approach. It uses a Heap for finding the next vertex with the minimum edge weight which can be included in the Minimum spanning tree.

# Technologies to be used

| Title  | Details |
| ------------- | ------------- |
| Languages  | C, C++, Python, Markdown  |
| Tools  | Sublime Text, Git  |

# Project delivery plan

We aim to deliver the project as a menu driven program which allows user to build a binary heap with all the standard heap functions and a merge function which works in O(log n) time.
Along with that  compare its performance with AVL and 

# End User Documentation

## Binomial heap functionalities implementation:- 

  - go to directory of project and simply run g++ -o binomial binomialheap.cpp command through terminal.
  - The corresponding .out will be generated. Execute this file using the command ./binomial.out .
  - A menu will be prompted requesting for the operation to be performed.
      - Press 1 to insert. Then provide the value to be inserted in the binomial heap.
      - Press 2 to extract min. Returns the minimum value present in the the binomial heap. 
      - Press 3 to decrease key. Terminal will prompt for old key. Provide the old key following with the new key(It should be smaller than the old key).Old key will be replaced with the new key(smaller value). If the new value is greater than the old value, then the program will show the error message.
      - Press 4 to delete a value from the binomial heap and then provide the value to be deleted.
      - Press 5 to quit from the menu driven program.
      - Press 6 to print the binomial heap.
      
## Performance Comparison with AVL tree :-
  
### Time analysis for insertion and deletion in Binomial heap:- 
  - go to directory of project and simply run g++ -o comparebinomial comp_analysis.cpp command through terminal.
  - The corresponding .out will be generated. Execute this file using the command ./comparebinomial.out .
  - The terminal will prompt for filename:-
    There are three input files:-
      - random.txt - contains around 20.000 random numbers.
      - sorted.txt - contains numbers 1-20,00,000 in increasing order.
      - reverse.txt - contains numbers 1-20,00,000 in descending order .
    Provide the filename accordingly.
  - The terminal will prompt for the numbers of values to be inserted from the file(Maximum value can be 20,00,000).
  - The program will create a binomial heap which contains the number of values that are selected in prior step and data will be from the file that was selected earlier. The same program will delete all the values inserted. At the end, it will show the time taken during insertion and time taken for the deletion of all the elements in the binomial heap.
  
### Time analysis for insertion and deletion in AVL tree:- 
  - go to directory of project and simply run g++ -o compareavl avl.cpp command through terminal.
  - The corresponding .out will be generated. Execute this file using the command ./compareavl.out .
  - The terminal will prompt for filename:-
    There are three input files:-
      - random.txt - contains around 20.000 random numbers.
      - sorted.txt - contains numbers 1-20,00,000 in increasing order.
      - reverse.txt - contains numbers 1-20,00,000 in descending order .
    Provide the filename accordingly.
  - The terminal will prompt for the numbers of values to be inserted from the file(Maximum value can be 20,00,000).
  - The program will create a AVL tree which contains the number of values that are selected in prior step and data will be from the file that was selected earlier. The same program will delete all the values inserted. At the end, it will show the time taken during insertion and time taken for the deletion of all the elements in the AVL tree.
  
#### Graph demonstarting the performance analysis for insert, search and delete operations between Binomial Heap and AVL tree:-
![Insert Comparison on Random data](/images/Insert_random.png)
<br>
![Insert Comparison on Sorted data](/images/Insert_sorted.png)
<br>
![Deletion Comparison on Random data](/images/Delete_random.png)
<br>
![Deletion Comparison on Sorted data](/images/Delete_sorted.png)
<br>
![Search Comparison on Random data](/images/Search_random.png)
<br>
![Search Comparison on Sorted data](/images/Search_sorted.png)
<br>
  
## Implementation of Prim's Algorithm using Binomial heap :-

 - go to directory of project and simply run g++ -o prim prims.cpp command through terminal.
 - The corresponding .out will be generated. Execute this file using the command ./prim.out <filename> .<br>
   There are two input files:-
      - prim1.txt - contains a graph information that has 20 vertices and 159 edges.
      - prim2.txt - contains a graph information that has 5 vertices and 8 edges.<br>
   Input File format:- 
      - First line contains number of vertices followed by number of edges(n).
      - There are following n lines that conatins information about edges. Source, destination and weight of the edges.<br>
 - Output:- 
      - The edges that will be present in the Minimum Spanning tree(Format:- Source Destination )
      - Weight of the minimum spanning tree
    

# Online resources

[Binomial Heaps [Wiki]](https://en.wikipedia.org/wiki/Binomial_heap)
<br>
[Binomial Heaps Overview](https://www.growingwiththeweb.com/data-structures/binomial-heap/overview/)
<br>
[cs.toronto.edu](http://www.cs.toronto.edu/~anikolov/CSC265F18/binomial-heaps.pdf)
<br>
[Geeksforgeeks](https://www.geeksforgeeks.org/binomial-heap-2/)
<br>
[Fibonacci Heaps [cs.princeton.edu]](https://www.cs.princeton.edu/~wayne/teaching/fibonacci-heap.pdf)


# Team members
- Shashi Jangra
- Varun Gupta
