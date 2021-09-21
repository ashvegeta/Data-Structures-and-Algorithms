#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>

#define max_size 256
#define table_size 10
#define deleted_entry (person*) (0xFFFFFFFFFFFFFUL)

typedef struct //defining hash table type
{
    char name[max_size];
    int age;
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
        if(hash_table[i]==NULL || hash_table[i]==deleted_entry)
        printf("\t%d ----> -------\n",i);
        else
        printf("\t%d ----> %s\n",i,hash_table[i]->name);
    }

    printf("END\n");
}

bool insert(person* p)
{
    if(p==NULL) return false;

    int index = hash_function(p->name);

    for(int i=0;i<table_size;i++) // linear probing to avoid collisions
    {
        int new_index = (index + i) % table_size;
        
        if(hash_table[new_index]==NULL || hash_table[new_index]==deleted_entry)
        {
            hash_table[new_index] = p;
            return true;
        }
    }

    return false; // return false if the hash table is full
}

person* delete(char* name)
{
    int index = hash_function(name);

    for(int i=0;i<table_size;i++)
    {
        int curr_index = (index + i) % table_size;

        if(hash_table[index]==NULL) return NULL; // the key doesnt exist in table to delete ; so return NULL

        if(hash_table[index]==deleted_entry) continue; // if there was a deleted entry , the key could still exist in the table

        if(hash_table[curr_index]!=NULL && strncmp(name,hash_table[curr_index]->name,strlen(name))==0)
        {
            person* temp = hash_table[curr_index]; // save data before deleting
            hash_table[curr_index] = deleted_entry;
            return temp;
        }
    }

    return NULL;
}

person* find(char* name)
{
    int index = hash_function(name);

    for(int i=0;i<table_size;i++)
    {
        int curr_idx = (index + i) % table_size;

        if(hash_table[curr_idx]==NULL) return NULL; // value doesnt exist to find

        if(hash_table[curr_idx]==deleted_entry) continue; // value may exist

        if(hash_table[curr_idx]!=NULL && strncmp(hash_table[curr_idx]->name,name,strlen(name))==0) 
        return hash_table[index];
    }

    return NULL;
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

    return 0;
}
