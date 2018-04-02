#include <assert.h>
#include <stdio.h>
#include "../../src/node/dg_node.h"

int main(int argc, char* argv[]) {

  DG_Node_T generic_node = new_dg_node();                                     // Node to test
  DG_Node_T generic_node_2 = new_dg_node();                                   // Node to test
  char test_data[] = "Test one";                                              // Data to use for testing
  char test_data_2[] = "Test one";                                            // Data to use for testing

  assert(dg_node_get_data(generic_node) == NULL);                             // The nodes data should default to NULL
  assert(dg_node_get_child(generic_node) == NULL);                            // The nodes next should default to NULL
  assert(dg_node_get_data(generic_node_2) == NULL);                           // The nodes data should default to NULL
  assert(dg_node_get_child(generic_node_2) == NULL);                          // The nodes next should default to NULL

  dg_node_add_data(generic_node, test_data);                                  // Set the data
  dg_node_add_data(generic_node_2, test_data_2);                              // Set the data
  dg_node_add_child(generic_node, generic_node_2);                            // Set next

  assert(dg_node_get_data(generic_node) == test_data);                        // Data should now be the test data
  assert(dg_node_get_data(generic_node) != test_data_2);                      // Data should not be the second test data
  assert(dg_node_get_data(generic_node_2) == test_data_2);                    // Data should now be the second test data
  assert(dg_node_get_data(generic_node_2) != test_data);                      // Data should not be the first test data
  assert(dg_node_get_child(generic_node) != NULL);                            // Next should no longer be null
  assert(dg_node_get_child(generic_node) == generic_node_2);                  // Next should be the second node
  assert(dg_node_get_data(dg_node_get_child(generic_node)) == test_data_2);   // Data should be the second test data
  assert(dg_node_get_data(dg_node_get_child(generic_node)) != test_data);     // Data should not be the first test data
  assert(dg_node_get_child(dg_node_get_child(generic_node)) == NULL);         // Next should be null as it isn't set

  free_dg_node(&generic_node);                                                // Free memory for the generic node (Should not error)
  assert(generic_node == NULL);                                               // Node should now be null

  /**
   * Recreate the generic node
   **/
  generic_node = new_dg_node();
  dg_node_add_data(generic_node, test_data);
  dg_node_add_child(generic_node, generic_node_2);

  free_dg_node(&generic_node_2);                                              // Free memory from the second generic node (Should not error)
  dg_node_add_data(generic_node, NULL);                                       // Free data on a DG_Node
  assert(generic_node_2 == NULL);                                             // Second node should be null
  assert(dg_node_get_data(generic_node) == NULL);                             // Data on generic node should be null

  /**
   * Recreate the second generic node
   **/
  generic_node_2 = new_dg_node();
  dg_node_add_data(generic_node_2, test_data_2);

  dg_node_add_child(generic_node, generic_node_2);                            // Reset generic nodes next

  free_dg_node(&generic_node_2);                                              // Free memory for second generic node
  free_dg_node(&generic_node);                                                // Free memory for generic node
  assert(generic_node == NULL);                                               // Node should now be null
  assert(generic_node_2 == NULL);                                             // Second Node should now be null

  /**
   * Test freeing data on a node
   */
  generic_node = new_dg_node();
  assert(dg_node_get_data(generic_node) == NULL);                             // generic nodes data should initialize to null
  int *a = malloc(sizeof(int));                                               // Data being freed should be on the heap
  *a = rand();                                                                // Set the data to a random integer
  dg_node_add_data(generic_node, a);                                          // Add data to the generic node
  assert(dg_node_get_data(generic_node) != NULL);                             // Make sure the data is not still equal to null
  assert(dg_node_get_data(generic_node) == a);                                // Make sure generic nodes data is a
  free_dg_node_data(&generic_node);                                           // Free the data on the generic node
  assert(dg_node_get_data(generic_node) == NULL);                             // generic nodes data should be null again
  free_dg_node_data(&generic_node);                                           // This should not throw an error
  free_dg_node(&generic_node);                                                // Free the generic node
  assert(generic_node == NULL);                                               // Node should now be null
  free_dg_node(&generic_node);                                                // This should not throw an error

  return(0);

}
