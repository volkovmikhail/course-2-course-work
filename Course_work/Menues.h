#pragma once
#ifndef MENUES_H
#define MENUES_H
#include "list.cpp"
#include "validData.h"
#include "users.h"
#include "objects.h"
#include "deals.h"

void user_menu(list& user,list & obj,list&deals, bool exit);
void admin_menu(list&user,list&obj,list&deals); //админ
void agent_menu(list& user, list& obj, list& deals, int currentuser);
void client_menu(list& user, list& obj, list& deals, int currentuser);

#endif

