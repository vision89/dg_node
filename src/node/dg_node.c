/**
 *
 * @file dg_node.c
 * @brief Contains functions for creating and freeing a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 *
 */

#include "dg_node.h"

/**
 *
 * @brief Creates and returns a new DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Creates and returns a new DG_Node.
 *
 */
DG_Node* new_dg_node() {
  DG_Node* generic_node = malloc(sizeof(DG_Node));  // Create a new node
  generic_node->data = NULL;                        // Default data to null
  generic_node->child = NULL;                        // Default next to null

  return generic_node;                              // Return the new node
}

/**
 *
 * @brief Frees an allocated DG_Node
 * @author Dustin Gulley
 * @date 03/30/2018
 * Frees an allocated DG_Node
 *
 */
void free_dg_node(DG_Node **node) {
  free(*node);
  *node = NULL;
}
