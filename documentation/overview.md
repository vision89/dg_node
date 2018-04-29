## Overview
* DG_Node is distributed under the New BSD license.  
* DG_Node is a typical node data structure.  It's intended to be used in creating other data structures such as linked lists.  
* The dg_node struct contains 6 methods, set_child, set_data, get_data, get_child, free, and free_data.  To create a new dg_node use the initialization function new_dg_node.
* To run the tests, run the file run_tests.sh.  Note that this requires gcc and that this has only been tested within elementary os and max osx high sierra.
* Run generate_documentation.sh to generate the reference documentation.  Note that this requires doxygen and moxygen, and has only been tested within elementary os.
