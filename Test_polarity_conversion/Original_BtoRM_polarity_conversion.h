#pragma once
#ifndef ORIGINAL_BTORM_POLARITY_CONVERSION_H
#define ORIGINAL_BTORM_POLARITY_CONVERSION_H
extern void Original_BtoRM_polarity_conversion(char p[], int input, struct Original_node* head);
extern void find(char* a, struct Original_node* head, int input);
extern void Original_find_left_individual(int count, struct Original_node* head, int input);
extern void Original_find_right_individual(int count, struct Original_node* head, int input);
extern void Original_find_change_individual(int count, struct Original_node* head, int input);
#endif