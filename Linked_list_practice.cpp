#include <iostream>
#include <string>
using namespace std;

struct node {
	struct book {
		int import_date;
		string book_name;
	}o;
	struct node *next;
};
typedef struct node ND;

ND* head = NULL;	//head초기값

//노드 삽입 구현(반입 날짜 순 정렬)
void insert_node(int _date, string _name) {
	ND* new_node = new ND;	//새로운 노드 생성
	
	new_node->o.import_date = _date;
	//new_node->o.book_name = new char[sizeof(_name)];
	new_node->o.book_name = _name;
	
	new_node->next = NULL;

	if (head == NULL) {		//리스트가 비었을 때
		head = new_node;
	}
	else if(new_node->o.import_date < head->o.import_date) { //리스트의 제일 앞보다 날짜가 반입 날짜가 빠를 때,
		new_node->next = head;
		head = new_node;
	}
	else { //반입 날짜가 중간에 위치 할 때,
		ND* curr = head;
		ND* prev = NULL;
		while (curr != NULL && curr->o.import_date < new_node->o.import_date) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = new_node;
		new_node->next = curr;
	}
}
// 노드 삭제
void delete_node(string _name) {
	ND* curr = head;
	ND* prev = NULL;
	if (curr != NULL) {
		while (1) {
			if (curr->o.book_name == _name) {
				prev->next = curr->next;
				break;
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
}

void reverse_list() {
	if (head == NULL) {
		cout << "리스트가 비었습니다." << endl;
		return;
	}
	if (head->next == NULL)return; //원소가 1개 밖에 없을 때

	ND* curr = head; ND* prev = NULL; ND* temp;
	while (curr != NULL) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		if (curr == NULL)head = prev;
	}
}

//리스트 출력
void printf_list() {
	cout << "-------------------" << endl;
	if (head == NULL) cout << "비었습니다." << endl;
	else {
		ND* curr = head;
		while (curr != NULL) {
			cout << curr->o.import_date << ' ' << curr->o.book_name << endl;
			curr = curr->next;
		}
	}
	cout << "-------------------" << endl;
}


int main() {
	string in;
	int num;
	for (int i = 0; i < 5; i++) {
		cin >> num >> in;
		insert_node(num, in);
	}
	printf_list();
	delete_node("king");
	printf_list();
	delete_node("gugu");
	printf_list();
	reverse_list();
	printf_list();
}