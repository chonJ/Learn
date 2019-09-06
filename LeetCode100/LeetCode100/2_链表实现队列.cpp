#include<iostream>
using namespace std;

struct node {
	char data;
	node * next;
};
struct queue {
	node* front;
	node* rear;
};
//初始化队列
queue * initQueue()
{
	queue * q = (queue*)malloc(sizeof(queue));
	q->front = q->rear = NULL;
	return q;
}
//判断队列是否为空
bool isEmpty(queue* q)
{
	return q->front == NULL;
}
//入队
void insertQueue(queue* q, char data)
{
	node* n = (node*)malloc(sizeof(node));
	if (n == nullptr)//内存分配失败
		return;
	n->data = data;
	n->next = NULL;//尾插最后指向空
	if (q->rear == NULL)
	{
		q->front = n;
		q->rear = n;
	}
	else
	{
		q->rear->next = n;//尾元素的下一个元素设为n
		q->rear = n;//更新尾巴
	}
	return;
}
//出队
void seleteQueue(queue* q)
{
	node* n = q->front;
	if (n == NULL)//队里没有元素
		return;
	if (q->front == q->rear)//队里只有一个元素
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		q->front = q->front->next;
		free(n);
	}
}
//打印队列
void display(queue* q)
{
	node* n = (node*)malloc(sizeof(node));
	n = q->front;
	while (n != NULL)
	{
		cout << n->data << "	";
		n = n->next;
	}
	cout << endl;
	return;
}
int main_List_Queue()
{
	int i = 0, j = 0;
	queue* q;
	q = initQueue();
	cout << "开始入队：" << endl;
	while (i < 5)
	{
		cout << char('a' + i) << "	入队，队列为：" << endl;
		insertQueue(q, 'a' + i);
		display(q);
		++i;
	}
	cout << "开始出队：" << endl;
	while (j++ < 5)
	{
		cout << "第" << j << "个元素出队，队列为：" << endl;
		seleteQueue(q);
		display(q);
		
	}
	cout << endl;
	system("pause");
	return 0;
}