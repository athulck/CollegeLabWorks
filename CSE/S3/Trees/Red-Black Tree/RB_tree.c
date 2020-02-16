// Implementation of Red-Black Tree in C 
#include <stdio.h>
#include <stdlib.h>


struct Node {

	int value;
	char color;
	struct Node *LEFT;
	struct Node *RIGHT;
	struct Node *PARENT;
};

struct Node *NULL_NODE;

int left_rotate(struct Node *root, struct Node *x) {

	struct Node *y = x->RIGHT;
	x->RIGHT = y->LEFT;

	if (y->LEFT != NULL_NODE)
		y->LEFT->PARENT = x;
	y->PARENT = x->PARENT;
	if (x->PARENT == NULL_NODE)
		root = y;
	else if (x == x->PARENT->LEFT)
		x->PARENT->LEFT = y;
	else x->PARENT->RIGHT = y;
	y->LEFT = x;
	x->PARENT = y;
}

int right_rotate(struct Node *root, struct Node *node) {

	// Rotating root node
	if (node == root) {
		node->LEFT->PARENT = node->PARENT;
		node->PARENT = node->LEFT;
		node->LEFT = node->LEFT->RIGHT;
		node->PARENT->RIGHT = node;
		root = node->PARENT;
	} else {

		if (node->PARENT != NULL) {
			if (node->PARENT->LEFT == node)
				node->PARENT->LEFT = node->LEFT;
			else 
				node->PARENT->RIGHT = node->LEFT;
		}
		node->LEFT->PARENT = node->PARENT;
		node->PARENT = node->LEFT;
		node->LEFT = node->LEFT->RIGHT;
		node->PARENT->RIGHT = node;
	}
}
/*
(struct node *) calculate_height(node) {

}
*/

void print2DUtil(struct Node *root, int space) 
{ 
	int COUNT = 4;
    // Base case 
    if (root == NULL_NODE) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->RIGHT, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d:%c\n", root->value, root->color); 
  
    // Process left child 
    print2DUtil(root->LEFT, space); 
} 

void display(struct Node *root) { 

	if ((root == NULL_NODE) || (root == NULL))
		return;

	printf("\n-----------------------------------------------------------------------------------");
	printf("\nNODE:");
	printf("\n=====");
	printf("\nValue : %d", root->value);
	if (root->PARENT != NULL) printf("\nParent : %d", root->PARENT->value);
	else printf("\nROOT NODE !");

	if (root->LEFT != NULL_NODE) printf("\nLeft child : %d", root->LEFT->value);
	if (root->RIGHT != NULL_NODE) printf("\nRight child : %d", root->RIGHT->value);

	display(root->LEFT);
	display(root->RIGHT);
}

void fixup_nodes (struct Node *root, struct Node *z) {

	
	while(z->PARENT->color == 'R') {

		if(z->PARENT == z->PARENT->PARENT->LEFT) {

			struct Node *UNCLE = z->PARENT->PARENT->RIGHT;

			if(UNCLE->color == 'R') {
				/* Case 1: Z, Z's parent & uncle is RED 
							B
						R  		R
					R
				*/
				z->PARENT->PARENT->color = 'R';
				z->PARENT->color = 'B';
				UNCLE->color = 'B';
				/*			R
						B  		B
					R
				*/
			} else {
				// Z's uncle is BLACK
				if (z == z->PARENT->RIGHT) {
					/* Case 2: Z and Z's parent is RED and Z is the right child and Z's uncle is BLACK
								B
						  <-R 		B
							   R
					*/
					z = z->PARENT;
					left_rotate(root, z);
					/*			B
							R 		B
						R
					*/
				}
				/* Case 3: Z and Z's parent is RED and Z is the left child and Z's uncle is BLACK
							B
						R 		B
					R
				*/
				z->PARENT->color = 'B';
				z->PARENT->PARENT->color = 'R';
				/*
							R->
						B 		B
					R
				*/
				right_rotate(root, z->PARENT->PARENT);
				/*
							B
						R 		R
									B
				*/
			}
		} else {
			// z->PARENT == z->PARENT->PARENT->RIGHT
			struct Node *UNCLE = z->PARENT->PARENT->LEFT;
			if(UNCLE->color == 'R') {
				/*
						B
					R 		R
								R
				*/	

				z->PARENT->PARENT->color = 'R';
				z->PARENT->color = 'B';
				UNCLE->color = 'B';
				/*
						R
					B 		B
								R
				*/	
			} else {

				if (z == z->PARENT->LEFT) {
					z = z->PARENT;
					right_rotate(root, z);
				}
				z->PARENT->color = 'B';
				z->PARENT->PARENT->color = 'R';
				left_rotate(root, z->PARENT->PARENT);
			}
		}
	}
	root->color = 'B';
}

void insert_node (struct Node *root, struct Node *new_node) {

	new_node->PARENT = root;

	if (new_node->value < root->value) {
		if (root->LEFT == NULL_NODE)
			root->LEFT = new_node;
		else insert_node(root->LEFT, new_node); 
	} else {
		if(root->RIGHT == NULL_NODE)
			root->RIGHT = new_node;
		else insert_node(root->RIGHT, new_node);
	}
}


struct Node* add_node (struct Node *root, int value) {

	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->color = 'R';
	new_node->LEFT = NULL_NODE;
	new_node->RIGHT = NULL_NODE;
	new_node->PARENT = NULL;
	new_node->value = value;

	//if root node ?
	if (root == NULL) {
		new_node->color = 'B';
		return new_node;
	} else {
		insert_node(root, new_node);
		fixup_nodes(root, new_node);
	}
	return root;
}



void main () {

	struct Node *RB_Tree = NULL;
	int array[] = {3,7,10,12,14,15,16,17,21,19,20,23,26,41,28,30,47,38,35,39};
	int len = sizeof(array)/sizeof(int);

	// creating the leaf null node
	NULL_NODE = (struct Node *)malloc(sizeof(struct Node));
	NULL_NODE->color  = 'B';
	NULL_NODE->LEFT   = NULL;
	NULL_NODE->RIGHT  = NULL;
	NULL_NODE->PARENT = NULL;
	NULL_NODE->value  = 0;

	for (int i=0; i<len; i++) {
		RB_Tree = add_node(RB_Tree, array[i]);
		
	}
	print2DUtil(RB_Tree, 4);
	printf("\n--------------------------------------------------------\n");
	display(RB_Tree);
	
}