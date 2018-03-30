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
 * @brief dg_node_t structure
 * @author Dustin Gulley
 * @date 03/30/2018
 * The DG_Node_t structure holds void data and a reference to another node
 *
 */
struct DG_Node_t {
  void *data;                         /**< Single datum held by the dg_node. */
  struct DG_Node_t *next;             /**< Reference to another dg_node. */
};

typedef struct DG_Node_t DG_Node;     /**< A realization of the DG_Node_t.  This is the typical type used. */

/**
 *
 * @brief Creates and returns a new DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Creates and returns a new DG_Node.
 *
 */
DG_Node* new_node();

/**
 *
 * @brief Frees an allocated DG_Node
 * @author Dustin Gulley
 * @date 03/30/2018
 * Frees an allocated DG_Node
 *
 */
void free_node(DG_Node **node);

#endif                                // DG_NODE_H_
