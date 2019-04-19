#include <iostream>
using namespace std;

struct node {
	struct student {
		int id;
		char grade;
	}d;
	struct node* next;
};
typedef struct node node;
node* head = NULL;
void print_node() {
	if (head == NULL) {
		cout << "값이 없습니다." << endl;
	}
	else {
		node* curr = head;
		while (curr != NULL) {
			cout << curr->d.id << " " << curr->d.grade << endl;
			curr = curr->next;
		}
	}
	/*node* curr = head;
	while (curr != NULL) {
	cout << curr->d.id << " " << curr->d.grade << endl;
	curr = curr->next;
	}*/
}

void insert_node(int _id, char _grade) {
	node* new_node = new node;
	new_node->d.id = _id;
	new_node->d.grade = _grade;
	new_node->next = NULL;

	node* curr = head;
	node** prev = &head;
	while (curr != NULL && curr->d.id < new_node->d.id) {
		prev = &(curr->next);
		//prev=curr;
		curr = curr->next;
	}
	*prev = new_node;
	//preb->next=new_node;
	new_node->next = curr;
}
/*if (head == NULL) {
head = new_node;
}
else if (head->d.id > new_node->d.id) {
new_node->next = head;
head = new_node;
}
else {
node* curr = head;
node* prev = NULL;
while (curr != NULL && curr->d.id < new_node->d.id) {
prev = curr;
curr = curr->next;
}
prev->next = new_node;
//(*prev).next = new_node;
new_node->next = curr;
}

}*/
void delete_node(int _id) {
	node* curr = head;
	node** prev = &head;
	while (curr != NULL) {
		if (curr->d.id == _id) {
			*prev = curr->next;
			delete curr;
			break;
		}
		prev = &(curr->next);
		curr = curr->next;
	}





	/*if (head == NULL) {
	cout << "값이 없습니다." << endl;
	}
	else {
	node* curr = head;
	node* prev = NULL;
	while (curr != NULL && curr->d.id == _id) {
	prev = curr;
	curr = curr->next;
	}
	if (curr == NULL) {
	cout << "값이 없습니다." << endl;
	}
	else {
	prev->next = curr->next;
	}
	}*/

	if (head != NULL) {
		node* curr = head;
		node* prev = NULL;
		if (curr->d.id == _id) {
			head = curr->next;
			delete curr;
		}
		else {
			while (curr != NULL) {
				if (curr->d.id == _id) {
					prev->next = curr->next;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
		}

	}

}
int main() {

	insert_node(201901, 'A');
	insert_node(201903, 'B');
	insert_node(201902, 'C');
	insert_node(201801, 'B'); //오류
	print_node();
	cout << endl;
	delete_node(201801);
	print_node();


	return 0;
}