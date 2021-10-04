
#include "bbvs.h"

ResultCode init_chain(Chain **head)
{
  Block block = DEFAULT_BLOCK;

  time_t current_time = time(NULL);
  if (current_time == ((time_t)-1))
  {
    fprintf(stderr, "Failure to obtain the current time.\n");
    return FAILURE;
  }

  block.index = 1;
  strncpy(block.timestamp, ctime(&current_time), TIMESTAMP_LEN);
  block.timestamp[TIMESTAMP_LEN - 1] = '\0';
  block.data_p = NULL;
  block.proof = 0;
  strcpy(block.previous_hash, "");

  *head = (Chain *)malloc(sizeof(Chain));
  if (*head == NULL)
  {
    fprintf(stderr, "Could not allocate memmory to next block\n");
    return FAILURE;
  }

  (*head)->block = block;
  (*head)->next = NULL;

  return SUCCESS;
}

ResultCode new_block(Chain **chain_head, vote_data_t *votesArr, int *chainLen, char previousHash[], long proof)
{
  Block block = DEFAULT_BLOCK;

  if (*chain_head == NULL ||
      votesArr == NULL ||
      strlen(previousHash) == 0 ||
      proof == 0)
  {
    return FAILURE;
  }

  time_t current_time = time(NULL);

  if (current_time == ((time_t)-1))
  {
    fprintf(stderr, "Failure to obtain the current time.\n");
    return FAILURE;
  }

  block.index = *chainLen + 1;
  strncpy(block.timestamp, ctime(&current_time), TIMESTAMP_LEN);
  block.timestamp[TIMESTAMP_LEN - 1] = '\0';
  block.data_p = votesArr; //TODO copy by val
  block.proof = proof;
  strcpy(block.previous_hash, previousHash);

  //clean votesArr
  votesArr = NULL;

  (*chain_head)->next = (Chain *)malloc(sizeof(Chain));
  if ((*chain_head)->next == NULL)
  {
    fprintf(stderr, "Could not allocate memmory to next block\n");
    return FAILURE;
  }

  (*chain_head)->next->block = block;
  (*chain_head)->next->next = NULL;

  return SUCCESS;
}

ResultCode new_vote(vote_data_t voteData, vote_data_t *votesArr, int *lastVoteIndex)
{
  if (voteData.voterCnp == DEFAULT_CNP ||
      voteData.voterSection == DEFAULT_VOTER_SCT ||
      voteData.votedCandidateIndex == DEFAULT_VOTED_CND ||
      votesArr == NULL ||
      lastVoteIndex == NULL)
  {
    return FAILURE;
  }

  votesArr[(*lastVoteIndex)++] = voteData;

  return SUCCESS;
}
