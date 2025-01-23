#include "common.h"
void find(char* a, struct Original_node* head, int input) {//�����г˻�����Ѱ���Ƿ��ж�Ӧ�ĳ˻���
	int flag = 0;
	struct Original_node* p = head;
	while (p->next != NULL) {
		int dd = 0;
		for (int i = 1; i <= input; i++) {
			if (p->next->str[i] != a[i]) {
				//cout << "rrrr" << endl;
				dd = 1;
			}
		}
		if (dd == 0) {//�ҵ���֮��ɾ��
			//cout << "�ҵ���"<<endl;
			struct Original_node* q = p->next;
			p->next = q->next;
			free(q);
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag == 0) {//˵��û�ҵ���Ӧ�˻���
		//cout << "yyy" << endl;
		struct Original_node* p1 = (struct Original_node*)malloc(sizeof(struct Original_node));
		initialization_Original_node(p1);
		for (int i = 1; i <= input; i++) {
			p1->str[i] = a[i];
		}
		if (p->next != NULL) {
			cout << "����" << endl;
		}
		p->next = p1;//��ʱp�������һ���ڵ�
	}

}
void Original_find_left_individual(int count, struct Original_node* head, int input) {//0��1
	struct Original_node* p = head;
	char a[50];
	memset(a, -1, sizeof(a));
	while (p->next != NULL) {
		if (int(p->next->str[count]) == 0) {
			for (int k = 1; k <= input; k++) {
				a[k] = p->next->str[k];
			}
			a[count] = 1;
			int dd = 0;
			for (int i = 1; i <= input; i++) {//���p�Ƿ��Ƕ�Ӧ�˻���
				if (p->str[i] != a[i]) {
					dd = 1;
				}
			}
			if (dd == 0) {//���p�Ƕ�Ӧ�˻��������ڵ�ɾ��
				struct Original_node* q = head;
				while (q->next != p) {
					q = q->next;
				}
				struct Original_node* q1 = q->next;//����p
				q->next = q1->next;
				free(q1);
				p = q;
				p = p->next;
			}
			else {
				find(a, head, input);
				p = p->next;
			}
		}
		else {
			p = p->next;
		}
	}
}
void Original_find_right_individual(int count, struct Original_node* head, int input) {//1��0
	struct Original_node* p = head;
	char a[50];
	memset(a, -1, sizeof(a));
	while (p->next != NULL) {
		if (int(p->next->str[count]) == 1) {
			for (int k = 1; k <= input; k++) {
				a[k] = p->next->str[k];
			}
			a[count] = 0;
			int dd = 0;
			for (int i = 1; i <= input; i++) {//���p�Ƿ��Ƕ�Ӧ�˻���
				if (p->str[i] != a[i]) {
					dd = 1;
				}
			}
			if (dd == 0) {//���p�Ƕ�Ӧ�˻��������ڵ�ɾ��
				struct Original_node* q = head;
				while (q->next != p) {
					q = q->next;
				}
				struct Original_node* q1 = q->next;//����p
				q->next = q1->next;
				free(q1);
				p = q;
				p = p->next;
			}
			else {
				find(a, head, input);
				p = p->next;
			}
		}
		else {
			p = p->next;
		}
	}
}
void Original_find_change_individual(int count, struct Original_node* head, int input) {//ȡ��
	struct Original_node* p = head;
	while (p->next != NULL) {
		if (int(p->next->str[count]) == 0) {
			//cout << "k" << endl;
			p->next->str[count] = 1;
		}
		else if (int(p->next->str[count]) == 1) {
			p->next->str[count] = 0;
		}
		p = p->next;
	}
}
void Original_BtoRM_polarity_conversion(char p[],int input, struct Original_node* head) {
	int c[100];
	memset(c, -1, sizeof(c));
	for (int i = 1; i <= input; i++) {
		c[i] = int(p[i]);
	}
	/*cout << "��Ҫת���ļ���Ϊ��";
	for (int j = 1; j <= input; j++)//��ó�ʼ����
	{
		cout << c[j];
	}
	cout << "\n";
	//����·�Ӳ����߼�ת��ΪRM�߼�*/
	for (int i = 1; i <= input; i++) {
		//cout << i << endl;
		if (c[i] == 2) {
			continue;
		}
		else if (c[i] == 0) {
			//cout << "ǰ" << endl;
			//print_list(head);
			Original_find_left_individual(i, head, input);
			//cout << "��" << endl;
			//print_list(head);
		}
		else if (c[i] == 1) {
			Original_find_right_individual(i, head, input);
			Original_find_change_individual(i, head, input);
		}
	}

}