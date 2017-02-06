#include <stdlib.h>
#include <stdio.h>
struct node{
	int data;
	struct node *head;
	struct node *tail;
};
typedef struct node *doublyLinked;

void print(doublyLinked ptr){
	if(ptr){
		print(ptr->head);
		printf("%3d",ptr->data);
		print(ptr->tail);
	}
}
void sort(doublyLinked* list, doublyLinked node){ 
	if(*list == NULL)
		*list = node;
	else if(node->data > (*list)->data)
		sort(&((*list)->tail), node);
	else
		sort(&((*list)->head), node);
}
void sorting(doublyLinked list, doublyLinked* temp){
	doublyLinked node = (doublyLinked)malloc(sizeof(*node));
	node->data = list->data;
	node->head = NULL;
	node->tail = NULL;
	sort(temp, node);
	if(list->tail)
		sorting(list->tail, temp);
}
int main(){
	doublyLinked A = (doublyLinked)malloc(sizeof(*A));
	doublyLinked B = (doublyLinked)malloc(sizeof(*B));
	doublyLinked C = (doublyLinked)malloc(sizeof(*C));
	doublyLinked D = (doublyLinked)malloc(sizeof(*D));
	A->data = 3;
	A->head = NULL;
	A->tail = B;
	B->data = 1;
	B->head = A;
	B->tail = C;
	C->data = 4;
	C->head = B;
	C->tail = D;
	D->data = 5;
	D->head = C;
	D->tail = NULL;
	doublyLinked list = A;
	list->head = NULL;
	printf("排序前");
	printf("%3d%3d%3d%3d\n", list->data, (list->tail)->data, ((list->tail)->tail)->data, (((list->tail)->tail)->tail)->data);

	doublyLinked temp = NULL;
	sorting(list, &temp);
	list = temp;
	printf("排序後");
	print(list);
	printf("\n");

	system("pause");
}
