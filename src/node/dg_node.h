/**
 *
 * @file dg_node.ht
 * @brief this header file contains the dg_node struct and all functions associated with the dg_node.
 * @author Dustin Gulley
 * @date 03/30/2018
 *
 */

#ifndef DG_NODE_H_   // Include guard
#define DG_NODE_H_

#include <sys/types.h>
#include <stdlib.h>

/**
 *
 * @brief A Type referring degree 1 node data.
 * @author Dustin Gulley
 * @date 03/30/2018
 * A Type referring to the data associated with a degree 1 node structure.
 *
 */
typedef struct dg_node_data *dg_node_data_td;

/**
 *
 * @brief A Type referring degree 1 node data and behaviors.
 * @author Dustin Gulley
 * @date 03/30/2018
 * A Type referring to the data and behaviors associated with a degree 1 node structure.
 *
 */
typedef struct dg_node {

  /**
   *
   * @brief Data of a degree 1 node data.
   * @author Dustin Gulley
   * @date 03/30/2018
   * Data associated with a degree 1 node structure.
   *
   */
  dg_node_data_td node;

  /**
   *
   * @brief Add a child node to a DG_Node.
   * @author Dustin Gulley
   * @date 03/30/2018
   * Add a child node to a DG_Node.
   *
   */
  void (*set_child) (struct dg_node *self, struct dg_node * child);

  /**
   *
   * @brief Add data to a DG_Node.
   * @author Dustin Gulley
   * @date 03/30/2018
   * Add data to a DG_Node.
   *
   */
  void (*set_data) (struct dg_node *self, void *datum);

  /**
   *
   * @brief Gets data attached to a DG_Node.
   * @author Dustin Gulley
   * @date 03/30/2018
   * Gets data attached to a DG_Node.
   *
   */
  void * (*get_data) (struct dg_node *self);

  /**
   *
   * @brief Gets a child attached to a DG_Node.
   * @author Dustin Gulley
   * @date 03/30/2018
   * Gets a child attached to a DG_Node.
   *
   */
  struct dg_node * (*get_child) (struct dg_node *self);

  /**
   *
   * @brief Frees an allocated DG_Node
   * @author Dustin Gulley
   * @date 03/30/2018
   * Frees an allocated DG_Node
   *
   */
  void (*free) (struct dg_node **self);

  /**
  *
  * @brief Frees data on a DG_Node
  * @author Dustin Gulley
  * @date 04/07/2018
  * Frees data on a DG_Node
  *
  */
  void (*free_data) (struct dg_node *self);

} * dg_node_td;

/**
 *
 * @brief Creates and returns a new DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Creates and returns a new DG_Node.
 *
 */
extern dg_node_td new_dg_node();

#endif                                // DG_NODE_H_
