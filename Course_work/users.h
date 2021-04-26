#pragma once
#ifndef USERS_H
#define USERS_H
#include "list.cpp"
#include "validData.h"
#include <conio.h>

void register_user(list & user);
void edit_user(list& user, int currentuser);
void sortFIO(list& user);

#endif
