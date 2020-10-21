#include <stdlib.h>
#include<stdio.h>
#include <string.h>
//This hash table is implement the open addressing method
// This file is used to insert key and value in the hashtable
//key is number and value is string
//CAPACITY value can be change to store large size data
//For example
/**
Used AddKeyandValue function to insert and query function to search the key
Input:
AddKeyandValue(hashtable, 1, "dog");
AddKeyandValue(hashtable, 2, "cat");
query(hashtable,1);
query(hashtable,2);

Output:
key = 1
value = dog
key = 2
value = cat

Used RemoveKeyandValue function to remove the key and value
Input:
AddKeyandValue(hashtable, 1, "dog");
AddKeyandValue(hashtable, 2, "cat");
RemoveKeyandValue(hashtable,2,cat);
query(hashtable,1);

Output:
key = 1
value = dog
**/
int CAPACITY = 100000;
struct Entry {
    int key;
    char *value;
};

//[0, CAPACITY]
int HashIndex(int key){
    return (key % CAPACITY + CAPACITY) % CAPACITY;
}
void AddKeyandValue(struct Entry** hashtable, int key, char *value){
    int i = HashIndex(key);
    //found
    while(hashtable[i]!= NULL){
        if(hashtable[i]->key == key ){
        hashtable[i]->value = strdup(value);//replace
        return;
        }else{
            i = HashIndex(i+1);
        }
    }

    //not found
    if(hashtable[i] == NULL){
        struct Entry* entry = malloc(sizeof(struct Entry));
        entry->key = key;
        entry->value = strdup(value);// replace
        hashtable[i] = entry;
    }
    
}
char *query(struct Entry** hashtable, int key){
    int i = HashIndex(key);
    while(hashtable[i] != NULL){
        if(hashtable[i]->key == key){
            printf("vlaue = %s\n", hashtable[i]->value);
            return hashtable[i]->value;
        }
        i = HashIndex(i+1);
    }
    return 0;
}


void RemoveKeyandValue(struct Entry** hashtable, int key){
    int i = HashIndex(key);
    //found
    while(hashtable[i]!= NULL){
        if(hashtable[i]->key == key ){
            if(hashtable[i]->value == 0){
                return;
            }else{
            hashtable[i]->key = 0;
            hashtable[i]->value = NULL;
            }
        return;
        }else{
            i = HashIndex(i+1);
        }
    }
}



int main(){
    struct Entry** hashtable = calloc(CAPACITY, sizeof(struct Entry*));
    //struct Entry** hashtable = malloc(CAPACITY * sizeof(struct Entry*));
    int one= 1;
    AddKeyandValue(hashtable, one, "dog");
    int  two = 2;
    AddKeyandValue(hashtable,two, "cat");
    
    query(hashtable,2);
    query(hashtable,1);
    free(hashtable);
}