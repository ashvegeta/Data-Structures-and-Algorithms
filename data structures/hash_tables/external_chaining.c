#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>

#define max_size 256
#define table_size 10

typedef struct person//defining hash table type
{
    char name[max_size];
    int age;
    struct person *next;
}person; 

person* hash_table[table_size]; // creating a hash table

void initialise_hash_table()
{
    for(int i=0;i<table_size;i++)
        hash_table[i] = NULL;
}

int hash_function(char* name)
{
    //return 5;  // simplest hash function

    int length = strnlen(name,max_size);
    int hash_val = 0;

    for(int i=0;i<length;i++)
    {
        hash_val+=(name[i] * (i+1));
    }

    return hash_val % table_size;
}

void print_hash_table()
{
    printf("\nSTART\n");

    for(int i=0;i<table_size;i++)
    {
        if(hash_table[i]==NULL)
            printf("\t%d ----> -------\n",i);

        else
        {
            person* head = hash_table[i];

            printf("\t%d ----> %s",i,head->name);
            head = head->next;

            while(head!=NULL)
            {
                printf(" --> %s",head->name);
                head = head->next;
            }
            printf("\n");
        
        }
    }

    printf("END\n");
}

bool insert(person* p)
{
    if(p==NULL) return false;

    int index = hash_function(p->name);

    p->next = hash_table[index]; // add the new element to the front of the list

    hash_table[index] = p; // p now constains the whole hash table with new entry added ; the new hash_table[index] will be p

    return true;
}

person* delete(char* name)
{
    int index = hash_function(name);
    person* head = hash_table[index];
    person* prev = NULL;

    while(head!=NULL && strncmp(name,head->name,strlen(name))!=0)
    {
        prev = head;
        head = head->next;
    }

    if(head==NULL) return NULL; // key not present to delete

    if(prev==NULL) hash_table[index] = head->next; // means the match is in the front of list

    else prev->next = head->next;// means the match is somewhere in the middle ; make the prev node point to the prev->next->next or head->next in the list

    return head;
}

person* find(char* name)
{
    int index = hash_function(name);
    person* head = hash_table[index];

    while(head!=NULL && strncmp(name,hash_table[index]->name,strlen(name))!=0)
    head = head->next;
    
    return head;
}

int main(int argc, char const *argv[])
{
    initialise_hash_table(); // intialize hash table

    person ashik = {.name="ashik" , .age = 20};
    person chinmay = {.name="chinmay" , .age = 21};
    person arun = {.name="arun" , .age = 21};
    person aravind = {.name="aravind" , .age = 21};

    // 1. insert operation
    insert(&ashik);
    insert(&chinmay);
    insert(&arun);
    insert(&aravind);

    print_hash_table();

    // 2 . find operation
    person* someone = find("samuel"); 

    if(someone==NULL)
    printf("\nperson %s not found !!\n","samuel");
    else
    printf("\nperson --> %s\n",someone->name);

    // 3. delete operation
    person* details = delete("chinmay");

    if(details==NULL)
    printf("\n\ncouldn't find or delete person with name %s\n\n","chinmay");
    else
    printf("\n\nsuccessfully deleted person with name %s\n\n","chinmay");

    print_hash_table();

    return 0;
}
