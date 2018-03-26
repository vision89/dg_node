#include <assert.h>
#include <stdio.h>
#include "../../src/node/dg_node.h"

int main(int argc, char* argv[]) {

  DG_Node* generic_node = new_node();                    // Node to test
  DG_Node* generic_node_2 = new_node();                  // Node to test
  char test_data[] = "Test one";                      // Data to use for testing
  char test_data_2[] = "Test one";                    // Data to use for testing

  assert(generic_node->data == NULL);                 // The nodes data should default to NULL
  assert(generic_node->next == NULL);                 // The nodes next should default to NULL
  assert(generic_node_2->data == NULL);               // The nodes data should default to NULL
  assert(generic_node_2->next == NULL);               // The nodes next should default to NULL

  generic_node->data = test_data;                     // Set the data
  generic_node_2->data = test_data_2;                 // Set the data
  generic_node->next = generic_node_2;                // Set next

  assert(generic_node->data == test_data);            // Data should now be the test data
  assert(generic_node->data != test_data_2);          // Data should not be the second test data
  assert(generic_node_2->data == test_data_2);        // Data should now be the second test data
  assert(generic_node_2->data != test_data);          // Data should not be the first test data
  assert(generic_node->next != NULL);                 // Next should no longer be null
  assert(generic_node->next == generic_node_2);       // Next should be the second node
  assert((generic_node->next)->data == test_data_2);  // Data should be the second test data
  assert((generic_node->next)->data != test_data);    // Data should not be the first test data
  assert((generic_node->next)->next == NULL);         // Next should be null as it isn't set

  free_node(&generic_node);                           // Free memory for the generic node (Should not error)
  assert(generic_node == NULL);                       // Node should now be null

  /**
   * Recreate the generic node
   **/
  generic_node = new_node();
  generic_node->data = test_data;
  generic_node->next = generic_node_2;

  free_node(&generic_node_2);                        // Free memory from the second generic node (Should not error)
  generic_node->data = NULL;                         // Still need to do this manually
  assert(generic_node_2 == NULL);                    // Second node should be null

  /**
   * Recreate the second generic node
   **/
  generic_node_2 = new_node();
  generic_node_2->data = test_data_2;

  generic_node->next = generic_node_2;             // Reset generic nodes next

  free_node(&generic_node_2);                      // Free memory for second generic node
  free_node(&generic_node);                        // Free memory for generic node
  assert(generic_node == NULL);                    // Node should now be null
  assert(generic_node_2 == NULL);                  // Second Node should now be null

  return(0);

}
