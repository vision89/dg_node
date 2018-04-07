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
struct dg_node_data {
  void *data;
  struct dg_node *child;
};

/**
 *
 * @brief Add a child node to a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Add a child node to a DG_Node.
 *
 */
static void dg_node_set_child(dg_node_td self, struct dg_node child) {
  dg_node_data_td node = self->node;
  node->child = &child;
}

/**
 *
 * @brief Add data to a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Add data to a DG_Node.
 *
 */
static void dg_node_set_data(dg_node_td self, void *datum) {
  dg_node_data_td node = self->node;
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
static void * dg_node_get_data(dg_node_td self) {
  dg_node_data_td node = self->node;
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
static dg_node_td dg_node_get_child(dg_node_td self) {
  dg_node_data_td node = self->node;
  return node->child;
}

/**
 *
 * @brief Frees data associated with a DG_Node.
 * @author Dustin Gulley
 * @date 04/01/2018
 * Frees data associated with a DG_Node.
 */
static void free_dg_node_data(dg_node_data_td *node) {
  if(node != NULL) {
    free(*node);
    *node = NULL;
  }
}

/**
 *
 * @brief Frees an allocated DG_Node
 * @author Dustin Gulley
 * @date 03/30/2018
 * Frees an allocated DG_Node
 *
 */
static void free_dg_node(dg_node_td *self) {

  dg_node_data_td node = (*self)->node;
  free_dg_node_data(&node);

  if(self != NULL) {
    free(self);
    self = NULL;
  }
}

/**
 *
 * @brief Creates node data
 * @author Dustin Gulley
 * @date 03/30/2018
 * Creates node data
 *
 */
dg_node_data_td dg_node_data_new() {

  dg_node_data_td generic_node = malloc(sizeof(struct dg_node_data));
  generic_node->data = NULL;
  generic_node->child = NULL;

  return generic_node;

}

/**
 *
 * @brief Creates and returns a new DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Creates and returns a new DG_Node.
 *
 */
dg_node_td new_dg_node() {

  //Create a new node
  dg_node_td new_node = malloc(sizeof(struct dg_node));   // Create a new node
  new_node->node = dg_node_data_new();
  new_node->set_child = &dg_node_set_child;
  new_node->set_data = &dg_node_set_data;
  new_node->get_data = &dg_node_get_data;
  new_node->get_child = &dg_node_get_child;
  new_node->free = &free_dg_node;

  return new_node;                                        // Return the new node
}
