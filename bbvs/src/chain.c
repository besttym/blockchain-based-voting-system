
#include "bbvs.h"

ResultCode init_chain()
{
    return SUCCESS;
}

ResultCode new_block()
{
    return SUCCESS;
}

ResultCode new_vote(vote_data_t vote_data, vote_data_t *votes_arr, int *last_vote_index)
{
    if(vote_data.voter_cnp == DEFAULT_CNP ||
       vote_data.voter_section == DEFAULT_VOTER_SCT ||
       vote_data.voted_candidate_index == DEFAULT_VOTED_CND ||
       votes_arr == NULL ||
       last_vote_index == NULL)
    {
        return FAILURE;
    }

    votes_arr[*last_vote_index] = vote_data;

    return SUCCESS;
}
