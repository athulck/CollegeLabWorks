
#include <stdio.h>
#include <stdlib.h>


struct node {

	int value;
	char bal_indicator;
	struct node *LEFT;
	struct node *RIGHT;

};

/*
int left_rotate(node) {

}

int right_rotate(node) {

}

(struct node *) calculate_height(node) {

}
*/

void print2DUtil(struct node *root, int space) 
{ 
	int COUNT = 3;
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 

void display(struct node *root) { 

	printf("\n");
	if(root == NULL)
		return;
	
	printf("%d", root->value);
	display(root->LEFT);
	display(root->RIGHT);

	                                             root->value
	                 root->LEFT->value                                 root->RIGHT->value
	root->LEFT->LEFT->value  root->LEFT->RIGHT->value  root->RIGHT->LEFT->value  root->RIGHT->RIGHT->value
	printf("%s\n", );
}

void insert_node (struct node *root, struct node *new_node) {

	if (new_node->value < root->value) {
		if (root->LEFT == NULL)
			root->LEFT = new_node;
		else insert_node(root->LEFT, new_node); 
	} else {
		if(root->RIGHT == NULL)
			root->RIGHT = new_node;
		else insert_node(root->RIGHT, new_node);
	}
}


struct node* add_node (struct node *root, int value) {

	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->value = value;
	new_node->bal_indicator = 'B';
	new_node->LEFT = NULL;
	new_node->RIGHT = NULL;

	if (root == NULL) {
		return new_node;
	} else {
		insert_node(root, new_node);
	}
	return root;
}


void main () {

	struct node *AVL_Tree = NULL;

	AVL_Tree = add_node(AVL_Tree, 3);
	AVL_Tree = add_node(AVL_Tree, 5);
	AVL_Tree = add_node(AVL_Tree, 7);

	display(AVL_Tree);
}