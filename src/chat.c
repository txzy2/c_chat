#include "../include/chat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool init_chat(Chat* c, const char* title)
{
    if (!c || !title) return false;

    strncpy(c->title, title, CHAT_TITLE_LEN - 1);
    c->title[CHAT_TITLE_LEN - 1] = '\0';

    vector_init(&c->users, sizeof(User*));
    c->id = 1;

    return true;
}

bool find_user(Chat* c, const int id)
{
    if (!c)
    {
        return false;
    }

    for (size_t i = 0; i < c->users.size; i++)
    {
        User** u = (User**)vector_get(&c->users, i);
        if ((*u)->id == id)
        {
            return true;
        }
    }

    return false;
}

bool add_user_to_chat(Chat* c, User* u)
{
    if (!c || !u) { return false; }
    if (find_user(c, u->id)) { return false; }

    vector_push(&c->users, &u);

    return true;
}

void free_chat(Chat* c)
{
    if (c == NULL)
    {
        return;
    }

    vector_free(&c->users);
    c->id = 0;
}

void print_user(const User* u)
{
    if (u == NULL)
    {
        return;
    }

    printf("> ID: %d NAME: %s (EMAIL: %s)\n", u->id, u->name, u->email);
}
