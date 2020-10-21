#include <stdlib.h>
#include<stdio.h>
#include <string.h>
int CAPACITY = 8;
struct Entry {
    int key;
    char *value;
    struct Entry *next;
};

int getIndex(int key){
    return (key % CAPACITY);
}

void AddKeyandValue(struct Entry** hashtable, int key, char *value){
    int i = getIndex(key);
    //found
    struct Entry *tmp;
    tmp = hashtable[i];
    
    while(tmp!=NULL){//key is same, then update value
      if(tmp->key != key){
        tmp= tmp->next;
        }else{
          tmp->value = strdup(value);
          return;
          }
      }
    
    tmp = hashtable[i];
    while(tmp!=NULL){
        if(tmp->key == key){ //key is same, then update value
            tmp->value = strdup(value);
            return;
        }else{
            struct Entry* entry = malloc(sizeof(struct Entry));
            entry->key = key;
            entry->value = strdup(value);// value is count
            entry->next = NULL;
            while(tmp->next!=NULL){
              tmp = tmp->next;
            }  
            tmp->next =entry;
        }
          tmp= tmp->next;
    }
    //not found
    if(hashtable[i] == NULL){
        struct Entry* entry = malloc(sizeof(struct Entry));
        entry->key = key;
        entry->value = strdup(value);// value is count
        entry->next = NULL;
        hashtable[i] = entry;
    }
    free(tmp);
    
}

char *query(struct Entry** hashtable, int key){
    int i = getIndex(key);
    //found
    struct Entry *tmp;
    tmp = hashtable[i];
    while(tmp!=NULL){
        if(tmp->key == key){
            printf("sum = %s\n", tmp->value);
            return tmp->value;
        }
        tmp= tmp->next;
    }    
    return 0;
}

void Remove(struct Entry** hashtable, int key){
    int i = getIndex(key);
    struct Entry *tmp;
    tmp = hashtable[i];
    if(hashtable[i]->key ==key){
      hashtable[i] = tmp->next;
      }
    while(tmp!=NULL && tmp->next!=NULL){
      if(tmp->next->key == key){
        tmp->next = tmp->next->next;
        }else{
          tmp = tmp->next;
          }
      }
  }

int main(){
    struct Entry** hashtable = calloc(CAPACITY, sizeof(struct Entry*));
    //struct Entry** hashtable = malloc(CAPACITY * sizeof(struct Entry*));
    AddKeyandValue(hashtable, 10, "dog");
    //Remove(hashtable, 10);
    query(hashtable, 10);
    free(hashtable);
}