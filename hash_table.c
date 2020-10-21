// This file is used to count the number and store the value in the hashtable
//This hash table is implement the open addressing method
//key is number and value is number
//For example
/**
Used IncreaseOne function to count and query function to search the key
Input:
IncreaseOne(counter,1);
IncreaseOne(counter,1);
query(counter,1);

Output:
key = 1
count = 2

Used RemoveOne function to decrease the count
Input:
IncreaseOne(counter,1);
IncreaseOne(counter,1);
RemoveOne(counter,1);
query(counter,1);

Output:
key = 1
count = 1
**/
#include <stdlib.h>
#include<stdio.h>

int CAPACITY = 100000;
struct Entry {
    int key;
    int count;
};

int HashIndex(int key){
    return (key % CAPACITY + CAPACITY) % CAPACITY;
}
void IncreaseOne(struct Entry** counter, int key){
    int i = HashIndex(key);
    //found
    while(counter[i]!= NULL){
        if(counter[i]->key == key ){
        counter[i]->count++;//count+=1
        return;
        }else{
            i = HashIndex(i+1);
        }
    }

    //not found
    if(counter[i] == NULL){
        struct Entry* entry = malloc(sizeof(struct Entry));
        entry->key = key;
        entry->count = 1;
        counter[i] = entry;
    }
    
}

void RemoveOne(struct Entry** counter, int key){
    int i = HashIndex(key);
    //found
    while(counter[i]!= NULL){
        if(counter[i]->key == key ){
            if(counter[i]->count == 0){
                return;
            }else{
            counter[i]->count--;
            }
        return;
        }else{
            i = HashIndex(i+1);
        }
    }
}

int query(struct Entry** counter, int key){
    int i = HashIndex(key);
    while(counter[i] != NULL){
        if(counter[i]->key == key){
            printf("key = %d\n", counter[i]->count);
            return counter[i]->count;
        }
        i = HashIndex(i+1);
    }
    return 0;
}



int main(){
    struct Entry** counter = calloc(CAPACITY, sizeof(struct Entry*));
    //struct Entry** counter = malloc(CAPACITY * sizeof(struct Entry*));

    int one= 1;
    IncreaseOne(counter, one);
    int  two = 2;
    IncreaseOne(counter,two);
    IncreaseOne(counter,two);
    IncreaseOne(counter,two);
    query(counter,2);
    RemoveOne(counter,two);
    RemoveOne(counter,two);
    query(counter,2);
    free(counter);
}