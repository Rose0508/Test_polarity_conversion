#include"common.h"
void initialization_individual_node(struct individual_node* p) {
	memset(p->str, -1, sizeof(p->str));
	p->next = NULL;
}
void put_popsize(struct individual_node* head, int input) {
	struct individual_node* p = head;
	while (p->next != NULL) {
		for (int i = 1; i <= input; i++) {
			cout << int(p->next->str[i]);
		}
		cout << "\n";
		p = p->next;
	}
}
struct individual_node* generate_initial_population(int input, int popsize) {
	double a = 1.0 / 3.0;
	double b = 2.0 / 3.0;
	double f;
	srand((unsigned)time(NULL) + ((unsigned)rand()));
	struct individual_node* head = (struct individual_node*)malloc(sizeof(struct individual_node));//哨兵节点
	initialization_individual_node(head);
	struct individual_node* p = head;
	for (int i = 1; i <= popsize; i++) {
		struct individual_node* p1 = (struct individual_node*)malloc(sizeof(struct individual_node));
		initialization_individual_node(p1);
		p->next = p1;
		for (int j = 1; j <= input; j++) {
			f = rand() / (RAND_MAX + 1.0);//轮盘赌方式获取初始种群
			if (f < a) {
				p1->str[j] = 0;
			}
			else if (f > b) {
				p1->str[j] = 2;
			}
			else {
				p1->str[j] = 1;
			}

		}
		p = p->next;
	}
	//put_popsize(head, input);
	return head;
}