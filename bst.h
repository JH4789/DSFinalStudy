//bst.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class bst
{
    public:
    	//These functions are supplied already
    	bst();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
  
  void deleteBig(node*, node*);
  node* returnRoot();
  void deleteSmall(node*&, node*, node*);
  void findPredecessor(node*, node*);
  int returnLeaves(node*);
  void deleteLeaves(node*, node*);
 	private:
                node * root;
  
		void display_tree(node*, int);
                
};
  

