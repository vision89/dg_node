## Tutorial
We will create a small program using dg_nodes which will generate 10 random numbers, store each number in a dg_node, and set up a parent-child relationship between each node.  We will then iterate through the nodes from parent to child, printing out the data stored in each node during each iteration.  Finally we will iterate through the nodes again, freeing the data stored in each node as well as the node itself, during each iteration.
A complete list of the code in the file is in [tutorial/tutorial.c](tutorial/tutorial.c).
Note that throughout this tutorial I've tried to say dg_node but you may see the word node as well.  When I say dg_node and node I use them interchangeably to mean the same thing.  DG_Node is simply a 1 degree node, I named it with the dg in its name to avoid naming collisions.

1. Get dg_node.  If you look in tutorial.c you will see I reference the dg_node in the root of the directory.  You will need to download a copy of dg_node and reference it from the location that you put it.  I suggest getting it by navigating to the location you'd like to store it using the command line and typing `git clone https://github.com/vision89/dg_node.git`.  This assumes you have git installed.
2. Create the file to store this tutorial code, I use atom so from the command line I would go to the location I'd like to store the file and type:
  > atom tutorial.c
3. Within tutorial.c include stdio and dg_node.  Note that the location of your dg_node will be different then mine, so your reference path will be different:
  >#include <stdio.h>

  >#include "../../src/node/dg_node.h"
4. To keep from using **magic numbers** we will define a constant which says how many random numbers we will create (0 inclusive):
  > #define MAX 9
5. Now create the main method, the remainder of the code will be typed within the main method.
6. Create a root dg_node, we will be careful not to alter this so that we always have a reference back to the root node.  We will create a new dg_node using the function `new_dg_node`.  This function creates a new dg_node on the heap and returns it.  Since it is created on the heap it must later be freed.  There is a function included with dg_node which will both free the node and set it to NULL which we will go over shortly:
  > DG_Node \*root = new_dg_node();
7. Create another dg_node which has the purpose of iterating through our dg_nodes.
  > DG_Node \*iterator = root;
8. Add data to the root node.  The data in dg_node is of type `(void *)`.  Since we our storing integers in our dg_nodes we will need to create them on the heap and then store them in the node.  This means we will later need to free the data.  There is no build in function to free the data stored in the dg_node, this must be done manually:
  > int \*a = malloc(sizeof(int));

  > \*a = rand();

  > root->data = a;
9.
10. Iterate from 0 to MAX creating a new dg_node on each iteration.  Store a random integer in each node and set the new node as a child of the previous node:
  > for(int i = 0;i < MAX; ++i) {

    > int \*b = malloc(sizeof(int));

    > \*b = rand();

    > DG_Node \*temp_node = new_dg_node();

    > temp_node->data = b;

    > iterator->child = temp_node;

    > iterator = iterator->child;

  > }
11.  Now we will have a chain of nodes, and from our root node we could follow each child down the chain.  Set the iterator back to the root.
  > iterator = root;
12. Follow the chain of nodes and print the data stored in each.  DG_Node is created with the child set to NULL so we can follow the children down the chain until we reach a NULL value.
  > while(iterator != NULL) {

    > printf("%d\n", \*((int \*)iterator->data));

    > iterator = iterator->child;

  > }
13. Set the iterator back to the root node.
  > iterator = root;
14. Finally follow the chain of nodes again, freeing the data stored in each node, as well as the node itself.
  > while(iterator != NULL) {

    > DG_Node \*temp_node = iterator->child;

    > free(iterator->data);

    > free_dg_node(&iterator);

    > iterator = temp_node;

  > }
15.  That's it.  You can compile the code by running `gcc ../../src/node/dg_node.c  tutorial.c`.  Then run the code by typing `./a.out`.
16. You should see something similar to
[output]: tutorial_screenshot.png "output".
17. That wraps it up.  Again, for a complete reference to the code above please see [tutorial/tutorial.c](tutorial/tutorial.c).
