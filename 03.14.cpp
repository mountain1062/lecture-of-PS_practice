/*03.14 연결리스트 구현*/
#include <iostream>
using namespace std;

struct node {
	struct student { 
	int id; char grade; 
	}d;
	struct node* next;
};
typedef struct node node;

node* head = NULL;

void print_node() {
	
	node* curr = head;
	while (curr != NULL) {
		cout << curr->d.id << " " << curr->d.grade << endl;
		curr = curr->next;
	}
}
void insert_node(int _id, char _grade) {
	//node new_node = {_id, _grade,NULL}; // 이렇게 생성하면 insert함수 안에서 정적으로 생성되어 함수 탈출시 사라진다 (stack에 생성)
	node* new_node = new node;
	new_node->d.id = _id;
	new_node->d.grade = _grade;
	new_node->next = NULL;
	if (head == NULL) {
		head = new_node;
	}
	else if (new_node->d.id < head->d.id) {
		new_node->next = head;
		head = new_node;
	}
	else {
		//삽입시 학번 순서를 따져야함
		node* curr = head;
		node* prev = NULL;

		while (curr != NULL && curr->d.id < new_node->d.id) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = new_node;
		//(*prev).next = new_node; //37번 라인과 동일
		new_node->next = curr;
	}
}
void delete_node(int _id) {
	if (head != NULL) {
		node* curr = head;
		node* prev = NULL;
		if (curr->d.id == _id) {
			head = curr->next;
			delete curr;
		}
		else {
			while (curr != NULL) {//curr == NULL -> 없는 값
				if (curr->d.id == _id) {
					//삭제
					prev->next = curr->next;
					delete curr;
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
	insert_node(201801, 'D');
	print_node();
	delete_node(201902);
	print_node();
}