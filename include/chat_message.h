//
// Created by kamaev on 9/4/26.
//

#ifndef TEST_C_CHAT_MESSAGE_H
#define TEST_C_CHAT_MESSAGE_H

#include "types.h"
#include "chat.h"

typedef struct
{
    int id;
    char text[CHAT_MSG_LEN];

    Chat* chat;

    User* from;
    User* to;
} ChatMessage;

typedef struct
{
    ChatMessage** msgs;
    int size;
    int capacity;
} ChatMsgVec;

bool init_chat_msg_vec(ChatMsgVec* chmsvc);

bool push_msg_to_vec(ChatMsgVec* chmsvc, ChatMessage* msg);

void free_chat_msg_vec(ChatMsgVec* chmsvc);

#endif //TEST_C_CHAT_MESSAGE_H
