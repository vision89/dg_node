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
 * @brief A Type referring to a degree 1 node structure.
 * @author Dustin Gulley
 * @date 03/30/2018
 * A Type referring to a degree 1 node structure.
 *
 */
typedef struct DG_Node *DG_Node_T;

/**
 *
 * @brief Creates and returns a new DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Creates and returns a new DG_Node.
 *
 */
extern DG_Node_T new_dg_node();

/**
 *
 * @brief Add a child node to a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Add a child node to a DG_Node.
 *
 */
extern void dg_node_add_child(DG_Node_T node, DG_Node_T child_node);

/**
 *
 * @brief Add data to a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Add data to a DG_Node.
 *
 */
extern void dg_node_add_data(DG_Node_T node, void *datum);

/**
 *
 * @brief Gets data attached to a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Gets data attached to a DG_Node.
 *
 */
extern void * dg_node_get_data(DG_Node_T node);

/**
 *
 * @brief Gets a child attached to a DG_Node.
 * @author Dustin Gulley
 * @date 03/30/2018
 * Gets a child attached to a DG_Node.
 *
 */
extern DG_Node_T dg_node_get_child(DG_Node_T node);

/**
 *
 * @brief Frees an allocated DG_Node
 * @author Dustin Gulley
 * @date 03/30/2018
 * Frees an allocated DG_Node
 *
 */
extern void free_dg_node(DG_Node_T *node);

/**
 *
 * @brief Frees data associated with a DG_Node.
 * @author Dustin Gulley
 * @date 04/01/2018
 * Frees data associated with a DG_Node.
 */
extern void free_dg_node_data(DG_Node_T *node);

#endif                                // DG_NODE_H_
