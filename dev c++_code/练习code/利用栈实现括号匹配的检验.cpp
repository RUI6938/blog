#include<iostream>

using namespace std;

template<class T>
struct StackNode
{
	T data;
	StackNode<T>* link;
	StackNode()
	{
		link = NULL;
	}
	StackNode(T x)
	{
		data = x;
		link = NULL;
	}
};

template<class T>
class Stack
{
public:
	Stack();  //构造函数
	~Stack();  //析构函数
	void Push(T x);  //入栈
	bool Pop(T& x);  //出栈
	bool Get_top(T& x)const;  //取栈顶值
	void MakeEmpty();  //清空栈
	bool IsEmpty(); //判断栈空
private:
	StackNode<T>* top;
};

template<class T>
Stack<T>::Stack()
{
	top = NULL;
}

template<class T>
Stack<T>::~Stack()
{
	MakeEmpty();
}

template<class T>
void Stack<T>::Push(T x)
{
	StackNode<T>* newnode;
	newnode = new StackNode<T>(x);
	if (newnode == NULL)
		return;
	newnode->link = top;
	top = newnode;
}

template<class T>
bool Stack<T>::Pop(T& x)
{
	StackNode<T>* temp = NULL;
	if (top == NULL)
		return false;
	temp = top;
	top = top->link;
	x = temp->data;
	delete temp;
	return true;
}

template<class T>
bool Stack<T>::Get_top(T& x)const
{
	if (top == NULL)
		return false;
	x = top->data;
	return true;
}

template<class T>
void Stack<T>::MakeEmpty()
{
	T temp;
	while (Pop(temp));
}

template<class T>
bool Stack<T>::IsEmpty()
{
	if (top == NULL)
		return true;
	else
		return false;
}

bool Match()  //括号匹配
{
	Stack<char> t;
	char ch,temp,top_data;
	while (cin >> noskipws >> ch && ch != '\n')
	{
		if (ch == '(' || ch == '[' || ch == '{')
		{
			t.Push(ch);
		}
		else
		{
			if (t.Get_top(top_data))
			{
				if (ch == ')' && top_data == '(' || ch == ']' && top_data == '[' || ch == '}' && top_data == '{')
				{
					t.Pop(temp);
				}
			}
			else
			{
				if (ch == ')' || ch == ']' || ch == '}')
					return false;
			}
		}
	}
	return t.IsEmpty();
}

int main()
{
	if (Match())
		cout << "success" << endl;
	else
		cout << "failure" << endl;
	return 0;
}

