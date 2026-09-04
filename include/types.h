//
// Created by kamaev on 9/4/26.
//

#ifndef TEST_C_TYPES_H
#define TEST_C_TYPES_H

#define NAME_LEN  32
#define EMAIL_LEN 60

#define CHAT_MSG_LEN   1024
#define CHAT_TITLE_LEN 50

typedef struct
{
    int id;
    char name[NAME_LEN];
    char email[EMAIL_LEN];
} User;

#endif //TEST_C_TYPES_H
