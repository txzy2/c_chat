#include <stdio.h>

#include "include/chat.h"
#include "include/types.h"
#include "include/chat_message.h"
#include "include/vector.h"

#define LEN(x) sizeof(x) / sizeof(x[0])

int main()
{
    User users[] = {
        {.id = 1, .name = "ANTON", .email = "email@email.ru"},
        {.id = 2, .name = "DIMA", .email = "dima@dima.ru"},
    };

    Chat c;
    init_chat(&c, "Диалог 1");

    for (size_t i = 0; i < LEN(users); i++)
    {
        if (!add_user_to_chat(&c, &users[i]))
        {
            return 1;
        }
    }

    printf("Chat %s (ID: %d)\n", c.title, c.id);
    for (size_t i = 0; i < c.users.size; i++)
    {
        print_user(*(User**)vector_get(&c.users, i));
    }

    ChatMsgVec cmv;
    init_chat_msg_vec(&cmv);

    ChatMessage msg = {.id = 1, .text = "Test Message", .chat = &c, .from = &users[0], .to = &users[1]};
    push_msg_to_vec(&cmv, &msg);

    ChatMessage** msg_arr = (ChatMessage**)cmv.v.data;
    for (size_t i = 0; i < cmv.v.size; i++)
    {
        printf("ID: %d, text: %s", msg_arr[i]->id, msg_arr[i]->text);
    }

    free_chat(&c);
    free_chat_msg_vec(&cmv);
    return 0;
}
