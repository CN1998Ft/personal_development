#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    int set;
    int total;
} MapSet;
typedef struct {
  int key;
  char *val;
} Pair;

typedef struct {
  Pair *buckets[MAX_SIZE];
} ArrayHashMap;

ArrayHashMap *newArrayHashMap() {
  ArrayHashMap *hmap = malloc(sizeof(ArrayHashMap));
  for (int i = 0; i < MAX_SIZE; i++) {
    hmap->buckets[i] = NULL;
  }
  return hmap;
}

void delArrayHashMap(ArrayHashMap *hmap){
    for (int i = 0; i < MAX_SIZE; i++){
        if (hmap->buckets[i] != NULL){
            free(hmap->buckets[i]->val);
            free(hmap->buckets[i]);
        }
    }
    free(hmap);
}

void put(ArrayHashMap *hmap, const int key, const char *val){
    Pair *Pair = malloc(sizeof(Pair));
    Pair->key = key;
    Pair->val = malloc(strlen(val) + 1);
    strcpy(Pair->val, val);

    int index = hashFunc(key);
    hmap->buckets[index] = Pair;
}

void removeItem(ArrayHashMap *hmap, const int key){
    int index = hashFunc(key);
    free(hmap->buckets[index]->val);
    free(hmap->buckets[index]);
    hmap->buckets[index] = NULL;
}

void pairSet(ArrayHashMap *hmap, MapSet *set)
{
    Pair *entries;
    int i = 0, index = 0;
    int total = 0;
    for (i = 0; i < MAX_SIZE; i++){
        if (hmap->buckets[i] != NULL){
            total++;
        }
    }
    entries = malloc(sizeof(Pair) * total);
    for (i = 0; i < MAX_SIZE; i++){
        if (hmap->buckets[i] != NULL){
            entries[index].key = hmap->buckets[i]->key;
            entries[index].val = malloc(strlen(hmap->buckets[i]->val) + 1);
            strcpy(entries[index].val, hmap->buckets[i]->val);
            index++;
        }
    }
    set->set = entries;
    set->len = total;
}

void keySet(ArrayHashMap *hmap, MapSet *set)
{
    int *keys;
    int i = 0, index = 0;
    int total = 0;
    for (i = 0; i < MAX_SIZE; i++){
        if (hmap->buckets[i] != NULL){
            keys[index] = hmap->buckets[i]->key;
            index++;
        }
    }
    keys = malloc(total * sizeof(int));
    for (i = 0; i < MAX_SIZE; i++){
        keys[index] = hmap->buckets[i]->key;
        index++;
    }
    set->set = keys;
    set->len = total;
}

void valueSet(ArrayHashMap *hmap, MapSet *set){
    char **vals;
    int i = 0, index = 0;
    int total = 0;
    for (i = 0; i < MAX_SIZE; i++){
        if (hmap->buckets[i] != NULL) {
            total++;
        }
    }
    vals = malloc(total * sizeof(char *));
    for (i = 0; i < MAX_SIZE; i++) {
        if (hmap->buckets[i] != NULL){
            vals[index] = hmap->buckets[i]->val;
            index++;
        }
    }
    set->set = vals;
    set->len = total;
}

void print(ArrayHashMap *hmap) {
    int i;
    MapSet set;
    pairSet(hmap, &set);
    Pair *entries = (Pair *)set.set;
    for (i = 0; i < set.len; i++) {
        printf("%d -> %s\n", entries[i].key, entries[i].val);
    }
    free(set.set);
}

int main() {
    return 0;
}
