#include "common.h"
void New_RMtoRM_polarity_conversion(char p1[], char p2[], struct node* head, int input) {//p1是当前极性，p2是目标极性
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
		//cout << "前" << endl;
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
				//cout << "执行change前" << endl;
				//print_list(head);
				find_change_individual(j, front, tail, sum, head);
				//cout << "执行change后" << endl;
				//print_list(head);
			}
		}
		else {
			if ((q1[j] == 0 && q2[j] == 2) || (q1[j] == 2 && q2[j] == 0) || (q1[j] == 1 && q2[j] == 2)) {
				struct node* p = head;
				while (p != NULL && p->next != NULL) {
					if ((p->next->number) % 2 == 0) {//找到了满足条件需要取反的结点
						if (p->next->next != NULL) {
							if (p->next->next->number == (p->next->number) + 1) {//说明转换后有重复结点需要删除
								struct node* p1 = p->next->next;
								p->next->next = p1->next;
								if (p1->next != NULL) {
									p1->next->front = p->next;
								}
								free(p1);
								p = p->next;//保证p->next为新结点
							}
							else {//说明转换后无重复结点,需要添加结点
								struct node* p1 = p->next->next;
								struct node* p2 = (struct node*)malloc(sizeof(struct node));
								p2->number = (p->next->number) + 1;
								p2->next = NULL;
								p2->next = p1;
								p1->front = p2;
								p->next->next = p2;
								p2->front = p->next;
								p = p->next->next;//保证p->next为新结点
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
							if (p->number == (p->next->number) - 1) {//证明转换后有重复结点 需删除p
								//cout << p->next->number << "删除了" << p->number << endl;
								struct node* p1 = p;
								p = p->front;
								p1->next->front = p;
								p->next = p1->next;//p->next为新结点
								p = p->next;
								free(p1);
							}
							else {//说明转换后无重复结点，需要添加
								struct node* p1 = (struct node*)malloc(sizeof(struct node));
								p1->number = p->next->number - 1;
								//cout << p->next->number << "添加了" << p1->number << endl;
								p->next->front = p1;
								p1->next = p->next;
								p->next = p1;
								p1->front = p;
								p = p->next->next;//保证p->next为新结点
							}
						}
						else {
							struct node* p1 = (struct node*)malloc(sizeof(struct node));
							p1->number = p->next->number - 1;
							//cout << p->next->number << "添加了" << p1->number << endl;
							p->next->front = p1;
							p1->next = p->next;
							p->next = p1;
							p1->front = p;
							p = p->next->next;//保证p->next为新结点
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
							if (p->next->next->number == p->next->number + 1) {//代表取反后有重复结点，无需操作
								p = p->next->next;//保证p->next是一个新结点
							}
							else {//如果没有则需要添加结点，并删除此结点;
								p->next->number = p->next->number + 1;
								p = p->next;//保证p->next是一个新结点,并且不需要标记
							}
						}
						else {
							p->next->number = p->next->number + 1;
							p = p->next;//保证p->next是一个新结点,并且不需要标记
						}
					}
					else {
						if (p != head) {
							if (p->number == p->next->number - 1) {//代表取反后有重复结点，无需操作
								p = p->next;//保证p->next是一个新结点
							}
							else {//如果没有则需要添加结点，并删除此结点;
								p->next->number = p->next->number - 1;
								p = p->next;//保证p->next是一个新结点,并且不需要标记
							}
						}
						else {//需要添加结点，并删除此结点
							p->next->number = p->next->number - 1;
							p = p->next;//保证p->next是一个新结点,并且不需要标记
						}
					}
				}
			}

		}
		//cout << "后" << endl;
		//print_list(head);
	}
}