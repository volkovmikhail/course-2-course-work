#include "Menues.h"

void user_menu(list& user,list & obj ,list & deals,bool exit)
{
	string repeat;
	bool next = true;
	int currentuser;
	string login, password;
	string* Userdata = new string[9];

	do
	{
		do
		{
			cout << "\n Логин \n >";
			getline(cin, login, '\n');
			cin.clear();
			system("cls");
		} while (!valid_zeroLen(login));
		do
		{
			cout << "\n Логин\n >" << login;
			cout << "\n\n Пароль \n >";
			getline(cin, password, '\n');
			cin.clear();
			system("cls");
		} while (!valid_zeroLen(password));
			

		if (login == "admin" && password == "wolf")
		{
			admin_menu(user,obj,deals);
			return;
		}

		if (user.getsize() == 0)
		{ }
		else
		{
			Userdata = user[0];
			currentuser = 0;
			while (!(Userdata[0] == login) && !(currentuser == user.getsize() - 1))
			{
				currentuser++;
				Userdata = user[currentuser];
			}

			if (Userdata[0] != login)
			{
				
			}
			else if(Userdata[1] == password)
			{
				next = false;
				break;
			}
		}

		do
		{
			system("cls");
			cout << "\n Логин \n >";
			cout << "\n\n Пароль \n >";
			cout << "\n\n 1. Повторить    2. Назад\n >";
			getline(cin, repeat, '\n');
			cin.clear();
		} while (!ONE_or_TWO(repeat));
		if (repeat == "2")
		{
			return;
		}

		system("cls");
	} while (next);
	system("cls");

	string agent = "Агент";
	if (Userdata[2] == agent)
	{
		agent_menu(user,obj,deals,currentuser);
		return;
	}
	else
	{
		client_menu(user,obj,deals,currentuser);
		return;
	}
};

