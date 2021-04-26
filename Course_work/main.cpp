#pragma once
#include "list.cpp"
#include "users.h"
#include "Menues.h"
#include <sys/stat.h>
#include "resource.h"

int main()
{
	system("color 87");

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	list user, obj, deals;

	system("mode con cols=48 lines=13");

	struct stat buff;
	if (stat("data", &buff))
	{
		MessageBox(NULL, L"База данных не найдена\nПапка 'data' создана в каталоге программы",L"Ошибка", MB_OK | MB_ICONERROR);
		system("mkdir data");
		cout << "make dir";
	}

	obj.load_data("data\\objects.txt");
	user.load_data("data\\users.txt");
	deals.load_data("data\\deals.txt");

	string reg_or_login;
	bool exit = true;
	do
	{
		system("mode con cols=48 lines=13");
		system("title Вход/Регистрация");
		system("cls");
		do
		{
			cout<<"\n\n               ___   /=/                        ";
			cout << "\n               |||   |||    _                   ";
			cout << "\n   ___    _    |||   |||   |||    _    __|_   _ ";
			cout << "\n _ |||_  |=| _ |||_  ||| _ |||_  ||| _ |==|  |||";
			cout << "\n| |||||_ |=|| |||||_ |||| |||||_ |||| ||==|_ |||";
			cout << "\n|_|||||_||=||_|||||_|||||_|||||_|||||_||==|_||||";
			cout << "\n Приветствуем вас в агенстве недвижимости WOLF!";
			cout << "\n\n 1. Вход  2. Регистрация  3. Справка  0. Закрыть\n >";

			getline(cin, reg_or_login);
			system("cls");
		} while (!ONE_or_TWO(reg_or_login) && !(reg_or_login == "0") && reg_or_login != "3");
		switch (atoi(reg_or_login.c_str()))
		{
		case 1:
			user_menu(user,obj,deals, exit);
			break;
		case 2:
			register_user(user);
			break;
		case 3:
			system("cls");

			cout << "\n Разработал: Волков Михаил Юрьевич";
			cout << "\n Агенство недвижимости 'WOLF'";
			cout << "\n\n МГКЭ Минск 2020\n\n\n";

			system("pause");
			break;
		case 0:
			system("cls");
			exit = false;
			break;
		default:
			break;
		}
	} while (exit);
	
	user.fileout_data("data\\users.txt");
	obj.fileout_data("data\\objects.txt");
	deals.fileout_data("data\\deals.txt");

	cout << "\n\n";
	return 0;
}