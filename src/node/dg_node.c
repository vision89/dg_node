#include "dg_node.h"

/**
 * Get a new node
**/
DG_Node* new_node() {
  DG_Node* generic_node = malloc(sizeof(DG_Node));  // Create a new node
  generic_node->data = NULL;                  // Default data to null
  generic_node->next = NULL;                  // Default next to null

  return generic_node;                        // Return the new node
}

/**
 * Free memory for an allocated node
**/
void free_node(DG_Node **node) {
  free(*node);
  *node = NULL;
}
