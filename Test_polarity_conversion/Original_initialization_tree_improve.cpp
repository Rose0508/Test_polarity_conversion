#include "common.h"
void initialization_Original_node(struct Original_node* p) {//初始化乘积项节点
	memset(p->str, -1, sizeof(p->str));
	p->next = NULL;
}
void initialization_Original_auxiliary_node(struct Original_auxiliary_node* p) {//初始化辅助节点
	p->number = -1;
	p->front = NULL;
	p->next = NULL;
}
void free_Original_auxiliary_node_List(struct Original_auxiliary_node* head) {
	struct Original_auxiliary_node* current = head;
	struct Original_auxiliary_node* nextNode;

	while (current != NULL) {
		nextNode = current->next;// Save the next node
		free(current);            // Free the current node
		current = nextNode;       // Move to the next node
	}
}
void Original_initialization_tree_improve(char** a, struct Original_node* head0, int input, int count) {
	struct Original_auxiliary_node* head = (struct Original_auxiliary_node*)malloc(sizeof(struct Original_auxiliary_node));
	initialization_Original_auxiliary_node(head);
	struct Original_auxiliary_node* p = head;
	queue<long long>que;
	for (int i = 0; i < count; i++) {
		//cout << i << endl;
		if (!que.empty()) {
			cout << "队列非空" << endl;
		}
		long long k = 1;
		if (a[i][0] == '0') {
			que.push(k * 2);
		}
		else if (a[i][0] == '1') {
			que.push(k * 2 + 1);
		}
		else if (a[i][0] == '-') {
			que.push(k * 2);
			que.push(k * 2 + 1);
		}
		for (int j = 1; j < input; j++) {
			//cout << j << endl;
			int m = 1;
			int sum = que.size();
			while (m <= sum) {
				long long n = que.front();
				if (a[i][j] == '0') {
					que.push(n * 2);
				}
				else if (a[i][j] == '1') {
					que.push(n * 2 + 1);
				}
				else if (a[i][j] == '-') {
					que.push(n * 2);
					que.push(n * 2 + 1);
				}
				que.pop();
				m++;
			}
		}
		p = head;
		while (!que.empty()) {
			long long n1 = que.front();
			long long n = n1;
			int flag = 0;
			while (p->next != NULL) {
				if (p->next->number == n) {
					flag = 1;
					p = p->next;//保证p->next为一个新的值
					break;
				}
				else if (p->next->number > n) {
					struct Original_auxiliary_node* p3 = (struct Original_auxiliary_node*)malloc(sizeof(struct Original_auxiliary_node));
					p3->front = p;
					p3->next = p->next;
					p3->number = n;
					p->next->front = p3;
					p->next = p3;
					flag = 1;
					p = p->next;//保证p->next为一个新的值
					break;
				}
				p = p->next;
			}
			if (flag == 0) {
				struct Original_auxiliary_node* p3 = (struct Original_auxiliary_node*)malloc(sizeof(struct Original_auxiliary_node));
				p3->front = p;
				p3->next = NULL;
				p3->number = n;
				p->next = p3;
				p = p->next;
			}
			que.pop();
		}
	}
	p = head;
	struct Original_node* q = head0;
	while (p->next != NULL) {
		int sum = p->next->number;
		struct Original_node* q1 = (struct Original_node*)malloc(sizeof(struct Original_node));
		initialization_Original_node(q1);
		int k = input;
		while (sum != 1) {
			if (sum % 2 == 0) {
				sum = sum / 2;
				q1->str[k] = 0;
			}
			else {
				sum = (sum - 1) / 2;
				q1->str[k] = 1;
			}
			k--;
		}
		q->next = q1;
		q = q->next;
		p = p->next;
	}
	free_Original_auxiliary_node_List(head);
	cout << "已填充完成" << endl;
}