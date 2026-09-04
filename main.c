#include <stdio.h>

#include "include/chat.h"
#include "include/types.h"
#include "include/chat_message.h"

#define LEN(x) sizeof(x) / sizeof(x[0])

int main()
{
    User users[] = {
        {.id = 1, .name = "ANTON", .email = "email@email.ru"},
        {.id = 2, .name = "DIMA", .email = "dima@dima.ru"},
    };

    Chat c;
    init_chat(&c, "Диалог 1");
    //TODO: Инициализировать вектор сообщений

    for (size_t i = 0; i < LEN(users); i++)
    {
        if (!add_user_to_chat(&c, &users[i]))
        {
            return 1;
        }
    }

    printf("Chat %s (ID: %d)\n", c.title, c.id);
    for (size_t i = 0; i < c.size; i++)
    {
        print_user(c.users[i]);
    }

    ChatMessage msg = {.id = 1, .text = "Test Message", .chat = &c, .from = &users[0], .to = &users[1]};
    //TODO: Добавить логику пуша в вектор

    free_chat(&c);
    return 0;
}
