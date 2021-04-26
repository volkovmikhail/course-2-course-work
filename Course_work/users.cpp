#include "users.h"

void register_user(list & user)
{

	SYSTEMTIME st;
	GetSystemTime(&st);
	string year;

	bool valid = false;
	string login, password1, password2, type, F, I, O, date, num, city;
	string* unique_login = new string[9];

	system("cls");

	do
	{
		valid = false;
		cout << "\n Введите логин (0 - назад)\n >";
		getline(cin, login, '\n');
		cin.clear();

		if (login == "0")
		{
			return;
		}

		for (int i = 0; i < user.getsize(); i++)
		{
			unique_login = user[i];
			if (unique_login[0] == login || login == "admin")
			{
				valid = true;
			}
		}
		cin.clear();
		system("cls");
		if (valid == true)
		{
			cout << " Такой логин уже существует:";
		}
	} while (!valid_zeroLen(login) || valid);

	do
	{

		cout << "\n Введите пароль\n >"; 
		getline(cin, password1, '\n');
		cin.clear();
		cout << "\n Подтвердите пароль\n >";
		getline(cin, password2, '\n');
		cin.clear();
		system("cls");
	} while (!valid_password(password1, password2));

	do
	{
		system("cls");
		cout << "\n Вы агент или клиент?\n 1. Клиент\t2. Агент\n >";
		getline(cin, type, '\n');
		cin.clear();
	} while (!ONE_or_TWO(type));
	if (type == "1")
	{
		type = "Клиент";
	}
	else
	{
		type = "Агент";
	}

	system("cls");
	do
	{
		cout << "\n Введите фамилию\n >";
		getline(cin, F, '\n');
		cin.clear();
		system("cls");
	} while (!valid_name(F));

	system("cls");
	do
	{
		cout << "\n Введите имя\n >";
		getline(cin, I, '\n');
		cin.clear();
		system("cls");
	} while (!valid_name(I));

	system("cls");
	do
	{

		cout << "\n Введите отчиство\n >";
		getline(cin, O, '\n');
		cin.clear();
		system("cls");
	} while (!valid_name(O));

	system("cls");
	do
	{
		cout << "\n Введите дату рождения [ДД.ММ.ГГГГ]\n >";
		getline(cin, date, '\n');
		cin.clear();
		system("cls");
		if (date.length() < 10) 
		{
			cout << " Неверный формат даты:";
			continue;
		}
		year = date.substr(6, 4);
		if (atoi(year.c_str()) > st.wYear - 17)
		{
			cout << " Вам должно быть больше 18 лет";
			date = "";
		}

	} while (!valid_date(date));

	system("cls");
	do
	{										
		cout << "\n Введите номер телефона\n >";
		getline(cin, num, '\n');
		cin.clear();
		system("cls");
	} while (!valid_numbers(num));

	system("cls");
	do
	{
		cout << "\n Введите город в котором вы проживаете\n >";
		getline(cin, city, '\n');
		cin.clear();
		system("cls");
	} while (!valid_not_numbers(city));
	system("cls");

	user.push_front(login, password1, type, F, I, O, date, num, city);
	sortFIO(user);
	user.fileout_data("data\\users.txt");
}

void sortFIO(list& user)
{
	string* arr = new string[9];
	string tempstr;
	char fio[3];
	char fio2[3];

	for (int i = 1; i < user.getsize(); ++i)
	{
		for (int j = 0; j < user.getsize() - 1; j++)
		{
			arr = user[j];
			tempstr = arr[3];
			fio[0] = tempstr[0];
			tempstr = arr[4];
			fio[1] = tempstr[0];
			tempstr = arr[5];
			fio[2] = tempstr[0];

			arr = user[j+1];
			tempstr = arr[3];
			fio2[0] = tempstr[0];
			tempstr = arr[4];
			fio2[1] = tempstr[0];
			tempstr = arr[5];
			fio2[2] = tempstr[0];

			if (strcmp(fio,fio2)>0)
			{
				arr = user[j];
				user.insert(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], j+2);
				user.removeAt(j);
			}
		}
	}
}

