/*Queue implementation*/

#include<stdio.h>
#define Q_SIZE 5

void insert();
void delete();
void display();

int front = -1;
int rear = -1;
int queue[Q_SIZE];

int main() {
	int choice;

	do {
		printf("\n> Enter a Queue operation :");
		printf("\ninsert : press 1");
		printf("\ndelete : press 2");
		printf("\ndisplay : press 3\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1 : insert(); break;
			case 2 : delete(); break;
			case 3 : display(); break;
			default : printf("\nWrong input");
		}
		printf("\nDo you want to continue? 1 : yes, 0 : no > ");
		scanf("%d", &choice);
	} while(choice == 1);
	return 0;
}

void insert() {
	int new_item;
	if(rear == Q_SIZE - 1) {
		printf("\nQueue Overflow");
	}
	
	printf("\nEnter a integer : ");
	scanf("%d", &new_item);

	if(rear == -1) {
		++front;
	}
	queue[++rear] = new_item;
	printf("\nItem inserted");
}

void delete() {
	if(front == -1) {
		printf("\nQueue Underflow");
	}
	else {
		printf("\nDeleted item : %d", queue[front]);
		if(rear == front) {
			rear = -1;
			front = -1;
		}
		else {
			++front;
		}
	}
}

void display() {
	int index = front;
	if(index == -1) {
		printf("\nQueue is already empty");
	}
	else {
		printf("\nQueue contains : ");
		while(index <= rear) {
			printf("\t%d", queue[index++]);
		}
	}
}
