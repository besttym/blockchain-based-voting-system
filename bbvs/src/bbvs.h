/*

Name:   bbvs.h                                                     
                                                                           
Purpose:  Declare the functions                                      

*/

#ifndef BBVS_H
#define BBVS_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "openssl/sha.h"
#include <limits.h>


#define SHA256_LEN 64
#define TIMESTAMP_LEN 26
#define CNP_LEN 13
#define HASH_LEN 256
#define MAX_VOTES 100
#define DEFAULT_CNP 0
#define DEFAULT_VOTER_SCT 0
#define DEFAULT_VOTED_CND 0

// Enumerations
typedef enum
{
  BBVS_SUCCESS, // 0
  BBVS_FAILURE, // 1
  BBVS_END,     // 2
} BbvsResultCode;

typedef enum
{
  SUCCESS, // 0
  FAILURE  // 1
} ResultCode;

typedef enum
{
  FALSE, // 0
  TRUE   // 1
} Bool;

//Structs
typedef struct vote_data
{
  char voterCnp[CNP_LEN + 1];
  int voterSection;
  int votedCandidateIndex;
} vote_data_t;

typedef struct Block
{
  unsigned int index;
  char timestamp[TIMESTAMP_LEN + 1];
  vote_data_t *data_p;
  long proof;
  char previous_hash[HASH_LEN + 1];
} Block;

typedef struct Chain
{
  Block block;
  struct Chain *next;
} Chain;

//Static consts
static const Block DEFAULT_BLOCK = {
    0, "", NULL, 0, ""};

//Funcitons
ResultCode init_chain(Chain **chain_head);
ResultCode new_block(Chain **chain_head, vote_data_t *votesArr, int *chainLen, char previousHash[], long proof);
ResultCode new_vote(vote_data_t vote_data, vote_data_t *votes_arr, int *last_vote_index);
long proof_of_work(long last_proof);
Bool valid_proof(const long last_proof, const long proof);

#endif
