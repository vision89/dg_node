/**
 * A small program as a tutorial for using dg_node
 * It will create 10 random integers
 * Each integer will be stored in a dg_node
 * The dg_nodes will be connected
 * We will iterate through the nodes going from parent to child and print out each integer
 * Afterwards we will free the dg_nodes and the data they contain
 */

#include <stdio.h>
#include "../../src/node/dg_node.h"

/**
 * The number of random integers we will create (0 inclusive)
 */
#define MAX 9

int main() {

  /**
   * Reference to the root node
   */
  dg_node_td root = new_dg_node();

  /**
   * Node used for iteration
   */                                                                              // Node to test
  dg_node_td iterator = root;

  /**
   * Add data to the node
   */
   int *a = malloc(sizeof(int));
   *a = rand();
   root->set_data(root, a);

   for(int i = 0;i < MAX; ++i) {
     int *b = malloc(sizeof(int));
     *b = rand();

     /**
      * Create a new node and add it to the iterators child reference
      */
     dg_node_td temp_node = new_dg_node();
     temp_node->set_data(temp_node, b);
     iterator->set_child(iterator, temp_node);

     //Set iterator to the child as we continue the loop
     iterator = iterator->get_child(iterator);

   }

   //Set iterator back to root
   iterator = root;

   /**
    * We iterate through all the nodes and print their data.
    * Notice that child initializes to NULL so you can iterate
    * until NULL is reached.
    */
   while(iterator != NULL) {
     printf("%d\n", *((int *) iterator->get_data(iterator)));
     iterator = iterator->get_child(iterator);
   }

   //Set iterator back to root
   iterator = root;

   /**
    * We will loop through the dg_nodes and free the data they
    * contain and the node itself.
    */
   while(iterator != NULL) {
     dg_node_td temp_node = iterator->get_child(iterator);  //Get a reference to the next node as we will free the parent
     iterator->free_data(iterator);                         //Free the contained data
     iterator->free(&iterator);                             //Free the node
     iterator = temp_node;                                  //Set iterator to the child and continue
   }

   return 0;

}
