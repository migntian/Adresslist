#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>

#define MAX 3
#define NAME_LENGTH 20
#define SEX_LENGTH 5
#define AGE_LENGTH 3
#define TELE_LENGTH 20
#define ADDR_LENGTH 30

typedef struct user{
    char name[NAME_LENGTH];
    char sex[SEX_LENGTH];
    char age[AGE_LENGTH];
    char tele[TELE_LENGTH];
    char addr[ADDR_LENGTH];
}user;

typedef struct contacts{
    user *person;
    int user_count;
    int capacity;
}contacts;

enum op
{
    EXIT,
    ADD,
    ERASE,
    CLEAR,
    FID,
    MODIFY,
    SHOW,
    SORT
};

int add_contacts(contacts *men);
int erase_contacts(contacts *men);
int clear_contacts(contacts *men);
int find_contacts(contacts *men);
int remove_contacts(contacts *men);
void sort_contacts(contacts *men);
void check(contacts *men);
void menu();
