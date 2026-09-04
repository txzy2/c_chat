#ifndef TEST_C_CHAT_MESSAGE_H
#define TEST_C_CHAT_MESSAGE_H

#include "types.h"
#include "chat.h"
#include "vector.h"

typedef struct {
    int id;
    char text[CHAT_MSG_LEN];

    Chat* chat;
    User* from;
    User* to;
} ChatMessage;

typedef struct {
    Vector v;
} ChatMsgVec;

bool init_chat_msg_vec(ChatMsgVec* chmsvc);
bool push_msg_to_vec(ChatMsgVec* chmsvc, ChatMessage* msg);
ChatMessage* get_msg_from_vec(ChatMsgVec* chmsvc, size_t index);
void free_chat_msg_vec(ChatMsgVec* chmsvc);

#endif //TEST_C_CHAT_MESSAGE_H
