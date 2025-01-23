#include"common.h"
int input = 0, output = 0;
long long num = 0;
int summ = 0;
char** a;
int rows = 1000;
int cols = 50;
void put_polarity_helper(struct individual* head, int path[], int len) {
	if (!head) {
		return;
	}
	if (head->number % 2 == 0) {
		path[len] = 0;
		len++;
	}
	else {
		path[len] = 1;
		len++;
	}
	if (head->leftflag == 0 && head->rightflag == 0) {
		// ��ӡ·��
		//cout << len << endl;
		for (int i = 0; i < len; i++) {
			printf("%d", path[i]);
		}
		summ++;
		printf("\n");
	}
	else {
		put_polarity_helper(head->left, path, len);
		//cout << "kkk" << len << endl;
		put_polarity_helper(head->right, path, len);
	}
}
void put_polarity(struct individual* head) {
	int path[1000];
	put_polarity_helper(head, path, 0);
}
// ð��������
void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 1; i <= n - 1; i++) {                  // �޸�ѭ����ʼ����
		// ��� i ��Ԫ���Ѿ��������
		for (j = 1; j <= n - i; j++) {              // �޸�ѭ����ʼ����
			// ���ǰһ��Ԫ�ش��ں�һ��Ԫ�أ��򽻻�����
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void free_individual_node(struct individual_node* head) {
	struct individual_node* p = head;
	struct individual_node* p1;
	while (p != NULL) {
		p1 = p->next;
		free(p);
		p = p1;
	}
}
// ��ӡ���麯��
void printArray(int arr[], int size) {
	int i;
	for (i = 1; i <= size; i++) {                 // �޸�ѭ����ʼ����
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void print_list1(struct Original_node* head) {
	//cout << "wwww" << endl;
	int a[10000];
	struct Original_node* p = head->next;
	int sum = 1;
	int count = 1;
	while (p != NULL) {
		sum = 1;
		for (int i = 1; i <= input; i++) {
			if (int(p->str[i]) == 0) {
				sum = sum * 2;
			}
			if (int(p->str[i]) == 1) {
				sum = sum * 2 + 1;
			}
			//cout << int(p->str[i]);
		}
		//cout << "\n";
		//cout << sum << " ";
		a[count] = sum;
		count++;
		summ++;
		p = p->next;
	}
	bubbleSort(a, count-1);
	printArray(a, count-1);
}
void print_list(struct node* head) {
	struct node* p = head->next;
	while (p != NULL) {
		cout << int(p->number) << " ";
		p = p->next;
	}
}
void count_Original_nodes(struct Original_node* head) {
	struct Original_node* p = head->next;
	int sum1 = 0;
	while (p != NULL) {
		sum1++;
		p = p->next;
	}
	cout << "����" << sum1 << "��" << endl;
}
void count_New_nodes(struct node* head) {
	struct node* p = head->next;
	int sum2 = 0;
	while (p != NULL) {
		sum2++;
		p = p->next;
	}
	cout << "����" << sum2 << "��" << endl;
}
void clear_Original_node_List(struct Original_node* head) {
	struct Original_node* current = head;
	struct Original_node* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;
}
void clear_New_node_List(struct node* head) {
	struct node* current = head;
	struct node* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;
}
struct Original_node* copy_Original_node(struct Original_node* Original_head, int input) {
	//����
	struct Original_node* head0 = (struct Original_node*)malloc(sizeof(struct Original_node));
	initialization_Original_node(head0);
	struct Original_node* p2 = head0;
	//ԭ��
	struct Original_node* p1 = Original_head->next;
	while (p1 != NULL) {
		struct Original_node* p3 = (struct Original_node*)malloc(sizeof(struct Original_node));
		initialization_Original_node(p3);
		for (int i = 1; i <= input; i++) {
			p3->str[i] = p1->str[i];
		}
		p2->next = p3;
		p2 = p2->next;
		p1 = p1->next;
	}
	return head0;
}
int main() {
	a = (char**)malloc(rows * sizeof(char*));
	for (int i = 0; i < rows; i++) {
		a[i] = (char*)malloc(cols * sizeof(char));
	}
	int iLineIndex = 0;
	const int MAX_LINE_LEN = 512;
	static char szLineData[MAX_LINE_LEN];
	int count = 0;
	ifstream infile;
	infile.open("D:\\Circuit\\clip.txt");
	if (!infile) {
		cout << "error" << endl;
		return 0;
	}
	while (!infile.eof())
	{
		infile.getline(szLineData, MAX_LINE_LEN);
		++iLineIndex;
		if (iLineIndex == 1) {
			int i = 3;
			while (szLineData[i] != '\0') {
				//cout << "lllll" << endl;
				input = input * 10;
				input = input + int(szLineData[i]) - 48;
				i++;
			}
		}
		else if (iLineIndex == 2) {
			int i = 3;
			while (szLineData[i] != '\0') {
				//cout << "22222" << endl;
				output = output * 10;
				output = output + int(szLineData[i]) - 48;
				i++;
			}

		}
		else if (iLineIndex == 5) {
			int i = 3;
			while (szLineData[i] != '\0') {
				//cout << "55555" << endl;
				num = num * 10;
				//cout << int(szLineData[i]) - 48 << endl;
				num = num + int(szLineData[i]) - 48;
				//cout <<num<< endl;
				i++;
			}
			num = num + 5;
		}
		else if (iLineIndex > 5 && iLineIndex < num + 1) {
			//cout << szLineData[input + 1] << endl;
			if (int(szLineData[input + 1]) - 48 == 1) {
				for (int j = 0; j < input; j++) {
					a[count][j] = szLineData[j];
				}
				count++;
			}
		}
		cout << szLineData << endl;

	}
	infile.close();
	cout << "�ļ��Ѿ�����" << endl;
	cout << "input��ֵΪ��" << input << endl;
	cout << "output��ֵΪ��" << output << endl;
	cout << "������Ϊ��" << num - 5 << endl;
	cout << "���˺�Ϊ��" << count << endl;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < input; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
	int popsize;
	int	G;
	cout << "׼����ʼ�Ա���������ת���㷨" << endl;
	cout << "��������Ⱥ��С��";
	//cin >> popsize;
	popsize = 1000;
	cout << "��Ⱥ��ģ:" << popsize << endl;
	cout << "����ʵ����Ⱥ" << endl;
	struct individual_node* head0 = generate_initial_population(input, popsize);
	cout << "��ǰ��Ⱥ�����" << endl;
	//put_popsize(head0, input);
	//ԭʼ�㷨�Ե�·������չ
	for (int r = 1; r <= 10; r++) {
		cout << "��" << r << "��ʵ��" << endl;
		struct Original_node* Original_head = (struct Original_node*)malloc(sizeof(struct Original_node));
		Original_head->next = NULL;
		memset(Original_head->str, -1, sizeof(Original_head->str));
		Original_initialization_tree_improve(a, Original_head, input, count);
		//cout << "ԭʼ����ת���㷨��չ���" << endl;
		count_Original_nodes(Original_head);
		double duration_Original;
		clock_t start_Original, finish_Original;
		//cout << "��ʼ����ԭʼ����ת���㷨��ʱ��" << endl;
		struct individual_node* Original_p = head0;
		start_Original = clock();
		while (Original_p->next != NULL) {
			if (Original_p == head0) {//���ڵ�һ���ڵ�Ҫ����Boolean�߼���RM�߼���ת��
				Original_BtoRM_polarity_conversion(Original_p->next->str, input, Original_head);
			}
			else {
				Original_RMtoRM_polarity_conversion(Original_p->str, Original_p->next->str, Original_head, input);
			}
			Original_p = Original_p->next;
		}
		finish_Original = clock();
		count_Original_nodes(Original_head);
		duration_Original = (double)(finish_Original - start_Original) / CLOCKS_PER_SEC;
		cout << "ԭʼ����ת���㷨����ʱ��Ϊ " << duration_Original << endl;
		print_list1(Original_head);
		clear_Original_node_List(Original_head);
		//
		//�Ľ��㷨�Ե�·������չ
		struct node* New_head = (struct node*)malloc(sizeof(struct node));
		New_head->front = NULL;
		New_head->next = NULL;
		New_head->number = 1;
		New_initialization_tree_improve(a, New_head, input, count);
		/*for (int i = 0; i < rows; i++) {
			free(a[i]);
		}
		free(a);*/
		//cout << "�Ľ�����ת���㷨��չ���" << endl;
		count_New_nodes(New_head);
		double duration_New;
		clock_t start_New, finish_New;
		//cout << "��ʼ����Ľ�����ת���㷨��ʱ��" << endl;
		struct individual_node* New_p = head0;
		start_New = clock();
		while (New_p->next != NULL) {
			if (New_p == head0) {//���ڵ�һ���ڵ�Ҫ����Boolean�߼���RM�߼���ת��
				New_BtoRM_polarity_conversion(New_p->next->str, input, New_head);
			}
			else {
				New_RMtoRM_polarity_conversion(New_p->str, New_p->next->str, New_head, input);
			}
			New_p = New_p->next;
		}
		finish_New = clock();
		count_New_nodes(New_head);
		duration_New = (double)(finish_New - start_New) / CLOCKS_PER_SEC;
		cout << "�Ľ�����ת���㷨����ʱ��Ϊ " << duration_New << endl;
		print_list(New_head);
		clear_New_node_List(New_head);
		cout << "\n\n" << endl;
	}
	free_individual_node(head0);//�ͷ���Ⱥ�ռ�
	return 0;
}