/*

Name:   main.c                                                       
                                                                           
Purpose:                                         

*/

#include "bbvs.h"


int main(int argc, char **argv)
{
  Chain *head = NULL;
  Chain *current = NULL;
  vote_data_t votes[MAX_VOTES];

  printf("Example output: %d\n", init_chain());

  return 0;
} /* main */
