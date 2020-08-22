/*Implementation of circular queue*/

#include<stdio.h>

#define CIR_Q_SIZE 5

void insert();
void delete();
void display();

int front = -1;
int rear = -1;
int cir_queue[CIR_Q_SIZE];

int main() {
	int user_input;
	
	do {
		printf("\nFollow the Queue operations below :");
		printf("\nPress 1 : insert, 2 : delete, 3 : display");
		scanf("%d", &user_input);

		switch(user_input) {
			case 1 : insert(); break;
			case 2 : delete(); break;
			case 3 : display(); break;
			default : printf("\n Wrong Input");
		}
		printf("\nDo you want to continue? Press 1 : Yes, 2 : No");
		scanf("%d", &user_input);
	} while(user_input == 1);
	
	return 0;
}

void insert() {
	int new_item;
	if(( (rear + 1) % CIR_Q_SIZE) == front) {
		printf("\nQueue Overflow");
	}
	else {
		printf("\nEnter a integer : ");
		scanf("%d", &new_item);
		if(front == -1) {
			++front;
		}
		rear = (++rear % CIR_Q_SIZE);
		cir_queue[rear] = new_item;
		printf("\ninserted successfully");
	}
}

void delete() {
	if(front == -1) {
		printf("\nQueue Underflow");
	}
	else {
		printf("\nDeleted item : %d", cir_queue[front]);
		if(front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			front = (++front % CIR_Q_SIZE);
		}

	}
}

void display() {
	if(front == -1) {
		printf("\nQueue is Empty");
	}
	else {
		int index;
		index = front;
		printf("\nQueue Contains : ");
		while(index != rear) {
			printf("%d\t", cir_queue[index]);
			index = ++index % CIR_Q_SIZE;
		}
		printf("%d", cir_queue[index]);
	}
}
