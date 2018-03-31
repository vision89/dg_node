## Overview
* DG_Node is distributed under the New BSD license.  
* DG_Node is a typical node data structure.  It's intended to be used in creating other data structures such as linked lists.  
* The DG_Node struct contains two members, one is a datum of type void and the other is a reference to another DG_Node.  
* There are two methods associated with DG_Node.  One for creating a new DG_Node and another for freeing an existing DG_Node.
* To run the tests, run the file run_tests.sh.  Note that this requires gcc and that this has only been tested within elementary os and max osx high sierra.
* Run generate_documentation.sh to generate the reference documentation.  Note that this requires doxygen and moxygen, and has only been tested within elementary os.
