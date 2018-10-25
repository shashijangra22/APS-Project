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

# Technologies to be used

| Title  | Details |
| ------------- | ------------- |
| Languages  | C, C++, Python, Markdown  |
| Tools  | Sublime Text, Git  |

# Deliverables

The project delivers the following functionalities as an api to the user : 

| Function  | Syntax | Parameters | Description | Complexity |
| ------------- | ------------- | ------------- | ------------- | ------------- |
| Create Heap | create() | None | returns root pointer of newly created heap | O(1) |
| Insert | H.insert(x) | key to insert | insert a key x to heap | O(log(n)) |
| Get Minimum  | H.getMin() | None | returns minimum element in the heap | O(1) |
| Delete  | H.delete(x) | key to delete | deletes the key x in the heap | O(log(n)) |
| Extract Minimum  | H.extractMin()  | None | deletes minimum element in the heap | O(log(n)) |
| Decrease Key  | H.decreaseKey(x,y) | key to be modified, new value to update | decreases the key x by value y | O(log(n)) |
| Merge  | H.merge(X) | heap root pointer to merge with | merges the 2 heaps H and X | O(log(n)) |

# Project delivery plan

We aim to deliver the project as a menu driven program which allows user to build a binary heap with all the standard heap functions and a merge function which works in O(log n) time.

# End User Documentation

  - go to root directory of project and simply run `make` command through terminal.
  - execute the `main` file via terminal command.
  - Operations supported are as follows : 

| Operation  | Input Format | Description |
| ------------- | ------------- | ------------- |
| Create Heap | 1\<space\>\<enter\> | Create a new heap. |
| Insert | 2\<space\>\<key\>\<enter\> | Insert key to heap. |
| Get Minimum | 3\<enter\> | returns the minimum key in heap. |
| Delete | 4\<space\>\<key\>\<enter\> | deletes the key in the heap |
| Extract Minimum  | 5\<enter\> | deletes minimum element in the heap |
| Decrease Key | 6\<space\>\<key\>\<space\>\<new value\>\<enter\> | decreases the key by value |

# Online resources
[Fibonacci Heaps [cs.princeton.edu]](https://www.cs.princeton.edu/~wayne/teaching/fibonacci-heap.pdf)
<br>
[Binomial Heaps [Wiki]](https://en.wikipedia.org/wiki/Binomial_heap)
<br>
[cs.toronto.edu](http://www.cs.toronto.edu/~anikolov/CSC265F18/binomial-heaps.pdf)
<br>
[Geeksforgeeks](https://www.geeksforgeeks.org/binomial-heap-2/)

# Plan for testing
An input file of a specified format can be supplied as an input to the program which includes test cases that encounters the best, avg. and worst time complexity of Binomial heap functions.

# Team members
- Shashi Jangra
- Varun Gupta
