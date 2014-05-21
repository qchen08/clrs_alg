#include <stdio.h>
#include <iostream>

struct tree{
	int value;
	struct tree *left;
	struct tree *right;
};

// return true if the sub-trees of node1 and node2 are equivalent //
bool compare(struct tree *node1, struct tree *node2){
	bool ret = true;
	if((node1 != NULL && node2 == NULL) ||
	   (node2 != NULL && node1 == NULL) 
	  ){
		ret = false;
	}
	
	if(node1 != NULL && node2 != NULL)
		if(node1->value != node2->value)
			ret = false;

	if(node1 != NULL && node2 != NULL)
		return ret && compare(node1->right, node2->right) && compare(node1->left, node2->left);
	else
		return ret;
}

int main(){

	struct tree *root1 = (struct tree *) malloc(sizeof(struct tree));
	struct tree *root2 = (struct tree *) malloc(sizeof(struct tree));
	struct tree *tmp;


	root1->value = 1;
	root2->value = 1;

	tmp = (struct tree *) malloc(sizeof(struct tree)); 
	tmp->value = 3;
	root1->left = tmp;

	tmp = (struct tree *) malloc(sizeof(struct tree)); 
	tmp->value = 2;
	root2->left = tmp;

	std::cout << compare(root1, root2) << std::endl;
	return 0;
}
