#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../../src/node/dg_node.h"

int main(int argc, char* argv[]) {
  char *test_data = malloc(9 * sizeof(char));                                                                                 // Will be data to use for testing
  char *test_data_2 = malloc(9 * sizeof(char));                                                                               // Will be data to use for testing
  dg_node_td generic_node = new_dg_node();                                                                                    // Node to test
  dg_node_td generic_node_2 = new_dg_node();                                                                                  // Node to test

  test_data = "Test one\0";                                                                                                   // Data to use for testing
  test_data_2 = "Test two\0";                                                                                                 // Data to use for testing

  assert(generic_node->get_data(generic_node) == NULL);                                                                       // The nodes data should default to NULL
  assert(generic_node->get_child(generic_node) == NULL);                                                                      // The nodes next should default to NULL
  assert(generic_node_2->get_data(generic_node_2) == NULL);                                                                   // The nodes data should default to NULL
  assert(generic_node_2->get_child(generic_node_2) == NULL);                                                                  // The nodes next should default to NULL

  generic_node->set_data(generic_node, test_data);                                                                            // Set the data
  generic_node_2->set_data(generic_node_2, test_data_2);                                                                      // Set the data
  generic_node->set_child(generic_node, generic_node_2);                                                                      // Set next

  assert(strcmp(generic_node->get_data(generic_node), test_data) == 0);                                                       // Data should now be the test data
  assert(strcmp(generic_node->get_data(generic_node), test_data_2) != 0);                                                     // Data should not be the second test data
  assert(strcmp(generic_node_2->get_data(generic_node_2), test_data_2) == 0);                                                 // Data should now be the second test data
  assert(strcmp(generic_node_2->get_data(generic_node_2), test_data) != 0);                                                   // Data should not be the first test data
  assert(generic_node->get_child(generic_node) != NULL);                                                                      // Next should no longer be null
  assert(generic_node->get_child(generic_node) == generic_node_2);                                                            // Next should be the second node
  assert(strcmp((generic_node->get_child(generic_node))->get_data(generic_node->get_child(generic_node)), test_data_2) == 0); // Data should be the second test data
  assert(strcmp((generic_node->get_child(generic_node))->get_data(generic_node->get_child(generic_node)), test_data) != 0);   // Data should not be the first test data
  assert((generic_node->get_child(generic_node))->get_child(generic_node->get_child(generic_node)) == NULL);                  // Next should be null as it isn't set

  generic_node->free(&generic_node);                                                                                          // Free memory for the generic node (Should not error)
  assert(generic_node == NULL);                                                                                               // Node should now be null

  /**
   * Recreate the generic node
   **/
  generic_node = new_dg_node();
  generic_node->set_data(generic_node, test_data);
  generic_node->set_child(generic_node, generic_node_2);

  generic_node_2->free(&generic_node_2);                                                                                      // Free memory from the second generic node (Should not error)
  generic_node->set_child(generic_node, NULL);                                                                                // Free data on a DG_Node
  assert(generic_node_2 == NULL);                                                                                             // Second node should be null
  assert(generic_node->get_child(generic_node) == NULL);                                                                      // Data on generic node should be null

  /**
   * Recreate the second generic node
   **/
  generic_node_2 = new_dg_node();
  generic_node_2->set_data(generic_node_2, test_data_2);

  generic_node->set_child(generic_node, generic_node_2);                                                                      // Reset generic nodes next

  generic_node_2->free(&generic_node_2);                                                                                      // Free memory for second generic node
  generic_node->free(&generic_node);                                                                                          // Free memory for generic node
  assert(generic_node == NULL);                                                                                               // Node should now be null
  assert(generic_node_2 == NULL);                                                                                             // Second Node should now be null

  /**
   * Test freeing data on a node
   */
  generic_node = new_dg_node();
  assert(generic_node->get_data(generic_node) == NULL);                       // generic nodes data should initialize to null
  int *a = malloc(sizeof(int));                                               // Data being freed should be on the heap
  *a = rand();                                                                // Set the data to a random integer
  generic_node->set_data(generic_node, a);                                    // Add data to the generic node
  assert(generic_node->get_data(generic_node) != NULL);                       // Make sure the data is not still equal to null
  assert(generic_node->get_data(generic_node) == a);                          // Make sure generic nodes data is a
  generic_node->free_data(generic_node);                                      // Free the data on the generic node
  assert(generic_node->get_data(generic_node) == NULL);                       // generic nodes data should be null again
  generic_node->free_data(generic_node);                                      // This should not throw an error
  generic_node->free(&generic_node);                                          // Free the generic node
  assert(generic_node == NULL);                                               // Node should now be null

  return(0);

}