void edit_user(list& user, int currentuser)
{
	string temp;
	bool next;
	string x,changed;
	string* userdata = new string[9];
	while (true)
	{
	userdata = user[currentuser];
		system("cls");
		cout << "      Режим редактирования";
		cout << "\n 1. Логин   : " << userdata[0];
		cout << "\n 2. Фамилия : " << userdata[3];
		cout << "\n 3. Имя     : " << userdata[4];
		cout << "\n 4. Отчиство: " << userdata[5];
		cout << "\n 5. Дата ржд: " << userdata[6];
		cout << "\n 6. Номер   : " << userdata[7];
		cout << "\n 7. Город   : " << userdata[8];
		cout << "\n 8. Изменить пороль\n\n";
		cout << " Какой пункт изменить? (0 - назад)\n >";
		getline(cin, x);
		cin.clear();
		switch (atoi(x.c_str()))
		{
		case 0:
			return;
		case 1:
			system("cls");
			cout << "\n Логин изменить нельзя :)\n\n";
			system("pause");
			break;
		case 2:
			system("cls");
			do
			{
				cout << "\n Введите фамилию (0 - назад)\n >";
				getline(cin, changed);
				cin.clear();
				if (changed == "0")
				{
					break;
				}
				system("CLS");
			} while (!valid_name(changed) && !(changed == "0"));
			
			if (changed == "0")
			{
				break;
			}
			user.insert(userdata[0], userdata[1], userdata[2], changed, userdata[4], userdata[5], userdata[6], userdata[7], userdata[8],currentuser);
			user.removeAt(currentuser+1);

			break;
		case 3:
			system("cls");
			do
			{
				cout << "\n Введите имя (0 - назад)\n >";
				getline(cin, changed);
				cin.clear();
				if (changed == "0")
				{
					break;
				}
				system("CLS");
			} while (!valid_name(changed) && !(changed == "0"));

			if (changed == "0")
			{
				break;
			}
			user.insert(userdata[0], userdata[1], userdata[2], userdata[3], changed , userdata[5], userdata[6], userdata[7], userdata[8], currentuser);
			user.removeAt(currentuser + 1);
			break;
		case 4:
			system("cls");
			do
			{
				cout << "\n Введите отчиство (0 - назад)\n >";
				getline(cin, changed);
				cin.clear();
				if (changed == "0")
				{
					break;
				}
				system("CLS");
			} while (!valid_name(changed) && !(changed == "0"));

			if (changed == "0")
			{
				break;
			}
			user.insert(userdata[0], userdata[1], userdata[2], userdata[3], userdata[4], changed, userdata[6], userdata[7], userdata[8], currentuser);
			user.removeAt(currentuser + 1);
			break;
		case 5:
			system("cls");
			do
			{
				cout << "\n Введите дату рождения [ДД.ММ.ГГГГ] (0 - назад)\n >";
				getline(cin, changed);
				cin.clear();
				if (changed == "0")
				{
					break;
				}
				system("CLS");
			} while (!valid_date(changed) && !(changed == "0"));

			if (changed == "0")
			{
				break;
			}
			user.insert(userdata[0], userdata[1], userdata[2], userdata[3], userdata[4], userdata[5], changed, userdata[7], userdata[8], currentuser);
			user.removeAt(currentuser + 1);
			break;
		case 6:
			system("cls");
			do
			{
				cout << "\n Введите номер телефона (0 - назад)\n >";
				getline(cin, changed);
				cin.clear();
				if (changed == "0")
				{
					break;
				}
				system("CLS");
			} while (!valid_numbers(changed) && !(changed == "0"));

			if (changed == "0")
			{
				break;
			}
			user.insert(userdata[0], userdata[1], userdata[2], userdata[3], userdata[4], userdata[5], userdata[6], changed, userdata[8], currentuser);
			user.removeAt(currentuser + 1);
			break;
		case 7:
			system("cls");
			do
			{
				cout << "\n Введите город проживания (0 - назад)\n >";
				getline(cin, changed);
				cin.clear();
				if (changed == "0")
				{
					break;
				}
				system("CLS");
			} while (!valid_not_numbers(changed) && !(changed == "0"));

			if (changed == "0")
			{
				break;
			}
			user.insert(userdata[0], userdata[1], userdata[2], userdata[3], userdata[4], userdata[5], userdata[6], userdata[7], changed, currentuser);
			user.removeAt(currentuser + 1);
			break;
		case 8:
			system("cls");
			next = true;
			do
			{
				while(next)
				{
					cout << "\n Введите текущий пороль (0 - назад)\n >";
					getline(cin, changed);
					cin.clear();
					if (changed == "0")
					{
						break;
						next = false;
					}
					system("CLS");
					if (valid_password(userdata[1],changed))
					{
						next = false;
					}
				};
				if (changed == "0")
				{
					break;
				}

				cout << "\n Введите новый пароль\n >";
				getline(cin, changed, '\n');
				cin.clear();
				cout << "\n Подтвердите пароль\n >";
				getline(cin, temp, '\n');
				cin.clear();
				system("cls");

			} while (!valid_password(changed,temp));

			if (changed == "0")
			{
				break;
			}
			user.insert(userdata[0], changed, userdata[2], userdata[3], userdata[4], userdata[5], userdata[6], userdata[7], userdata[8], currentuser);
			user.removeAt(currentuser + 1);
			break;
		default:
			break;
		}
		user.fileout_data("data\\users.txt");
	}
}