#include "deals.h"


void add_deal(list& deals)
{
	string seller, buyer, cost, object, adress, stage, date;
	bool _1or2or3 = false;
	do
	{
		cout << "\n Введите Продовца(login)\n >";
		getline(cin, seller, '\n');
		cin.clear();
		system("cls");
	} while (!valid_name(seller));

	do
	{
		cout << "\n Введите Покупателя(login) или '-'\n >";
		getline(cin, buyer, '\n');
		cin.clear();
		system("cls");
	} while (!valid_name(buyer));

	do
	{
		cout << "\n Введите стоимость операции\n >";
		getline(cin, cost, '\n');
		cin.clear();
		system("cls");
	} while (!valid_numbers(cost));

	do
	{
		cout << "\n Введите объект продажи\n >";
		getline(cin, object, '\n');
		cin.clear();
		system("cls");
	} while (!valid_zeroLen(object));

	do
	{
		cout << "\n Введите адресс обьекта\n >";
		getline(cin, adress, '\n');
		cin.clear();
		system("cls");
	} while (!valid_zeroLen(adress));

	do
	{
		cout << "\n Введите этап сделки";
		cout << "\n 1. Отклонена   2. В процессе   3. Завершена\n >"; // СТРОЧКА ПРИГОДИТСЯ
		getline(cin, stage, '\n');
		if (stage == "1")
		{
			stage = "Отклонена";
			_1or2or3 = true;
		}
		else if (stage == "2")
		{
			stage = "В_процессе";
			_1or2or3 = true;
		}
		else if(stage == "3")
		{
			stage = "Завершена";
			_1or2or3 = true;
		}

		cin.clear();
		system("cls");
	} while (!_1or2or3);

	do
	{
		cout << "\n Введите дату создания сделки\n >";
		getline(cin, date, '\n');
		cin.clear();
		system("cls");
	} while (!valid_date(date));

	deals.push_front(seller, buyer, cost, object, adress, stage, date," "," ");

}
