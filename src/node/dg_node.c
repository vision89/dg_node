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
 * @brief A realization of DG_Node_T.
 * @author Dustin Gulley
 * @date 03/30/2018
 * A realization of DG_Node_T, which is a type referring to a degree 1 node structure.
 *
 */
struct DG_Node {
  void *data;
  struct DG_Node *child;
};

/**
 *
 * @brief Creates and returns a new DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Creates and returns a new DG_Node.
 *
 */
DG_Node_T new_dg_node() {
  DG_Node_T generic_node = malloc(sizeof(struct DG_Node));  // Create a new node
  generic_node->data = NULL;                        // Default data to null
  generic_node->child = NULL;                        // Default next to null

  return generic_node;                              // Return the new node
}

/**
 *
 * @brief Add a child node to a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Add a child node to a DG_Node.
 *
 */
void dg_node_add_child(DG_Node_T node, DG_Node_T child_node) {
  node->child = child_node;
}

/**
 *
 * @brief Add data to a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Add data to a DG_Node.
 *
 */
void dg_node_add_data(DG_Node_T node, void *datum) {
  node->data = datum;
}

/**
 *
 * @brief Gets data attached to a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Gets data attached to a DG_Node.
 *
 */
void * dg_node_get_data(DG_Node_T node) {
  return node->data;
}

/**
 *
 * @brief Gets a child attached to a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Gets a child attached to a DG_Node.
 *
 */
DG_Node_T dg_node_get_child(DG_Node_T node) {
  return node->child;
}

/**
 *
 * @brief Frees an allocated DG_Node
 * @author Dustin Gulley
 * @date 03/30/2018
 * Frees an allocated DG_Node
 *
 */
void free_dg_node(DG_Node_T *node) {
  if((*node) != NULL) {
    free(*node);
    *node = NULL;
  }
}

/**
 *
 * @brief Frees data associated with a DG_Node.
 * @author Dustin Gulley
 * @date 04/01/2018
 * Frees data associated with a DG_Node.
 */
void free_dg_node_data(DG_Node_T *node) {
  if((*node)->data != NULL) {
    free((*node)->data);
    (*node)->data = NULL;
  }
}
