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

ND* head = NULL;	//head�ʱⰪ

//��� ���� ����(���� ��¥ �� ����)
void insert_node(int _date, string _name) {
	ND* new_node = new ND;	//���ο� ��� ����
	
	new_node->o.import_date = _date;
	//new_node->o.book_name = new char[sizeof(_name)];
	new_node->o.book_name = _name;
	
	new_node->next = NULL;

	if (head == NULL) {		//����Ʈ�� ����� ��
		head = new_node;
	}
	else if(new_node->o.import_date < head->o.import_date) { //����Ʈ�� ���� �պ��� ��¥�� ���� ��¥�� ���� ��,
		new_node->next = head;
		head = new_node;
	}
	else { //���� ��¥�� �߰��� ��ġ �� ��,
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
// ��� ����
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
		cout << "����Ʈ�� ������ϴ�." << endl;
		return;
	}
	if (head->next == NULL)return; //���Ұ� 1�� �ۿ� ���� ��

	ND* curr = head; ND* prev = NULL; ND* temp;
	while (curr != NULL) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		if (curr == NULL)head = prev;
	}
}

//����Ʈ ���
void printf_list() {
	cout << "-------------------" << endl;
	if (head == NULL) cout << "������ϴ�." << endl;
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