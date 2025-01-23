#include "common.h"
void Original_RMtoRM_polarity_conversion(char p1[], char p2[], struct Original_node* head, int input) {//p1是当前极性，p2是目标极性
	int q1[50];
	int q2[50];
	for (int i = 1; i <= input; i++) {
		q1[i] = int(p1[i]);
		q2[i] = int(p2[i]);
	}
	for (int j = 1; j <= input; j++) {
		if ((q1[j] == 0 && q2[j] == 2) || (q1[j] == 2 && q2[j] == 0) || (q1[j] == 1 && q2[j] == 2)) {
			Original_find_left_individual(j, head, input);
		}
		else if ((q1[j] == 0 && q2[j] == 1) || (q1[j] == 1 && q2[j] == 0) || (q1[j] == 2 && q2[j] == 1)) {
			Original_find_right_individual(j, head, input);
		}
		if ((q1[j] == 1 && q2[j] == 2) || (q1[j] == 2 && q2[j] == 1)) {
			Original_find_change_individual(j, head, input);
		}
	}
}