#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    //object.deleteBig(object.returnRoot()->right, object.returnRoot());
    object.deleteLeaves(object.returnRoot(), object.returnRoot());
    
    object.display();	//displays again after!
   
    return 0;
}
