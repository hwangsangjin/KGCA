#include "Stack.h"

int main()
{
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);

	s.pop();
	s.pop();
	s.pop();

	return 0;
}

// ������
Stack::Stack()
{
	// �ʱ� ����� ����
	count = 0;

	// ž ��� ����
	head = new Node{ 0, nullptr };
}

// �Ҹ���
Stack::~Stack()
{
	// ��尡 ������� �ʴٸ�
	while (!empty())
	{
		// ž ��� ����
		pop();
	}
}

void Stack::push(int value)
{
	// ���ο� ��带 �����ϰ� ž ���� ����
	Node* newNode = new Node{ value, head };

	// ž ��带 ���� ������ ���� ����
	head = newNode;

	// ��� ���� ����
	count++;
}

void Stack::pop()
{
	// ž ��尡 nullptr �̸� ����
	if (head->next == nullptr)
	{
		return;
	}

	// �ӽ� ��带 �����ϰ� ž ���� ����
	Node* temp = head;
	// ž ��带 ���� ���� ����
	head = head->next;

	// ž ��� �޸� ����
	delete temp;

	// ��� ���� ����
	count--;
}

int Stack::top()
{

	return head->data;
}

int Stack::size()
{
	return count;
}

bool Stack::empty()
{
	return count == 0;
}