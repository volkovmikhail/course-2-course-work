#include "Menues.h"

void admin_menu(list& user, list& obj, list& deals)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode con cols=48 lines=15");
	fstream file;
	string x, a, b, owner;
	bool exit = true;
	string* arr_data = new string[9];

	do
	{
		system("cls");
		cout << "     Администрация";
		cout << "\n\n 1. Просмотр базы данных";
		cout << "\n 2. Добавление пользователя";
		cout << "\n 3. Добавление обьекта недвижимости";
		cout << "\n 4. Добавление сделки";
		cout << "\n 5. Удаление пользователя";
		cout << "\n 6. Удаление обьекта недвижимости";
		cout << "\n 7. Удаление сделки";
		cout << "\n 8. Очистить базу данных";
		cout << "\n 9. Сохранить все данные";
		cout << "\n 0. Вернуться в главное меню\n\n >";
		getline(cin, x, '\n');
		cin.clear();

		switch (atoi(x.c_str()))
		{
		case 1:
			system("cls");
			cout << "     Какую базу данных желаете просмотреть?";
			cout << "\n 1. Пользователи";
			cout << "\n 2. Обекты";
			cout << "\n 3. История сделок\n >";
			getline(cin, a, '\n');
			cin.clear();
			switch (atoi(a.c_str()))
			{
			case 1:
				system("mode con cols=48 lines=20");
				GetConsoleScreenBufferInfo(hConsole, &csbi);
				csbi.dwSize.Y = 10000;
				SetConsoleScreenBufferSize(hConsole, csbi.dwSize);
				sortFIO(user);
				for (int i = 0; i < user.getsize(); i++)
				{
					arr_data = user[i];

					cout << "\n     " << arr_data[0];
					cout << "\n Пароль  : " << arr_data[1];
					cout << "\n Тип     : " << arr_data[2];
					cout << "\n Фамилия : " << arr_data[3];
					cout << "\n Имя     : " << arr_data[4];
					cout << "\n Отчество: " << arr_data[5];
					cout << "\n Дата ржд: " << arr_data[6];
					cout << "\n Номер   : " << arr_data[7];
					cout << "\n Город   : " << arr_data[8] << endl << endl;
				}
				system("pause");
				system("mode con cols=48 lines=15");
				break;
			case 2:
				system("mode con cols=48 lines=20");
				GetConsoleScreenBufferInfo(hConsole, &csbi);
				csbi.dwSize.Y = 10000;
				SetConsoleScreenBufferSize(hConsole, csbi.dwSize);
				for (int i = 0; i < obj.getsize(); i++)
				{
					arr_data = obj[i];

					cout << "\n     " << arr_data[0];
					cout << "\n Адрес    : " << arr_data[1];
					cout << "\n Стоимость: " << arr_data[2];
					cout << "\n Тип      : " << arr_data[3];
					cout << "\n Владелец : " << arr_data[4];
					cout << "\n Комнат   : " << arr_data[5];
					cout << "\n Этажей   : " << arr_data[6] << endl << endl;
				}
				system("pause");
				system("mode con cols=48 lines=15");
				break;
			case 3:
				system("mode con cols=48 lines=20");
				GetConsoleScreenBufferInfo(hConsole, &csbi);
				csbi.dwSize.Y = 10000;
				SetConsoleScreenBufferSize(hConsole, csbi.dwSize);
				for (int i = 0; i < deals.getsize(); i++)
				{
					arr_data = deals[i];

					cout << "\n Продавец          : " << arr_data[0];
					cout << "\n Покупатель        : " << arr_data[1];
					cout << "\n Стоимость операции: " << arr_data[2];
					cout << "\n Объект продажи    : " << arr_data[3];
					cout << "\n Адрес             : " << arr_data[4];
					cout << "\n Этап сделки       : " << arr_data[5];
					cout << "\n Дата создания     : " << arr_data[6] << endl << endl;
				}
				system("pause");
				system("mode con cols=48 lines=15");
				break;
			default:
				break;
			};

			break;
		case 2:

			system("cls");
			register_user(user);

			break;
		case 3:
			system("cls");
			do
			{
				cout << "\n Введите владельца объекта(login)\n >";
				getline(cin, owner, '\n');
				cin.clear();
				system("cls");
			} while (!valid_name(owner));
			register_obj(obj, owner);

			break;
		case 4:

			system("cls");
			add_deal(deals);

			break;
		case 5:

			system("mode con cols=48 lines=20");
			GetConsoleScreenBufferInfo(hConsole, &csbi);
			csbi.dwSize.Y = 10000;
			SetConsoleScreenBufferSize(hConsole, csbi.dwSize);
			system("cls");
			for (int i = 0; i < user.getsize(); i++)
			{
				arr_data = user[i];

				cout << "\n  " << i << ". " << arr_data[0];
				cout << "\n Пароль  : " << arr_data[1];
				cout << "\n Тип     : " << arr_data[2];
				cout << "\n Фамилия : " << arr_data[3];
				cout << "\n Имя     : " << arr_data[4];
				cout << "\n Отчиство: " << arr_data[5];
				cout << "\n Дата ржд: " << arr_data[6];
				cout << "\n Номер   : " << arr_data[7];
				cout << "\n Город   : " << arr_data[8] << endl << endl;
			}
			do
			{
				cout << "\n Выберите пользователя для удаления\n >";
				getline(cin, x, '\n');
				cin.clear();
				system("cls");
			} while (!valid_zeroLen(x));

			if (user.getsize() != 0)
			{
				user.removeAt(atoi(x.c_str()));
				system("cls");
				cout << "\n Пользователь удалён\n\n";
			}
			system("pause");
			system("mode con cols=48 lines=15");
			break;
		case 6:
			system("mode con cols=48 lines=20");
			GetConsoleScreenBufferInfo(hConsole, &csbi);
			csbi.dwSize.Y = 10000;
			SetConsoleScreenBufferSize(hConsole, csbi.dwSize);
			system("cls");
			for (int i = 0; i < obj.getsize(); i++)
			{
				arr_data = obj[i];

				cout << "\n  " << i << ". " << arr_data[0];
				cout << "\n Адрес    : " << arr_data[1];
				cout << "\n Стоимость: " << arr_data[2];
				cout << "\n Тип      : " << arr_data[3];
				cout << "\n Владелец : " << arr_data[4];
				cout << "\n Комнат   : " << arr_data[5];
				cout << "\n Этажей   : " << arr_data[6] << endl << endl;
			}

			do
			{
				cout << "\n Выберите объект для удаления\n >";
				getline(cin, x, '\n');
				cin.clear();
				system("cls");
			} while (!valid_zeroLen(x));

			if (obj.getsize() != 0)
			{
				obj.removeAt(atoi(x.c_str()));
				system("cls");
				cout << "\n Объект удалён\n\n";
			}
			system("pause");
			system("mode con cols=48 lines=15");
			break;
		case 7:
			system("mode con cols=48 lines=20");
			GetConsoleScreenBufferInfo(hConsole, &csbi);
			csbi.dwSize.Y = 10000;
			SetConsoleScreenBufferSize(hConsole, csbi.dwSize);
			system("cls");
			for (int i = 0; i < deals.getsize(); i++)
			{
				arr_data = deals[i];

				cout << "\n " << i << ". \n Продавец      : " << arr_data[0];
				cout << "\n Покупатель        : " << arr_data[1];
				cout << "\n Стоимость операции: " << arr_data[2];
				cout << "\n Объект продажи    : " << arr_data[3];
				cout << "\n Адрес             : " << arr_data[4];
				cout << "\n Этап сделки       : " << arr_data[5];
				cout << "\n Дата создания     : " << arr_data[6] << endl << endl;
			}

			do
			{
				cout << "\n Выберите сделку для удаления\n >";
				getline(cin, x, '\n');
				cin.clear();
				system("cls");
			} while (!valid_zeroLen(x));

			if (deals.getsize() != 0)
			{
				deals.removeAt(atoi(x.c_str()));
				system("cls");
				cout << "\n Сделка удалена\n\n";
			}
			system("pause");
			system("mode con cols=48 lines=15");
			break;
		case 8:
			system("cls");
			cout << "     Какую базу данных очистить?";
			cout << "\n\n 1. Пользователи";
			cout << "\n 2. Обекты";
			cout << "\n 3. История";
			cout << "\n 4. Очистить всю базу данных";
			cout << "\n 0. Назад\n\n >";
			getline(cin, b, '\n');
			cin.clear();

			switch (atoi(b.c_str()))
			{
			case 1:
				user.clear();
				file.open("data\\users.txt", ios::trunc);
				file.close();
				cout << "\n Файл users.txt был очищен\n\n";
				system("pause");
				break;
			case 2:
				obj.clear();
				file.open("data\\objects.txt", ios::trunc);
				file.close();
				cout << "\n Файл objects.txt был очищен\n\n";
				system("pause");
				break;
			case 3:
				deals.clear();
				file.open("data\\deals.txt", ios::trunc);
				file.close();
				cout << "\n Файл deals.txt был очищен\n\n";
				system("pause");
				break;
			case 4:
				user.clear();
				file.open("data\\users.txt", ios::trunc);
				file.close();

				obj.clear();
				file.open("data\\objects.txt", ios::trunc);
				file.close();

				deals.clear();
				file.open("data\\deals.txt", ios::trunc);
				file.close();

				cout << "\n База данных полностью пуста!";
				system("pause");
				break;
			default:
				break;
			}
			break;
		case 9:

			user.fileout_data("data\\users.txt");
			obj.fileout_data("data\\objects.txt");
			deals.fileout_data("data\\deals.txt");
			cout << "\n Все данные были сохранены\n\n";
			system("pause");

			break;
		case 0:
			exit = false;
			break;
		default:
			break;
		}
	} while (exit);
}