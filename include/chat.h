//
// Created by kamaev on 9/4/26.
//

#ifndef TEST_C_CHAT_H
#define TEST_C_CHAT_H

#include "types.h"
#include "vector.h"

typedef struct
{
    int id;
    char title[CHAT_TITLE_LEN];

    Vector users;
} Chat;

bool init_chat(Chat* c, const char* title);

bool find_user(Chat* c, int id);

void free_chat(Chat* c);

bool add_user_to_chat(Chat* c, User* u);

void print_user(const User* u);

#endif //TEST_C_CHAT_H
