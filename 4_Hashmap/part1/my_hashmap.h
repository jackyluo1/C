// =================== Support Code =================
// Hashmap 
//
// - Implement each of the functions to create a working hashmap.
// - Do not change any of the function declarations
//   - (i.e. hashmap_t* hashmap_create() should not have additional arguments)
// - You should not have any 'printf' statements in your functions other 
//   than functions that explicitly ask for printf  output. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// - You may add any helper functions that you think you need (if any, or otherwise for debugging)
// ==================================================
#ifndef MY_HASHMAP_T
#define MY_HASHMAP_T

#include <stdlib.h>
#include <string.h>


// A key value pair
// This is specifically for a (char*, char*) key value pair
typedef struct pair{
    char* key;
    char* value;
}pair_t;

// Each node holds a key and a value
typedef struct node{
    struct node* next;
    pair_t* kv;          // 'kv' stands for key/value pair
}node_t;


// Simple hash function that will put a key into a bucket
// You should not modify this
int stringHash(char* myKey, int numberOfBuckets){
    return strlen(myKey) % numberOfBuckets;
}

// Create a function prototype to a function that takes
// in a char* and an int.
typedef int(*hashFunctionPointer)(char*,int) ; 

// Chained implementation of a hashmap
typedef struct hashmap{
    unsigned int buckets;   // i.e. size of the hashmap
    node_t** arrayOfLists;  // An array of linked lists for our buckets
                            // Read another way
                            //      - an array of node_t*

    // A function pointer to a hash function
    // The hash_function must take in a 'char*' as a key, and have a
    // second parameter specifying the number of buckets.
    hashFunctionPointer hashFunction;
}hashmap_t;

// Creates a new hashmap
// Allocates memory for a new hashmap.
// Initializes the capacity(i.e. number of buckets)
hashmap_t* hashmap_create(unsigned int _buckets){
    // Allocate memory for our hashmap
	//TODO
        hashmap_t* map = (hashmap_t*)malloc(sizeof(hashmap_t));
       
    // Set the number of buckets
	//TODO
	map-> buckets = _buckets; 
    // Initialize our array of lists for each bucket
	//TODO
	map->arrayOfLists = (node_t**)malloc(sizeof(node_t*)*_buckets);
	for(int i = 0; i < _buckets; i++){
          map->arrayOfLists[i] = NULL;
          
        } 
       	
    // Setup our hashFunction to point to our
    // stringHash function.
	//TODO
	map->hashFunction = 0;
    // Return the new map that we have created
    return map;
}

// Frees a hashmap
// Responsibility to free a hashmap that has been previously allocated.
// Must also free all of the chains in the hashmap
// This function should run in O(n) time
void hashmap_delete(hashmap_t* _hashmap){
   if(NULL == _hashmap) return ; 
   if(_hashmap != NULL){
	//TODO
      for(int i = 0; i < _hashmap->buckets; i++){
         node_t* pos;
        
         while(_hashmap->arrayOfLists[i] != NULL){      
             pos = _hashmap->arrayOfLists[i];
             _hashmap->arrayOfLists[i] = _hashmap->arrayOfLists[i]->next;
             printf("F");
             free(pos);
         } 
      }	     
   }
}
// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' if the hashmap is NULL
// The algorithm is:
//  - Call the _hashmap's hash function on the key
//  - Search that bucket to see if the key exists.
// This function should run in average-case constant time

int hashmap_hasKey(hashmap_t* _hashmap, char* key){
	//TODO
     if(_hashmap == NULL) return -9999;
     int index = stringHash(key,_hashmap->buckets);
     node_t* pos = _hashmap->arrayOfLists[index];
     if(pos == NULL) return 0; 
     if(strcmp(_hashmap->arrayOfLists[index]->kv->key,key)==0) return 1;
     while(pos != NULL){
           if(strcmp(pos->kv->key,key)==0)       return 1;
           pos = pos->next;
     }   
     return 0;	
}

// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//      - You should malloc the key/value in this function
// This function should run in average-case constant time

void hashmap_insert(hashmap_t* _hashmap,char* key,char* value){
    // TODO
        if(hashmap_hasKey(_hashmap,key) == 1) return;
	pair_t* new_pair = (pair_t*)malloc(sizeof(pair_t));
        new_pair->key = key;
        new_pair->value =value;

        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->kv = new_pair;
        		
	int bucket = stringHash(key,_hashmap->buckets);	
	node_t* iter = _hashmap->arrayOfLists[bucket];
	if(iter == NULL){
		_hashmap->arrayOfLists[bucket] = new_node;
	 }else{
           while(iter != NULL && iter->next != NULL){ 
             iter = iter->next;        
           }
           iter->next = new_node;    
            new_node->next =NULL;
        }              
}

// Return a value from a key 
// Returns NULL if the key is not found
// The algorithm is:
//  - If the key does not exist, then--return NULL if not found.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and return the value
// This function should run in average-case constant time

char* hashmap_getValue(hashmap_t* _hashmap, char* key){
	//TODO
        if(hashmap_hasKey(_hashmap,key) == 0) return NULL;
        int index = stringHash(key,_hashmap->buckets);
        node_t* iter = _hashmap->arrayOfLists[index];
	while(iter != NULL){
       	          if(strcmp(iter->kv->key, key)==0){
                         return iter->kv->value;
                  }	
         	  iter = iter->next;			
        }
        return NULL;
}

// TODO NOTE THAT I DID NOT FINISH REMOVE KEY BECAUSE...
// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
// This function should run in average-case constant time

void hashmap_removeKey(hashmap_t* _hashmap, char* key){
	//TODO
	if(hashmap_hasKey(_hashmap,key) == 0) return;
        int index = stringHash(key,_hashmap->buckets);
        node_t* iter =  _hashmap->arrayOfLists[index];
        if(strcmp(_hashmap->arrayOfLists[index]->kv->key , key)==0){
                     _hashmap->arrayOfLists[index]->kv->key = NULL;
                     _hashmap->arrayOfLists[index]->kv->value = NULL;
                     _hashmap->arrayOfLists[index] = NULL;
        }
        node_t* temp = iter->next;
	while(temp != NULL){
                pair_t* pair = temp->kv;
		if(strcmp(pair->key, key)==0){             
                   iter->next = temp->next;
                   free(pair);
                   free(temp);
                }		  
                iter = _hashmap->arrayOfLists[index];
 		temp = temp->next;			  
        }
}	
	

// Update a key with a new Value
// The algorithm is:
//  - Returns immediately if the key does not exist
//  - Call the _hashmap's hash function on the key
//  - Updates the value of the key to the new value
// This function should run in average-case constant time
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue){
	//TODO
       if(hashmap_hasKey(_hashmap,key) == 0) return;
       int index = stringHash(key,_hashmap->buckets); 
       node_t* iter =  _hashmap->arrayOfLists[index];
 
       if(strcmp(_hashmap->arrayOfLists[index]->kv->key , key)==0){
           _hashmap->arrayOfLists[index]->kv->value = newValue;
       }
       while(iter != NULL){
                  pair_t* pair = iter->kv;
            	  if(strcmp(pair->key, key)==0){
                       pair->value = newValue;
                  }	
         	  iter = iter->next;			
        }     
}

// Prints all of the keys in a hashmap
// The algorithm is:
//  - Iterate through every bucket and print out the keys
// This function should run in O(n) time
void hashmap_printKeys(hashmap_t* _hashmap){
	//TODO
	for(int i=0; i < _hashmap->buckets; i++){
		  printf("Bucket=%d\n",i);
		  node_t* iter = _hashmap->arrayOfLists[i];
		  while(iter != NULL){
			printf("\tKey=%s\n",iter->kv->key);
                        printf("\tVlaue=%s\n",iter->kv->value);
			iter = iter->next;			
		  }
               }	
		 
}

#endif
