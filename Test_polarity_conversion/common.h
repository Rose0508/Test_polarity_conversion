#pragma once
#include <iostream>
#include <ctime>
#include<fstream>
#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include "New_initialization_tree_improve.h"
#include"New_BtoRM_polarity_conversion.h"
#include"New_RMtoRM_polarity_conversion.h"
#include "Original_initialization_tree_improve.h"
#include"Original_BtoRM_polarity_conversion.h"
#include"Original_RMtoRM_polarity_conversion.h"
#include"generate_initial_population.h"
//#include"calculate_area.h"
struct individual {
	long long number;
	char leftflag;
	char rightflag;
	struct individual* left;
	struct individual* right;
};
struct node {
	int number;
	//char sum;
	struct node* front;
	struct node* next;
};
struct Original_node {
	char str[50];//���ڴ�ų˻���
	struct Original_node* next;
};
struct Original_auxiliary_node {//�����ڵ�
	int number;//���ڴ�ų˻���
	struct Original_auxiliary_node* front;
	struct Original_auxiliary_node* next;
};
struct individual_node {//��Ⱥÿ������
	char str[50];//���漫��
	struct individual_node* next;
};
extern void print_list(struct node* head);
extern void clearList(struct node* head);
extern void put_polarity_helper(struct individual* head, int path[], int len);
extern void put_polarity(struct individual* head);
using namespace std;