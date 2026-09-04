#include "../include/chat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool init_chat(Chat* c, const char* title)
{
    if (!c || !title) return false;

    strncpy(c->title, title, CHAT_TITLE_LEN - 1);
    c->title[CHAT_TITLE_LEN - 1] = '\0';

    c->size = 0;
    c->capacity = 1;
    c->users = malloc(c->capacity * sizeof(*c->users));
    c->id = c->size == 0 ? 1 : c->size + 1;

    return c->users != NULL;
}

bool find_user(Chat* c, const int id)
{
    if (!c)
    {
        return false;
    }

    for (int i = 0; i < c->size; i++)
    {
        if (c->users[i]->id == id)
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

    if (c->size >= c->capacity)
    {
        const int new_capacity = c->capacity * 2;

        User** tmp = realloc(c->users, new_capacity * sizeof(*c->users));
        if (!tmp)
        {
            return false;
        }

        c->users = tmp;
        c->capacity = new_capacity;
    }

    c->users[c->size] = u;
    c->size++;

    return true;
}

void free_chat(Chat* c)
{
    if (c == NULL)
    {
        return;
    }

    free(c->users);
    c->users = NULL;
    c->size = c->capacity = c->id = 0;
}

void print_user(const User* u)
{
    if (u == NULL)
    {
        return;
    }

    printf("> ID: %d NAME: %s (EMAIL: %s)\n", u->id, u->name, u->email);
}
