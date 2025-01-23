#include "common.h"
void find(char* a, struct Original_node* head, int input) {//在所有乘积项中寻找是否有对应的乘积项
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
		if (dd == 0) {//找到了之后删除
			//cout << "找到了"<<endl;
			struct Original_node* q = p->next;
			p->next = q->next;
			free(q);
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag == 0) {//说明没找到对应乘积项
		//cout << "yyy" << endl;
		struct Original_node* p1 = (struct Original_node*)malloc(sizeof(struct Original_node));
		initialization_Original_node(p1);
		for (int i = 1; i <= input; i++) {
			p1->str[i] = a[i];
		}
		if (p->next != NULL) {
			cout << "出错" << endl;
		}
		p->next = p1;//此时p就是最后一个节点
	}

}
void Original_find_left_individual(int count, struct Original_node* head, int input) {//0变1
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
			for (int i = 1; i <= input; i++) {//检测p是否是对应乘积项
				if (p->str[i] != a[i]) {
					dd = 1;
				}
			}
			if (dd == 0) {//如果p是对应乘积项，则将这个节点删除
				struct Original_node* q = head;
				while (q->next != p) {
					q = q->next;
				}
				struct Original_node* q1 = q->next;//就是p
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
void Original_find_right_individual(int count, struct Original_node* head, int input) {//1变0
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
			for (int i = 1; i <= input; i++) {//检测p是否是对应乘积项
				if (p->str[i] != a[i]) {
					dd = 1;
				}
			}
			if (dd == 0) {//如果p是对应乘积项，则将这个节点删除
				struct Original_node* q = head;
				while (q->next != p) {
					q = q->next;
				}
				struct Original_node* q1 = q->next;//就是p
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
void Original_find_change_individual(int count, struct Original_node* head, int input) {//取反
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
	/*cout << "将要转换的极性为：";
	for (int j = 1; j <= input; j++)//获得初始极性
	{
		cout << c[j];
	}
	cout << "\n";
	//将电路从布尔逻辑转变为RM逻辑*/
	for (int i = 1; i <= input; i++) {
		//cout << i << endl;
		if (c[i] == 2) {
			continue;
		}
		else if (c[i] == 0) {
			//cout << "前" << endl;
			//print_list(head);
			Original_find_left_individual(i, head, input);
			//cout << "后" << endl;
			//print_list(head);
		}
		else if (c[i] == 1) {
			Original_find_right_individual(i, head, input);
			Original_find_change_individual(i, head, input);
		}
	}

}