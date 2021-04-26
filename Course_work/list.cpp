#ifndef _LIST_CPP
#define _LIST_CPP


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class list
{
public:
	// Functions:
	list()
	{
		size = 0;
		head = nullptr;
	};

	~list()
	{
		clear();
	};

	void removeAt(int index)
	{
		NODE* prev = this->head;
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->pNext;
			}
			NODE* ToDelete = prev->pNext;
			prev->pNext = ToDelete->pNext;
			delete ToDelete;
			size--;
		}
	};

	void insert(string data0, string data1, string data2,
		string data3, string data4, string data5,
		string data6, string data7,
		string data8, int index)
	{
		NODE* prev = this->head;
		if (index == 0)
		{
			push_front(data0, data1, data2, data3,
			 data4,data5, data6,data7,
			 data8);
		}
		else
		{
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->pNext;
			}
			prev->pNext = new NODE(data0, data1, data2,
				data3, data4, data5, data6, data7,
				data8, prev->pNext);
			size++;
		}
	};

	void clear()
	{
		while (size)
		{
			pop_front();
		}
	};

	void pop_front()
	{
		if (size == 1)
		{
			NODE* temp = head;
			head = nullptr;
			delete temp;
		}
		else
		{
			NODE* temp = head;
			head = head->pNext;
			delete temp;
		}
		size--;
	};

	void pop_back()
	{
		removeAt(size - 1);
	};

	void push_front(string data0, string data1, 
		string data2, string data3, string data4, 
		string data5, string data6, string data7,
		string data8)
	{
		head = new NODE(data0, data1, data2,
			data3, data4, data5, data6, data7,
			data8, head);
		size++;
	};

	void push_back(string data0, string data1,
		string data2, string data3, string data4,
		string data5, string data6, string data7,
		string data8)
	{
		if (head == nullptr)
		{
			head = new NODE(data0, data1, data2,
				data3, data4, data5, data6, data7,
				data8);
		}
		else
		{
			NODE* current = this->head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new NODE(data0, data1,
				data2, data3, data4, data5, data6,
				data7,data8);
		}
		size++;
	};

	int getsize()
	{
		return size;
	}

	string* operator[](const int index) 
	{
		NODE* current = this->head;
		int counter = 0;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
		return 0;
	};
	// Запись в файл и чтение :
	void fileout_data(string path)
	{
		ofstream fout;
		fout.open(path, ios::trunc);
		if (!fout.is_open())
		{
			cout << "\n Ошибка записи, данные не изменены";
		}
		else
		{
			NODE* node = this->head;
			while (node != nullptr)
			{
				fout << endl;
				for (size_t i = 0; i < 9; i++)
				{
					fout <<" "<< node->data[i];
				}
				node = node->pNext;
			}
		}
		fout.close();
	};

	void load_data(string path)
	{
		ifstream fin;
		fin.open(path);
		if (!fin.is_open())
		{
			ofstream fout(path);
		}
		else if (fin.peek() == EOF)
		{
			fin.close();
			return;
		}
		else
		{

			string list_data[9];

			while (!fin.eof())
			{
				for (size_t i = 0; i < 9; i++)
				{
					fin >> list_data[i];
				}
				push_back(list_data[0], list_data[1], list_data[2], list_data[3], list_data[4],
					list_data[5], list_data[6], list_data[7], list_data[8]);
			}

		}
		fin.close();
	};

private:
	// NODE with data:
	class NODE
	{
	public:

		NODE* pNext;
		string data[9];
		//     Пользователи					Обьекты						Сделки		
		// 0  - логин						0  - Название обкта			0  - Продавец
		// 1  - пороль						1  - Адресс					1  - Покупатель
		// 2  - клиент/агент				2  - Стоимость				2  - Стоимость операции
		// 3  - фамилия						3  - Тип Недвиж				3  - Обьект который купили (название)
		// 4  - имя							4  - Владелец				4  - Адресс
		// 5  - отчество					5  - Кол-во Комнат			5  - этап сделки, в процессе покупки или уже купилено
		// 6  - дата рожд.					6  - Кол-во Этажей			6  - дата
		// 7  - телефон						7  - 						7  - 				
		// 8  - город						8  - 						8  - 
		
		
		NODE(string data0,string data1, string data2,
			string data3, string data4, string data5,
			string data6, string data7,string data8, NODE* pNext = nullptr)
		{
			this->data[0] = data0;
			this->data[1] = data1;
			this->data[2] = data2;
			this->data[3] = data3;  
			this->data[4] = data4;
			this->data[5] = data5;
			this->data[6] = data6;
			this->data[7] = data7;
			this->data[8] = data8;
			this->pNext =  pNext;
		}
	};
	unsigned int size;
	NODE* head;
};
#endif