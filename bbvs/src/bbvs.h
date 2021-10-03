/*

Name:   bbvs.h                                                     
                                                                           
Purpose:  Declare the functions                                      

*/

#ifndef BBVS_H
#define BBVS_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VOTES 100
#define DEFAULT_CNP 0
#define DEFAULT_VOTER_SCT 0
#define DEFAULT_VOTED_CND 0


// Enumerations
typedef enum {
    BBVS_SUCCESS, // 0
    BBVS_FAILURE, // 1
    BBVS_END,     // 2
} BbvsResultCode;

typedef enum {
    SUCCESS, // 0
    FAILURE // 1
} ResultCode;

typedef struct vote_data {
    char voter_cnp[13];
    int voter_section;
    int voted_candidate_index;
} vote_data_t;

typedef struct Block {
    unsigned int index;
    time_t timestamp;
    vote_data_t data;
    long proof;
    char previous_hash[256];
} Block;

typedef struct Chain {
    Block block;
    struct Chain* next;
} Chain;

ResultCode init_chain();
ResultCode new_block();
ResultCode new_vote(vote_data_t vote_data, vote_data_t *votes_arr, int *last_vote_index);


int example(int first, int second);

#endif
