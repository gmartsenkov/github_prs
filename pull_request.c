typedef struct PullRequest
{
    char *title;
    unsigned int x_position;
} PullRequest;

char* PR_DISPLAY(PullRequest *pr) 
{
    return pr->title[pr->x_position];
}