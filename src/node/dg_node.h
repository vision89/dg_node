#ifndef DG_NODE_H_   // Include guard
#define DG_NODE_H_

#include <sys/types.h>
#include <stdlib.h>

// A node designed to be used in the linked list
struct DG_Node_t {
  void *data;                         // Generic Data
  struct DG_Node_t *next;             // The next node in the list
};

typedef struct DG_Node_t DG_Node;     // Node structure

DG_Node* new_node();                  // Get a new node

void free_node(DG_Node **node);       // Free the allocated node

#endif                                // DG_NODE_H_
