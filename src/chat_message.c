#include "../include/chat_message.h"

bool init_chat_msg_vec(ChatMsgVec* chmsvc) {
    vector_init(&chmsvc->v, sizeof(ChatMessage*));
    return true;
}

bool push_msg_to_vec(ChatMsgVec* chmsvc, ChatMessage* msg) {
    vector_push(&chmsvc->v, &msg); // обратите внимание: передаём &msg, а не msg
    return true;
}

ChatMessage* get_msg_from_vec(const ChatMsgVec * chmsvc, const size_t index) {
    ChatMessage** ptr = vector_get(&chmsvc->v, index);
    return *ptr;
}

void free_chat_msg_vec(ChatMsgVec* chmsvc) {
    vector_free(&chmsvc->v);
}