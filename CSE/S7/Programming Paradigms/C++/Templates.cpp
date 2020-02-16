/**/


#include <iostream>


template <class item, int max_items = 100>

class queue {

	item items[max_items];
	int next_free;
	int next_full;

	public:
	queue() {
		next_free = next_full = 0;
		// initialization
	}

	void print_queue() {

		std::cout<<'\n';
		for(int i=next_full; i<next_free; i++) {
			std::cout<<items[i]<<" ";
		}
	}
	
	void enqueue(item it) {
		items[next_free] = it;
		next_free = (next_free + 1) % max_items;
	}
	
	item dequeue() {
		item rtn = items[next_full];
		next_full = (next_full + 1) % max_items;
		return rtn;
	}
};


template <class item>

class Stack {


	struct Node {

		item value;
		struct Node *next;
	} *base;

	public:

		Stack() {
			base = NULL;
		}

		void push(item element) {

			struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
			new_node->value = element;
			new_node->next  = NULL;

			if (base == NULL)
				base = new_node;
			else {

				struct Node *temp = base;
				for (; temp->next != NULL; temp = temp->next);
				temp-> next = new_node;
			}

		}

		item pop() {

			if (base == NULL) {
				return NULL;
			} else {

				struct Node *temp = base;
				for (; (temp->next != NULL && temp->next->next == NULL); temp = temp->next);

				item rtn;
				if (temp == base) {
					rtn = base->value;
					free(base);
					base = NULL;
				} else {
					rtn = base->next->value;
					free(base->next);
					base->next = NULL;
				}
				return rtn;
			}

		}
};


void print(char *format) {

	std::cout<<format;

}

int main() {


	queue<int, 50> int_queue;

	int_queue.enqueue(10);
	int_queue.enqueue(20);
	int_queue.enqueue(30);
	int_queue.print_queue();
	std::cout<<int_queue.dequeue()<<"\n";
	std::cout<<int_queue.dequeue()<<"\n";
	std::cout<<int_queue.dequeue()<<"\n";
	int_queue.print_queue();

	Stack<int> stack;

	stack.push(100);
	stack.push(200);
	stack.push(300);

	std::cout<< stack.pop() <<"\n";
	std::cout<< stack.pop() <<"\n";
	std::cout<< stack.pop() <<"\n";


}
