#include <iostream>


using namespace std;

template<typename T>
struct List
{
public:
	List();
	~List();
	

	int Size;//кол-во эл-ов в списке
	void push_back(T data);
	int getSize() { return Size; };
	T& operator[](const int index);
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();
	void showlist();
	void changeAt(T data, int index);
	void is_clear()
	{
		return Size ? 1 : 0;
	};
	const void variant_task(List& second_list);

private:

	template<typename T>
	struct Node
	{
		Node* pNext;
		Node* pPrev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};

	Node<T>* head;//голова списка
	Node<T>* tail;//хвост списка
};

template<typename T>
inline List<T>::List()//+
{
	Size = 0;
	head = tail = nullptr;
}

template<typename T>
inline List<T>::~List()//+
{
	clear();
}

template<typename T>
inline void List<T>::push_back(T data)//+
{
	if (head == nullptr)
	{
		
		head = tail = new Node<T>(data);
	}
	else
	{
		Node<T>* current = new Node<T>(data);
		tail->pNext = current;
		current->pPrev = tail;
		tail = current;
	}
	Size++;
}

template<typename T>
inline T& List<T>::operator[](const int index)//+
{
	T s = "";
	if (index < 0 || index >= Size)
		return s;

	if (Size / 2 >= index)//1st half
	{
		int counter = 0;
		Node<T>* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	else //2 half
	{
		int counter = Size;
		Node<T>* current = this->tail;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pPrev;
			counter--;
		}
	}
}

template<typename T>
inline void List<T>::pop_front()//+
{
	if (Size == 0) return;
	if (Size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node<T>* temp = head;
		head = head->pNext;
		head->pPrev = nullptr;
		delete temp;
	}
	Size--;
}

template<typename T>
inline void List<T>::clear()//+
{
	while (Size)
		pop_front();
}

template<typename T>
inline void List<T>::push_front(T data)//+
{
	if (head == nullptr)
	{
		head = tail = new Node<T>(data);
	}
	else
	{
		Node* current = new Node<T>(data);
		head->pPrev = current;
		current->pNext = head;
		head = current;
	}
	Size++;
}

template<typename T>
inline void List<T>::insert(T data, int index)//+
{
	if (index <= 0)
		push_front(data);
	else if (index >= Size)
		push_back(data);
	else if (Size / 2 - index > 0)//1st half
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		previous->pNext = new Node<T>(data, previous->pNext, previous);
		Size++;

	}
	else//2nd half
	{
		Node<T>* next = this->tail;

		for (int i = Size - 1; i >= index; i--)
		{
			next = next->pPrev;
		}
		next->pNext = new Node<T>(data, next->pNext, next);
		next->pNext->pNext->pPrev = next->pNext; // Size >=2
		Size++;
	}
}

template<typename T>
inline void List<T>::removeAt(int index)//+
{
	if (Size)
	{
		if (index <= 0)
			pop_front();
		else if (index >= Size - 1)
			pop_back();
		else if (Size / 2 - index > 0)
		{
			Node<T>* previous = this->head;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}

			Node<T>* toDelete = previous->pNext;

			previous->pNext = toDelete->pNext;
			toDelete->pNext->pPrev = previous;
			delete toDelete;
			Size--;
		}
		else
		{
			Node<T>* next = this->tail;

			for (int i = Size - 1; i > index + 1; i--)
			{
				next = next->pPrev;
			}

			Node<T>* toDelete = next->pPrev;

			next->pPrev = toDelete->pPrev;
			toDelete->pPrev->pNext = next;

			delete toDelete;
			Size--;
		}
	}
	else
		cout << "Отсутствуют элементы списка\n";
}

template<typename T>
inline void List<T>::pop_back()//+
{
	if (Size == 0) return;
	if (Size == 1)
	{
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node<T>* current = tail;
		tail = tail->pPrev;
		tail->pNext = nullptr;
		delete current;
	}
	Size--;
}

template<typename T>
inline void List<T>::showlist()
{
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->pNext;
	}
}

template<typename T>
inline void List<T>::changeAt(T data, int index)
{
	if (index <= 0)
		push_front(data);
	else if (index >= Size)
		push_back(data);
	else if (Size / 2 - index > 0)//1st half
	{
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++)
			current = current->pNext;
		current->data = data;
	}
	else//2nd half
	{
		Node<T>* current = this->tail;

		for (int i = Size - 1; i >= index; i--)
			current = current->pPrev;
		current->data = data;
	}
}

template<typename T>
inline const void List<T>::variant_task(List<T>& second_list)
{
	int counter = this->getSize();
	if (second_list.getSize() > this->getSize() || second_list.getSize() == 0)
	{
		cout << "-1";
	}
	Node<T>* current = this->tail;
	Node<T>* elem_a;
	Node<T>* elem_b;//elem_a - элемент основного списка, elem_b - элемент подсписка
	for (int i = 0; i < second_list.getSize()-1; i++)
	{
		current = current->pPrev;
		counter--;
	}
	while (current->pPrev != nullptr)
	{
		if (current->data == second_list.head->data)
		{
			elem_a = current;
			elem_b = second_list.head;
			while (elem_a->data == elem_b->data)
			{
				elem_a = elem_a->pNext;
				elem_b = elem_b->pNext;
				if (elem_b == nullptr)
				{
					cout << counter;
					return;
				}
			}
		}
		current = current->pPrev;
		counter--;
	}

}