void client_menu(list& user, list& obj, list& deals, int currentuser)
{

	CONSOLE_SCREEN_BUFFER_INFO csbi; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SYSTEMTIME st;
	GetSystemTime(&st);

	system("mode con cols=48 lines=13");
	int year, month, day;
	string x,temp,temp2,seller, buyer,date;
	string* data = new string[9];
	int* Index = new int[user.getsize()];
	int* dealsIndex = new int[deals.getsize()];
	int* objIndex = new int[obj.getsize()];
	data = user[currentuser];
	string title = "title Меню клиента ";
	title = title + data[0];
	system(title.c_str());
	bool ret = true;
	int lines(0);

	do
	{
	data = user[currentuser];
		do
		{
			system("cls");
			cout << "     Здравствуйте, " << data[4];																											//Функции клиента <-
			cout << "\n\n 1. Мой профиль";
			cout << "\n 2. Поиск объекта";
			cout << "\n 3. Поиск Агента";
			cout << "\n 4. Добавить объект";
			cout << "\n 5. Текущие сделки";
			cout << "\n 6. Моя недвижимость";
			cout << "\n 7. История моих сделок";
			cout << "\n 8. Настройки";
			cout << "\n 0. Выход\n >";
			getline(cin, x, '\n');
			cin.clear();
		} while (!valid_zeroLen(x) || !valid_numbers(x));
		
		switch(atoi(x.c_str()))
		{
		case 1:
			do
			{
				data = user[currentuser];
				system("cls");
				cout << "      Ваш профиль ";
				cout << "\n\n Логин   : " << data[0];
				cout << "\n Фамилия : " << data[3];
				cout << "\n Имя     : " << data[4];
				cout << "\n Отчиство: " << data[5];
				cout << "\n Дата ржд: " << data[6];
				cout << "\n Номер   : " << data[7];
				cout << "\n Город   : " << data[8] << endl << endl;
				cout << " 1.Редактировать 0. Назад\n >";
				getline(cin, x);
				cin.clear();

				if (x == "1")
				{
					edit_user(user, currentuser);
					x = "-";
				}
				
			} while (!ONE_or_TWO(x) && !( x == "0"));

			break;
		case 2:
			
			lines = 0;
				for (int i = 0; i < obj.getsize(); i++)
				{
					lines += 11; 
				}

			do
			{
				do
				{
					 
					GetConsoleScreenBufferInfo(hConsole, &csbi); //полоска прокрутки
					csbi.dwSize.Y = lines;
					SetConsoleScreenBufferSize(hConsole, csbi.dwSize);
					system("cls");
					for (int i = 0; i < obj.getsize(); i++)
					{
						data = obj[i];

						cout << "\n     " << data[0];
						cout << "\n Адрес    : " << data[1];
						cout << "\n Стоимость: " << data[2];
						cout << "\n Тип      : " << data[3];
						cout << "\n Владелец : " << data[4];
						cout << "\n Комнат   : " << data[5];
						cout << "\n Этажей   : " << data[6];
						cout << "\n  " << i + 1 << ". Подробней" << endl << endl; //купить или что то ещё

					}

					if (obj.getsize() == 0)
					{
						cout << "\n В базе данных нету объектов\n\n";
					}

					cout << " Введите номер для подробностей (0 - назад)\n >";
					
					getline(cin, x);
					cin.clear();
					temp = x;
					if (atoi(x.c_str()) > obj.getsize() || atoi(x.c_str()) <= 0)
					{
						break;
					}

					do
					{
						
						do
						{
							system("cls");
							system("mode con cols=48 lines=13");
							data = obj[atoi(temp.c_str()) - 1]; // (-1)!!
							cout << "     " << data[0];
							cout << "\n Адрес    : " << data[1];
							cout << "\n Стоимость: " << data[2];
							cout << "\n Тип      : " << data[3];
							cout << "\n Владелец : " << data[4];
							cout << "\n Комнат   : " << data[5];
							cout << "\n Этажей   : " << data[6];

							temp2 = data[4];
							for (int i = 0; i < user.getsize(); i++)
							{
								data = user[i];
								if (data[0] == temp2)
								{
									break;
								}
							}
							cout << "\n Вы можете позвонить владельцу\n по номеру: " << data[7];
							cout << "\n\n 1. Информация о владельце   2. Купить\n 0. Назад\n >";
							getline(cin, x);
							cin.clear();
						} while (!ONE_or_TWO(x)&&!(x == "0"));
						
						if (x == "1")
						{
							system("cls");
							cout << "\n      Профиль " << data[0];
							cout << "\n Фамилия : " << data[3];
							cout << "\n Имя     : " << data[4];
							cout << "\n Отчество: " << data[5];
							cout << "\n Дата ржд: " << data[6];
							cout << "\n Номер   : " << data[7];
							cout << "\n Город   : " << data[8] << endl << endl;
							system("pause");
						}

						if (x == "2")//купить
						{
							system("cls");
							seller = data[0];
							data = user[currentuser];
							buyer = data[0];
							data = obj[atoi(temp.c_str())-1];
							
							day = st.wDay;
							month = st.wMonth;
							year = st.wYear;

							if (day < 10)
							{
								date = "0" + to_string(day)+ ".";
							}
							else
							{
								date = to_string(day) + ".";
							}

							if (month < 10)
							{
								date += "0" + to_string(month) + ".";
							}
							else
							{
								date += to_string(month) + ".";
							}

							date += to_string(year);

							deals.push_back(seller,buyer,data[2], data[0],data[1], "В_процессе",date,"-","-");
							cout << "\n Заявка отправлена владельцу\n Ожидайте подтверждения\n Если владелец подтвердит - объект ваш.\n\n";
							
							deals.fileout_data("data\\deals.txt");

							system("pause");
						}

						if (x == "0")
						{
							break;
						}

					} while (true);
					
				} while (true);

				if (x == "0")
				{
					break;
				}
			} while (true);

			system("mode con cols=48 lines=13");
			break;
		case 3:

			ret = true;
			do
			{
				do
				{
					lines = 0;
					for (int i = 0; i < user.getsize(); i++)
					{
						data = user[i];
						if (data[2] == "Агент")
						{
							lines += 12;
						}
					}

					 
					GetConsoleScreenBufferInfo(hConsole, &csbi);
					csbi.dwSize.Y = lines;
					SetConsoleScreenBufferSize(hConsole, csbi.dwSize);

					day = 0;
					for (int i = 0; i < user.getsize(); i++)
					{
						data = user[i];

						if (data[2] == "Агент")
						{

							day++; //сохраняю индексы
							Index[day] = i;
							cout << "\n     " << data[0];
							cout << "\n Фамилия : " << data[3];
							cout << "\n Имя     : " << data[4];
							cout << "\n Отчество: " << data[5];
							cout << "\n Дата ржд: " << data[6];
							cout << "\n Номер   : " << data[7];
							cout << "\n Город   : " << data[8];
							cout << "\n  " << day << ". Подробней / Нанять" << endl << endl;

						}
					}

					if (day == 0)
					{
						cout << "\n В базе данных нету агентов\n";
					}

					cout << "\n Подробней об агенте (0 - назад)\n >";
					getline(cin, temp);
					cin.clear();
					system("cls");
				} while (!(atoi(temp.c_str()) > day || atoi(temp.c_str()) < 0) && !valid_numbers(temp));

				if (temp == "0")
				{
					system("mode con cols=48 lines=13");
					break;
				}

				system("mode con cols=48 lines=13");

				do//подробней
				{
					data = user[Index[atoi(temp.c_str())]];

					cout << "\n     " << data[0];
					cout << "\n Фамилия : " << data[3];
					cout << "\n Имя     : " << data[4];
					cout << "\n Отчество: " << data[5];
					cout << "\n Дата ржд: " << data[6];
					cout << "\n Номер   : " << data[7];
					cout << "\n Город   : " << data[8];

					temp2 = data[0];
					year = 0;
					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if ((data[0] == temp2 || data[1] == temp2) && data[5] == "Завершена")
						{
							year++; // кол-во успешных сделак
						}
					}

					cout << "\n Количество удачнх сделок: " << year;
					cout << "\n\n  1. Нанять    0. назад\n >";
					getline(cin, x);
					cin.clear();
					system("cls");
				} while (x != "1" && x != "0");

				if (x == "1")// нанять
				{
					system("cls");
					data = user[currentuser];
				

					day = st.wDay;
					month = st.wMonth;
					year = st.wYear;

					if (day < 10)
					{
						date = "0" + to_string(day) + ".";
					}
					else
					{
						date = to_string(day) + ".";
					}

					if (month < 10)
					{
						date += "0" + to_string(month) + ".";
					}
					else
					{
						date += to_string(month) + ".";
					}

					date += to_string(year);

					deals.push_back(temp2,data[0],"-","Найм_агента","-","В_процессе",date,"-","-");
					cout << "\n Заявка на найм отправлена Агенту,\n Ожидайте подтверждения,\n После подтверждения агент свяжется с вами\n\n";
					
					deals.fileout_data("data\\deals.txt");

					system("pause");
				}

				if (x == "0")
				{
					continue;
				}

			} while (ret);
			
			break;
		case 4:

			system("cls");
			day = obj.getsize();
			register_obj(obj, data[0]);
			cout << "\n Объект выставлен на продажу,\n Ожидайте заявки в разделе 'Текущие сделки'\n\n";
			if (day != obj.getsize())
			{
				system("pause");
			}

			break;
		case 5: //сделать подтверждение сделки

			system("cls");
			ret = true;
			data = user[currentuser];
			temp2 = data[0];

			do
			{
				do
				{
					lines = 0;
					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if (data[0] == temp2 || data[1] == temp2 && data[5] == "В_процессе")
						{
							lines += 11;
						}
					}

					 
					GetConsoleScreenBufferInfo(hConsole, &csbi);
					csbi.dwSize.Y = lines;
					SetConsoleScreenBufferSize(hConsole, csbi.dwSize);

					day = 0;

					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if ((data[0] == temp2 || data[1] == temp2) && data[5] == "В_процессе")
						{
							day++;
							dealsIndex[day] = i;
							cout << "\n\n Продавец          : " << data[0];
							cout << "\n Покупатель        : " << data[1];
							if (data[2] != "-")
							{
								cout << "\n Стоимость операции: " << data[2];
							}
							cout << "\n Объект продажи    : " << data[3];
							if (data[4] != "-")
							{
								cout << "\n Адрес             : " << data[4];
							}
							cout << "\n Дата              : " << data[6];
							cout << "\n Этап сделки -> " << data[5];
							cout << "\n   " << day << ". Подтвердить / подробней" << endl << endl;
						}
					}
					if (day == 0)
					{
						cout << "\n У вас нету текущих сделок\n\n";
					}
					cout << " Вы можете подтвердить сделки выбрав номер";
					cout << "\n Введите номер (0 - назад)\n >";
					getline(cin, x);
					cin.clear();
					system("cls");
				} while ((atoi(x.c_str()) > day || atoi(x.c_str()) < 0) || !valid_numbers(x));

				if (x == "0")
				{
					break;
				}

				system("mode con cols=48 lines=13");

				do // подробней / подтвердить
				{
					data = deals[dealsIndex[atoi(x.c_str())]];

					cout << "\n\n Продавец          : " << data[0];
					cout << "\n Покупатель        : " << data[1];
					if (data[2] != "-")
					{
						cout << "\n Стоимость операции: " << data[2];
					}
					cout << "\n Объект продажи    : " << data[3];
					if (data[4] != "-")
					{
						cout << "\n Адрес             : " << data[4];
					}
					cout << "\n Дата              : " << data[6];
					cout << "\n Этап сделки -> " << data[5];


					if (data[5] == "В_процессе" && data[0] == temp2)
					{
						cout << "\n\n 1. Подтвердить  2. Отклонить  0. Назад\n >";
						getline(cin, temp);
						cin.clear();
						system("cls");
					}
					else
					{

						cout << "\n\n 0 - назад\n >";
						getline(cin, temp);
						cin.clear();
						system("cls");
						if (temp == "1" || temp == "2")
						{
							temp = "0";
						}

					}

				} while (!ONE_or_TWO(temp) && !(temp == "0"));

				if (temp == "1")
				{
					if (data[4] == "-")
					{
						deals.push_back(data[0], data[1], data[2], data[3], data[4], "Завершена", getSystemTime(), data[7], data[8]);
						deals.removeAt(dealsIndex[atoi(x.c_str())]);
						cout << "\n Сделка завершена,\n Этот клиент в вашей клиентской базе\n\n";
						system("pause");
					}
					else if (data[4] != "-")
					{
						temp = data[1];
						seller = data[3];
						deals.push_back(data[0], data[1], data[2], data[3], data[4], "Завершена", getSystemTime(), data[7], data[8]);
						deals.removeAt(dealsIndex[atoi(x.c_str())]);
						for (int i = 0; i < obj.getsize(); i++)
						{
							data = obj[i];
							if (data[0] == seller)
							{
								day = i;
								break;
							}
						}

						obj.push_back(data[0], data[1], data[2], data[3], temp, data[5], data[6], data[7], data[8]);

						obj.removeAt(day);

						cout << "\n Обьект передан пользователю " << temp << ",";
						cout << "\n Сделка завершена\n\n";
						system("pause");
						break;
					}

					obj.fileout_data("data\\objects.txt");
					deals.fileout_data("data\\deals.txt");
				}

				if (temp == "2")
				{

					deals.push_back(data[0], data[1], data[2], data[3], data[4], "Отклонена", getSystemTime(), data[7], data[8]);

					deals.removeAt(dealsIndex[atoi(x.c_str())]);

					deals.fileout_data("data\\deals.txt");

				}

			} while (ret);

			system("mode con cols=48 lines=13");

			break;
		case 6: // Моя недвижимость

			system("cls");
			data = user[currentuser];
			temp2 = data[0];

			do
			{
				do
				{
					lines = 0;
					for (int i = 0; i < obj.getsize(); i++)
					{
						data = obj[i];
						if (temp2 == data[4])
						{
							lines += 11;
						}
					}

					 
					GetConsoleScreenBufferInfo(hConsole, &csbi);
					csbi.dwSize.Y = lines;
					SetConsoleScreenBufferSize(hConsole, csbi.dwSize);

					day = 0;

					for (int i = 0; i < obj.getsize(); i++)
					{
						data = obj[i];
						if (data[4] == temp2)
						{
							day++;
							objIndex[day] = i;
							cout << "\n     " << data[0];
							cout << "\n Адрес    : " << data[1];
							cout << "\n Стоимость: " << data[2];
							cout << "\n Тип      : " << data[3];
							cout << "\n Владелец : " << data[4];
							cout << "\n Комнат   : " << data[5];
							cout << "\n Этажей   : " << data[6];
							cout << "\n  " << day << ". Подробней / Редактировать" << endl << endl;
						}
					}

					if (day == 0)
					{
						cout << "\n У вас нету недвижимости\n";
					}

					cout << "\n Введите что-нибудь (0 - назад)\n >";
					getline(cin, x);
					cin.clear();
					system("cls");

				} while ((atoi(x.c_str()) > day || atoi(x.c_str()) < 0) || !valid_numbers(x));

				if (x == "0")
				{
					system("mode con cols=48 lines=13");
					break;
				}

				system("mode con cols=48 lines=13");

				do
				{
					system("cls");
					data = obj[objIndex[atoi(x.c_str())]];
					cout << "\n\n     " << data[0];
					cout << "\n Адрес    : " << data[1];
					cout << "\n Стоимость: " << data[2];
					cout << "\n Тип      : " << data[3];
					cout << "\n Владелец : " << data[4];
					cout << "\n Комнат   : " << data[5];
					cout << "\n Этажей   : " << data[6];
					cout << "\n\n 1. Редактировать 0. Назад\n >";

					getline(cin, temp);
					cin.clear();

					if (temp == "1")
					{
						edit_obj(obj, objIndex[atoi(x.c_str())]);
						temp = "";
					}

					if (temp == "2")
					{
						temp = "";
					}


				} while (!ONE_or_TWO(temp) && !(temp == "0"));

			} while (true);

			
			system("mode con cols=48 lines=13");

			break;
		case 7:

			system("cls");
			ret = true;
			data = user[currentuser];
			temp2 = data[0];

			do
			{
				do
				{
					lines = 0;
					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if (data[0] == temp2 || data[1] == temp2)
						{
							lines += 11;
						}
					}

					 
					GetConsoleScreenBufferInfo(hConsole, &csbi);
					csbi.dwSize.Y = lines+4;
					SetConsoleScreenBufferSize(hConsole, csbi.dwSize);

					day = 0;

					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if (data[0] == temp2 || data[1] == temp2)
						{
							day++;
							dealsIndex[day] = i;
							cout << "\n\n Продавец          : " << data[0];
							cout << "\n Покупатель        : " << data[1];
							if (data[2] != "-")
							{
								cout << "\n Стоимость операции: " << data[2];
							}
							cout << "\n Объект продажи    : " << data[3];
							if (data[4] != "-")
							{
								cout << "\n Адрес             : " << data[4];
							}
							cout << "\n Дата              : " << data[6];
							cout << "\n Этап сделки -> " << data[5];
							cout << "\n   " << day << ". Подробней" << endl << endl;
						}
					}

					if (day == 0)
					{
						cout << "\n Вы не совершали сделок\n";
					}

					cout << "\n Введите номер (0 - назад)\n >";
					getline(cin, x);
					cin.clear();
					system("cls");
				} while ((atoi(x.c_str()) > day || atoi(x.c_str()) < 0) || !valid_numbers(x));

				if (x == "0")
				{
					break;
					system("mode con cols=48 lines=13");
				}

				system("mode con cols=48 lines=13");

				do // подробней
				{
					data = deals[dealsIndex[atoi(x.c_str())]];

					cout << "\n\n Продавец          : " << data[0];
					cout << "\n Покупатель        : " << data[1];
					if (data[2] != "-")
					{
						cout << "\n Стоимость операции: " << data[2];
					}
					cout << "\n Объект продажи    : " << data[3];
					if (data[4] != "-")
					{
						cout << "\n Адрес             : " << data[4];
					}
					cout << "\n Дата              : " << data[6];
					cout << "\n Этап сделки -> " << data[5];


					cout << "\n\n 0 - назад\n >";
					getline(cin, temp);
					cin.clear();
					system("cls");
					if (temp == "1" || temp == "2")
					{
						temp = "0";
					}
				

				} while (temp != "0");

			} while (ret);

			system("mode con cols=48 lines=13");

			break;
		case 8:

			do
			{
				system("cls");
				cout << "      Настройки темы";
				cout << "\n\n 1. По умолчанию";
				cout << "\n 2. MS-DOS";
				cout << "\n 3. Norton";
				cout << "\n 4. Светлая тема";
				cout << "\n 5. Матрица";
				cout << "\n 6. Яркая тема";
				cout << "\n 0. Назад";
				cout << "\n\n >";
				getline(cin, x);
				cin.clear();
				switch (atoi(x.c_str()))
				{
				case 1:
					system("color 87");// по умолчанию
					break;
				case 2:
					system("color 07");//мс-дос
					break;
				case 3:
					system("color 1B"); // нортон
					break;
				case 4:
					system("color F0");//чёрным по белому
					break;
				case 5:
					system("color 0A");//матрица
					break;
				case 6:
					system("color E5");// персик
					break;
				default:
					break;
				}

				if (x == "0")
				{
					break;
				}

			} while (true);

			break;
		case 0:
			ret = false;
			break;
		default:
			break;
		}
	} while (ret);

};

