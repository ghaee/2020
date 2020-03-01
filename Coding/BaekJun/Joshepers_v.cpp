#include <iostream>

using namespace std;
typedef struct list_node *list_ptr;
typedef struct list_node{
	int data;
	list_ptr next;
}node;

int main(){
	int n, key;
	cin >> n >> key;
	node* head = new sizeof(node);
	head->next = NULL;
}