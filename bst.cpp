#include "bst.h"

bst::bst(){root = NULL;}
int bst::returnLeaves(node* current) {
  if(current == NULL) {
    return 0;
  }
  else if(current->left == NULL && current->right == NULL) {
    return 1;
  }
  else {
  return returnLeaves(current->left)+returnLeaves(current->right);
  }
}
void bst::deleteLeaves(node* current, node* parent) {
  if(current == NULL) {
    return;
  }
  if(current->left == NULL && current->right == NULL) {
    node* temp = current;
    if(parent->left == current) {
      parent->left = NULL;
    }
    else {
      parent->right = NULL;
    }
    delete temp;
    return;
  }
  deleteLeaves(current->left, current);
  deleteLeaves(current->right, current);
}
node* bst::returnRoot() {
  return root;
}
void bst::deleteSmall(node* & root, node* current, node* parent) {
  if(current->left != NULL) {
    deleteSmall(root, current->left, current);
  }
  else {
    if(current == root) {
      node* temp = root;
      root = root->right;
      delete temp;
    }
    else if(current->right != NULL) {
      node* temp = current;
      parent->left = current->right;
      delete temp;
    }
    else {
      node* temp = current;
      parent->left = NULL;
      delete temp;
    }
  }
}
void bst::findPredecessor(node* root, node* current) {
  if(current == NULL) {
    if(root->left == current) {
      cout << "The root is the biggest" << endl;
    }
    return;
  }
  if(current == root) {
    findPredecessor(root, current->left);
  }
  else if(current->right != NULL) {
    findPredecessor(root, current->right);
  }
  else {
    
      cout << "Predecessor found!" << endl;
      cout << current->data << endl;
      
  }
}
void bst::deleteBig(node* current, node* parent) {
  if(current == NULL) {
    return;
  }
  deleteBig(current->left, current);
  deleteBig(current->right, current);
  cout << current->data << endl;
  if(parent->left == current) {
    parent->left = NULL;
  }
  else {
    parent->right = NULL;
  }
  delete current;
}
void bst::build() {
  srand((unsigned)time(0));
  int arrayLength = rand()%5+10;
  int values[arrayLength];
  for (int a = 0; a < arrayLength; a++){values[a] = -1;}
  for (int a = 0; a < arrayLength; a++) {
    bool duplicate = false;
    do {
      duplicate = false;
      values[a] = rand()%30+1;
      for (int b = 0; b < arrayLength; b++) {
        if ((a != b) && (values[a] == values[b])) {duplicate = true;}
      }
    } while (duplicate == true);
  }
  for (int a = 0; a < arrayLength; a++) {
    node* newnode = new node();
    newnode->data = values[a];
    node* current = root;
    if (root == NULL) {
      root = newnode;
    }
    else {
      while(current != NULL) {
        if (newnode->data < current->data) {
          if (current->left == NULL) {
            current->left = newnode;
	    break;
	  }
	  else {
            current = current->left;
	  }
	}
	else {
          if (current->right == NULL) {
            current->right = newnode;
	    break;
	  }
	  else {
            current = current->right;
	  }
	}
      }
    }
  }
}

void bst::display_tree(node* current, int level) {
  if (current->right != NULL) {display_tree(current->right, level+1);}
  for (int a = 0; a < level; a++) {cout << "\t";}
  cout << current->data << " (";
  if (current->left != NULL) cout << current->left->data << ",";
  else cout << ",";
  if (current->right != NULL) cout << current->right->data << ")" << endl;
  else cout << ")" << endl;
  if (current->left != NULL) {display_tree(current->left, level+1);}
}

void bst::display() {
  cout << "---------Tree Printout----------" << endl;
  display_tree(root, 0);
  cout << "--------------------------------" << endl;
}
