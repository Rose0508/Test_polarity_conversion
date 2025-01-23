#pragma once
#ifndef NEW_BTORM_POLARITY_CONVERSION_H
#define NEW_BTORM_POLARITY_CONVERSION_H
extern void New_BtoRM_polarity_conversion(char p[], int input, struct node* head);
extern void find_left_individual(int i, long long front, long long tail, long long sum, struct node* head);
extern void find_right_individual(int i, long long  front, long long tail, long long sum, struct node* head);
extern void find_change_individual(int i, long long  front, long long tail, long long sum, struct node* head);
#endif