void agent_menu(list& user, list& obj, list& deals, int currentuser)
{

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SYSTEMTIME st;
	GetSystemTime(&st);

	system("mode con cols=48 lines=13");
	int year, month, day;
	string x, temp, temp2, seller, buyer, date;
	string* data = new string[9];
	int* Index = new int[user.getsize()];
	int* dealsIndex = new int[deals.getsize()];
	int* objIndex = new int[obj.getsize()];
	data = user[currentuser];
	string title = "title Меню клиента ";
	title = title + data[0];
	system(title.c_str());
	bool ret = true;
	int lines(0);

	do
	{
		data = user[currentuser];
		do
		{
			system("cls");
			cout << "     Здравствуйте, " << data[4];																											//Функции клиента <-
			cout << "\n\n 1. Мой профиль";
			cout << "\n 2. Поиск объекта";
			cout << "\n 3. Моя клиентская база";
			cout << "\n 4. Добавить объект";
			cout << "\n 5. Текущие сделки";
			cout << "\n 6. Моя недвижимость";
			cout << "\n 7. История моих сделок";
			cout << "\n 8. Настройки";
			cout << "\n 0. Выход\n >";
			getline(cin, x, '\n');
			cin.clear();
		} while (!valid_zeroLen(x) || !valid_numbers(x));

		switch (atoi(x.c_str()))
		{
		case 1:
			do
			{
				data = user[currentuser];
				system("cls");
				cout << "      Ваш профиль ";
				cout << "\n\n Логин   : " << data[0];
				cout << "\n Фамилия : " << data[3];
				cout << "\n Имя     : " << data[4];
				cout << "\n Отчиство: " << data[5];
				cout << "\n Дата ржд: " << data[6];
				cout << "\n Номер   : " << data[7];
				cout << "\n Город   : " << data[8] << endl << endl;
				cout << " 1.Редактировать 0. Назад\n >";
				getline(cin, x);
				cin.clear();

				if (x == "1")
				{
					edit_user(user, currentuser);
					x = "-";
				}

			} while (!ONE_or_TWO(x) && !(x == "0"));

			break;
		case 2:

			lines = 0;
			for (int i = 0; i < obj.getsize(); i++)
			{
				lines += 11;
			}

			do
			{
				do
				{
					 
					GetConsoleScreenBufferInfo(hConsole, &csbi); //полоска прокрутки
					csbi.dwSize.Y = lines;
					SetConsoleScreenBufferSize(hConsole, csbi.dwSize);
					system("cls");
					for (int i = 0; i < obj.getsize(); i++)
					{
						data = obj[i];

						cout << "\n     " << data[0];
						cout << "\n Адрес    : " << data[1];
						cout << "\n Стоимость: " << data[2];
						cout << "\n Тип      : " << data[3];
						cout << "\n Владелец : " << data[4];
						cout << "\n Комнат   : " << data[5];
						cout << "\n Этажей   : " << data[6];
						cout << "\n  " << i + 1 << ". Подробней" << endl << endl; //купить или что то ещё

					}

					if (obj.getsize() == 0)
					{
						cout << "\n В базе данных нету объектов\n\n";
					}

					cout << " Введите номер для подробностей (0 - назад)\n >";

					getline(cin, x);
					cin.clear();
					temp = x;
					if (atoi(x.c_str()) > obj.getsize() || atoi(x.c_str()) <= 0)
					{
						break;
					}

					do
					{

						do
						{
							system("cls");
							system("mode con cols=48 lines=13");
							data = obj[atoi(temp.c_str()) - 1]; // (-1)!!
							cout << "     " << data[0];
							cout << "\n Адрес    : " << data[1];
							cout << "\n Стоимость: " << data[2];
							cout << "\n Тип      : " << data[3];
							cout << "\n Владелец : " << data[4];
							cout << "\n Комнат   : " << data[5];
							cout << "\n Этажей   : " << data[6];

							temp2 = data[4];
							for (int i = 0; i < user.getsize(); i++)
							{
								data = user[i];
								if (data[0] == temp2)
								{
									break;
								}
							}
							cout << "\n Вы можете позвонить владельцу\n по номеру: " << data[7];
							cout << "\n\n 1. Информация о владельце   2. Купить\n 0. Назад\n >";
							getline(cin, x);
							cin.clear();
						} while (!ONE_or_TWO(x) && !(x == "0"));

						if (x == "1")
						{
							system("cls");
							cout << "\n      Профиль " << data[0];
							cout << "\n Фамилия : " << data[3];
							cout << "\n Имя     : " << data[4];
							cout << "\n Отчество: " << data[5];
							cout << "\n Дата ржд: " << data[6];
							cout << "\n Номер   : " << data[7];
							cout << "\n Город   : " << data[8] << endl << endl;
							system("pause");
						}

						if (x == "2")//купить
						{
							system("cls");
							seller = data[0];
							data = user[currentuser];
							buyer = data[0];
							data = obj[atoi(temp.c_str()) - 1];

							day = st.wDay;
							month = st.wMonth;
							year = st.wYear;

							if (day < 10)
							{
								date = "0" + to_string(day) + ".";
							}
							else
							{
								date = to_string(day) + ".";
							}

							if (month < 10)
							{
								date += "0" + to_string(month) + ".";
							}
							else
							{
								date += to_string(month) + ".";
							}

							date += to_string(year);

							deals.push_front(seller, buyer, data[2], data[0], data[1], "В_процессе", date, "-", "-");
							cout << "\n Заявка отправлена владельцу\n Ожидайте подтверждения\n Если владелец подтвердит - объект ваш.\n\n";
							system("pause");
							
							deals.fileout_data("data\\deals.txt");
						}

						if (x == "0")
						{
							break;
						}

					} while (true);

				} while (true);

				if (x == "0")
				{
					break;
				}
			} while (true);

			system("mode con cols=48 lines=13");
			break;
		case 3:
			data = user[currentuser];
			temp2 = data[0];
			do
			{

				do
				{
					system("cls");
					lines = 0;
					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if (data[0] == temp2)
						{
							lines += 1;
						}
					}

					GetConsoleScreenBufferInfo(hConsole, &csbi); //полоска прокрутки
					csbi.dwSize.Y = lines + 4;
					SetConsoleScreenBufferSize(hConsole, csbi.dwSize);

					day = 0;
					cout << "      Список ваших клиентов\n";
					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if (data[0] == temp2 && data[5] == "Завершена")
						{
							day++;
							dealsIndex[day] = i;
							cout << "\n " << day << ". " << data[1];
						}
					}
					if (day == 0)
					{
						cout << "\n У вас нету клиентов";
					}
					cout << "\n\n Подробней (0 - назад)\n >";
					getline(cin, x);
					cin.clear();
				} while ((atoi(x.c_str()) > day || atoi(x.c_str()) < 0) || !valid_numbers(x));
				
				if (x == "0")
				{
					break;
				}

				data = deals[dealsIndex[atoi(x.c_str())]];
				temp = data[1];
				for (int i = 0; i < user.getsize(); i++)
				{
					data = user[i];
					if (data[0] == temp)
					{
						break;
					}
				}

				do
				{
					system("cls");
					cout << "\n\n Логин   : " << data[0];
					cout << "\n Фамилия : " << data[3];
					cout << "\n Имя     : " << data[4];
					cout << "\n Отчиство: " << data[5];
					cout << "\n Дата ржд: " << data[6];
					cout << "\n Номер   : " << data[7];
					cout << "\n Город   : " << data[8] << endl;
					cout << "\n Позвоните этому пользователю\n проконсультируйте его по вопросам";
					cout << "\n 0. Назад\n >";
					getline(cin, temp);
					cin.clear();
				} while (temp != "0");

			} while (true);
			
			

			break;
		case 4:

			system("cls");
			day = obj.getsize();
			register_obj(obj, data[0]);
			cout << "\n Объект выставлен на продажу,\n Ожидайте заявки в разделе 'Текущие сделки'\n\n";
			if (day != obj.getsize())
			{
				system("pause");
			}

			break;
		case 5:

			system("cls");
			ret = true;
			data = user[currentuser];
			temp2 = data[0];

			do
			{
				do
				{
					lines = 0;
					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if (data[0] == temp2 || data[1] == temp2 && data[5] == "В_процессе")
						{
							lines += 11;
						}
					}

					 
					GetConsoleScreenBufferInfo(hConsole, &csbi);
					csbi.dwSize.Y = lines;
					SetConsoleScreenBufferSize(hConsole, csbi.dwSize);

					day = 0;

					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if ((data[0] == temp2 || data[1] == temp2) && data[5] == "В_процессе")
						{
							day++;
							dealsIndex[day] = i;
							cout << "\n\n Продавец          : " << data[0];
							cout << "\n Покупатель        : " << data[1];
							if (data[2] != "-")
							{
								cout << "\n Стоимость операции: " << data[2];
							}
							cout << "\n Объект продажи    : " << data[3];
							if (data[4] != "-")
							{
								cout << "\n Адрес             : " << data[4];
							}
							cout << "\n Дата              : " << data[6];
							cout << "\n Этап сделки -> " << data[5];
							cout << "\n   " << day << ". Подтвердить / подробней" << endl << endl;
						}
					}

					if (day == 0)
					{
						cout << "\n У вас нету текущих сделок\n\n";
					}

					cout << " Вы можете подтвердить сделки выбрав номер";
					cout << "\n Введите номер (0 - назад)\n >";
					getline(cin, x);
					cin.clear();
					system("cls");
				} while ((atoi(x.c_str()) > day || atoi(x.c_str()) < 0) || !valid_numbers(x));

				if (x == "0")
				{
					break;
				}

				system("mode con cols=48 lines=13");

				do // подробней / подтвердить
				{
					data = deals[dealsIndex[atoi(x.c_str())]];

					cout << "\n\n Продавец          : " << data[0];
					cout << "\n Покупатель        : " << data[1];
					if (data[2] != "-")
					{
						cout << "\n Стоимость операции: " << data[2];
					}
					cout << "\n Объект продажи    : " << data[3];
					if (data[4] != "-")
					{
						cout << "\n Адрес             : " << data[4];
					}
					cout << "\n Дата              : " << data[6];
					cout << "\n Этап сделки -> " << data[5];


					if (data[5] == "В_процессе" && data[0] == temp2)
					{
						cout << "\n\n 1. Подтвердить  2. Отклонить  0. Назад\n >";
						getline(cin, temp);
						cin.clear();
						system("cls");
					}
					else
					{

						cout << "\n\n 0 - назад\n >";
						getline(cin, temp);
						cin.clear();
						system("cls");
						if (temp == "1" || temp == "2")
						{
							temp = "0";
						}

					}

				} while (!ONE_or_TWO(temp) && !(temp == "0"));

				if (temp == "1")
				{
					if (data[4] == "-")
					{
						deals.push_back(data[0], data[1], data[2], data[3], data[4], "Завершена", getSystemTime(), data[7], data[8]);
						deals.removeAt(dealsIndex[atoi(x.c_str())]);
						cout << "\n Сделка завершена,\n Этот клиент в вашей клиентской базе\n\n";
						system("pause");
					}
					else if (data[4] != "-")
					{
						temp = data[1];
						seller = data[3];
						deals.push_back(data[0], data[1], data[2], data[3], data[4], "Завершена", getSystemTime(), data[7], data[8]);
						deals.removeAt(dealsIndex[atoi(x.c_str())]);
						for (int i = 0; i < obj.getsize(); i++)
						{
							data = obj[i];
							if (data[0] == seller)
							{
								day = i;
								break;
							}
						}

						obj.push_back(data[0], data[1], data[2], data[3], temp, data[5], data[6], data[7], data[8]);

						obj.removeAt(day);

						cout << "\n Обьект передан пользователю " << temp << ",";
						cout << "\n Сделка завершена\n\n";
						system("pause");
						break;
					}

					obj.fileout_data("data\\objects.txt");
					deals.fileout_data("data\\deals.txt");
				}

				if (temp == "2")
				{

					deals.push_back(data[0], data[1], data[2], data[3], data[4], "Отклонена", getSystemTime(), data[7], data[8]);

					deals.removeAt(dealsIndex[atoi(x.c_str())]);

					deals.fileout_data("data\\deals.txt");

				}

			} while (ret);

			system("mode con cols=48 lines=13");

			break;
		case 6: // Моя недвижимость

			system("cls");
			data = user[currentuser];
			temp2 = data[0];

			do
			{
				do
				{
					lines = 0;
					for (int i = 0; i < obj.getsize(); i++)
					{
						data = obj[i];
						if (temp2 == data[4])
						{
							lines += 11;
						}
					}

					 
					GetConsoleScreenBufferInfo(hConsole, &csbi);
					csbi.dwSize.Y = lines;
					SetConsoleScreenBufferSize(hConsole, csbi.dwSize);

					day = 0;

					for (int i = 0; i < obj.getsize(); i++)
					{
						data = obj[i];
						if (data[4] == temp2)
						{
							day++;
							objIndex[day] = i;
							cout << "\n     " << data[0];
							cout << "\n Адрес    : " << data[1];
							cout << "\n Стоимость: " << data[2];
							cout << "\n Тип      : " << data[3];
							cout << "\n Владелец : " << data[4];
							cout << "\n Комнат   : " << data[5];
							cout << "\n Этажей   : " << data[6];
							cout << "\n  " << day << ". Подробней / Редактировать" << endl << endl;
						}
					}

					if (day == 0)
					{
						cout << "\n У вас нету недвижимости\n";
					}

					cout << "\n Введите что-нибудь (0 - назад)\n >";
					getline(cin, x);
					cin.clear();
					system("cls");

				} while ((atoi(x.c_str()) > day || atoi(x.c_str()) < 0) || !valid_numbers(x));

				if (x == "0")
				{
					system("mode con cols=48 lines=13");
					break;
				}

				system("mode con cols=48 lines=13");

				do
				{
					system("cls");
					data = obj[objIndex[atoi(x.c_str())]];
					cout << "\n\n     " << data[0];
					cout << "\n Адрес    : " << data[1];
					cout << "\n Стоимость: " << data[2];
					cout << "\n Тип      : " << data[3];
					cout << "\n Владелец : " << data[4];
					cout << "\n Комнат   : " << data[5];
					cout << "\n Этажей   : " << data[6];
					cout << "\n\n 1. Редактировать 0. Назад\n >";

					getline(cin, temp);
					cin.clear();

					if (temp == "1")
					{
						edit_obj(obj, objIndex[atoi(x.c_str())]);
						temp = "";
					}

					if (temp == "2")
					{
						temp = "";
					}


				} while (!ONE_or_TWO(temp) && !(temp == "0"));

			} while (true);


			system("mode con cols=48 lines=13");

			break;
		case 7:

			system("cls");
			ret = true;
			data = user[currentuser];
			temp2 = data[0];

			do
			{
				do
				{
					lines = 0;
					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if (data[0] == temp2 || data[1] == temp2)
						{
							lines += 11;
						}
					}

					 
					GetConsoleScreenBufferInfo(hConsole, &csbi);
					csbi.dwSize.Y = lines+4;
					SetConsoleScreenBufferSize(hConsole, csbi.dwSize);

					day = 0;

					for (int i = 0; i < deals.getsize(); i++)
					{
						data = deals[i];
						if (data[0] == temp2 || data[1] == temp2)
						{
							day++;
							dealsIndex[day] = i;
							cout << "\n\n Продавец          : " << data[0];
							cout << "\n Покупатель        : " << data[1];
							if (data[2] != "-")
							{
								cout << "\n Стоимость операции: " << data[2];
							}
							cout << "\n Объект продажи    : " << data[3];
							if (data[4] != "-")
							{
								cout << "\n Адрес             : " << data[4];
							}
							cout << "\n Дата              : " << data[6];
							cout << "\n Этап сделки -> " << data[5];
							cout << "\n   " << day << ". Подробней" << endl << endl;
						}
					}

					if (day == 0)
					{
						cout << "\n Вы не совершали сделок\n";
					}

					cout << "\n Введите номер (0 - назад)\n >";
					getline(cin, x);
					cin.clear();
					system("cls");
				} while ((atoi(x.c_str()) > day || atoi(x.c_str()) < 0) || !valid_numbers(x));

				if (x == "0")
				{
					break;
					system("mode con cols=48 lines=13");
				}

				system("mode con cols=48 lines=13");

				do // подробней / подтвердить
				{
					data = deals[dealsIndex[atoi(x.c_str())]];

					cout << "\n\n Продавец          : " << data[0];
					cout << "\n Покупатель        : " << data[1];
					if (data[2] != "-")
					{
						cout << "\n Стоимость операции: " << data[2];
					}
					cout << "\n Объект продажи    : " << data[3];
					if (data[4] != "-")
					{
						cout << "\n Адрес             : " << data[4];
					}
					cout << "\n Дата              : " << data[6];
					cout << "\n Этап сделки -> " << data[5];


					cout << "\n\n 0 - назад\n >";
					getline(cin, temp);
					cin.clear();
					system("cls");
					if (temp == "1" || temp == "2")
					{
						temp = "0";
					}


				} while (temp != "0");

			} while (ret);

			system("mode con cols=48 lines=13");

			break;
		case 8:

			do
			{
				system("cls");
				cout << "      Настройки темы";
				cout << "\n\n 1. По умолчанию";
				cout << "\n 2. MS-DOS";
				cout << "\n 3. Norton";
				cout << "\n 4. Чёрным по белому";
				cout << "\n 5. Матрица";
				cout << "\n 6. Персик";
				cout << "\n 0. Назад";
				cout << "\n\n >";
				getline(cin, x);
				cin.clear();
				switch (atoi(x.c_str()))
				{
				case 1:
					system("color 87");// по умолчанию
					break;
				case 2:
					system("color 07");//мс-дос
					break;
				case 3:
					system("color 1B"); // нортон
					break;
				case 4:
					system("color F0");//чёрным по белому
					break;
				case 5:
					system("color 0A");//матрица
					break;
				case 6:
					system("color E5");// персик
					break;
				default:
					break;
				}

				if (x == "0")
				{
					break;
				}

			} while (true);

			break;
		case 0:
			ret = false;
			break;
		default:
			break;
		}
	} while (ret);
};