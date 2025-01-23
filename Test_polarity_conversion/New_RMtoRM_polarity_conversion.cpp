#include "common.h"
void New_RMtoRM_polarity_conversion(char p1[], char p2[], struct node* head, int input) {//p1�ǵ�ǰ���ԣ�p2��Ŀ�꼫��
	int q1[50];
	int q2[50];
	for (int i = 1; i <= input; i++) {
		q1[i] = int(p1[i]);
		q2[i] = int(p2[i]);
	}
	long long front = pow(2, input);
	long long tail = pow(2, input + 1) - 1;
	for (int j = 1; j <= input; j++) {
		//cout << j << endl;
		//cout << "ǰ" << endl;
		//print_list(head);
		if (j < input) {
			int n = input - j;
			long long sum = pow(2, n);
			if ((q1[j] == 0 && q2[j] == 2) || (q1[j] == 2 && q2[j] == 0) || (q1[j] == 1 && q2[j] == 2)) {
				find_left_individual(j, front, tail, sum, head);
			}
			else if ((q1[j] == 0 && q2[j] == 1) || (q1[j] == 1 && q2[j] == 0) || (q1[j] == 2 && q2[j] == 1)) {
				find_right_individual(j, front, tail, sum, head);
			}
			if ((q1[j] == 1 && q2[j] == 2) || (q1[j] == 2 && q2[j] == 1)) {
				//cout << "ִ��changeǰ" << endl;
				//print_list(head);
				find_change_individual(j, front, tail, sum, head);
				//cout << "ִ��change��" << endl;
				//print_list(head);
			}
		}
		else {
			if ((q1[j] == 0 && q2[j] == 2) || (q1[j] == 2 && q2[j] == 0) || (q1[j] == 1 && q2[j] == 2)) {
				struct node* p = head;
				while (p != NULL && p->next != NULL) {
					if ((p->next->number) % 2 == 0) {//�ҵ�������������Ҫȡ���Ľ��
						if (p->next->next != NULL) {
							if (p->next->next->number == (p->next->number) + 1) {//˵��ת�������ظ������Ҫɾ��
								struct node* p1 = p->next->next;
								p->next->next = p1->next;
								if (p1->next != NULL) {
									p1->next->front = p->next;
								}
								free(p1);
								p = p->next;//��֤p->nextΪ�½��
							}
							else {//˵��ת�������ظ����,��Ҫ��ӽ��
								struct node* p1 = p->next->next;
								struct node* p2 = (struct node*)malloc(sizeof(struct node));
								p2->number = (p->next->number) + 1;
								p2->next = NULL;
								p2->next = p1;
								p1->front = p2;
								p->next->next = p2;
								p2->front = p->next;
								p = p->next->next;//��֤p->nextΪ�½��
							}
						}
						else {
							struct node* p3 = (struct node*)malloc(sizeof(struct node));
							p3->number = (p->next->number) + 1;
							p3->next = NULL;
							p->next->next = p3;
							p3->front = p->next;
							p = p->next->next;
						}
					}
					else {
						p = p->next;
					}
				}
			}
			else if ((q1[j] == 0 && q2[j] == 1) || (q1[j] == 1 && q2[j] == 0) || (q1[j] == 2 && q2[j] == 1)) {
				struct node* p = head;
				while (p != NULL && p->next != NULL) {
					//cout << p->next->number << endl;
					if ((p->next->number) % 2 != 0) {
						if (p != head) {
							if (p->number == (p->next->number) - 1) {//֤��ת�������ظ���� ��ɾ��p
								//cout << p->next->number << "ɾ����" << p->number << endl;
								struct node* p1 = p;
								p = p->front;
								p1->next->front = p;
								p->next = p1->next;//p->nextΪ�½��
								p = p->next;
								free(p1);
							}
							else {//˵��ת�������ظ���㣬��Ҫ���
								struct node* p1 = (struct node*)malloc(sizeof(struct node));
								p1->number = p->next->number - 1;
								//cout << p->next->number << "�����" << p1->number << endl;
								p->next->front = p1;
								p1->next = p->next;
								p->next = p1;
								p1->front = p;
								p = p->next->next;//��֤p->nextΪ�½��
							}
						}
						else {
							struct node* p1 = (struct node*)malloc(sizeof(struct node));
							p1->number = p->next->number - 1;
							//cout << p->next->number << "�����" << p1->number << endl;
							p->next->front = p1;
							p1->next = p->next;
							p->next = p1;
							p1->front = p;
							p = p->next->next;//��֤p->nextΪ�½��
						}
					}
					else {
						p = p->next;
					}
				}
			}
			if ((q1[j] == 1 && q2[j] == 2) || (q1[j] == 2 && q2[j] == 1)) {
				struct node* p = head;
				while (p != NULL && p->next != NULL) {
					if ((p->next->number) % 2 == 0) {
						if (p->next->next != NULL) {
							if (p->next->next->number == p->next->number + 1) {//����ȡ�������ظ���㣬�������
								p = p->next->next;//��֤p->next��һ���½��
							}
							else {//���û������Ҫ��ӽ�㣬��ɾ���˽��;
								p->next->number = p->next->number + 1;
								p = p->next;//��֤p->next��һ���½��,���Ҳ���Ҫ���
							}
						}
						else {
							p->next->number = p->next->number + 1;
							p = p->next;//��֤p->next��һ���½��,���Ҳ���Ҫ���
						}
					}
					else {
						if (p != head) {
							if (p->number == p->next->number - 1) {//����ȡ�������ظ���㣬�������
								p = p->next;//��֤p->next��һ���½��
							}
							else {//���û������Ҫ��ӽ�㣬��ɾ���˽��;
								p->next->number = p->next->number - 1;
								p = p->next;//��֤p->next��һ���½��,���Ҳ���Ҫ���
							}
						}
						else {//��Ҫ��ӽ�㣬��ɾ���˽��
							p->next->number = p->next->number - 1;
							p = p->next;//��֤p->next��һ���½��,���Ҳ���Ҫ���
						}
					}
				}
			}

		}
		//cout << "��" << endl;
		//print_list(head);
	}
}