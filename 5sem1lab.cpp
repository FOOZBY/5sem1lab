#include "func.h"

int main()
{
	setlocale(0, "");

	List<int> first_list;
	List<int> second_list;
	int length, elem;

	cout << "введите размерность первого списка: ";
	cin >> length;
	cout << "введите элементы 1-ого списка" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> elem;
		first_list.push_back(elem);
	}

	cout << "введите размерность второго списка: ";
	cin >> length;
	cout << "введите элементы 2-ого списка" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> elem;
		second_list.push_back(elem);
	}

	cout << "последнее вхождение 2-ого списка в первый на ";
	first_list.variant_task(second_list);
	cout << " элементе";
	system("pause");
	return 0;
}