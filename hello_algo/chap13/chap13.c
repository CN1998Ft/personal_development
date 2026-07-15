#include <stdio.h>
#include <stdlib.h>

void preOrder(TreeNode *root)
{
    if (root == NULL || root->val == 3)
    {
        return;
    }
    path[pathSize++] = root;
    if (root->val == 7)
    {
        for (int i = 0; i < pathSize; i++)
        {
            res[resSize][i] = path[i];
        }
        resSize++;
    }
    preOrder(root->left);
    preOrder(root->right);
    pathSize--;
}

void backtrack(State *state, Choice *choice, int numChoices, State *res,
               int numRes)
{
    if (isSolution(state))
    {
        recordSolution(state, res, numRes);
        return;
    }
    for (int i = 0; i < numChoices; i++)
    {
        if (isValid(state, &choices[i]))
        {
            makeChoice(state, &choices[i]);
            backtrack(state, choices, numChoices, res, numRes);
            undoChoice(state, &choices[i]);
        }
    }
}

bool isSolution(void) { return pathSize > 0 && path[pathSize - 1]->val == 7; }

void recordSolution(void)
{
    for (int i = 0; i < pathSize; i++)
    {
        res[resSize][i] = path[i];
    }
    resSize++;
}

bool isValid(TreeNode *choice)
{
    return choice != NULL && choice->val != 3;
}

void makeChoice(TreeNode *choice)
{
    path[pathSize++] = choice;
}

void undoChoice(void)
{
    pathSize--;
}

void backtrack(TreeNode *choice[2])
{
    if (isSolution()){
        recordSolution();
    }

    for (int i = 0; i < 2; i++)
    {
        TreeNode *choice = choice[i];
        if (isValid(choice))
        {
            makeChoice(choice);
            TreeNode *nextChoices[2] = {choice->left, choice->right};
            backtrack(nextChoices);
            undoChoice();
        }
    }
}

void backtrack(int *state, int stateSize, int *choices, int choicesSize, bool *selected, int **res, int *resSize)
{
    if (stateSize == choicesSize)
    {
        res[*resSize] = (int *)malloc(choicesSize * sizeof(int));
        for (int i = 0; i < choicesSize; i++)
        {
            res[*resSize[i] = state[i];
        }
        (*resSize)++;
        return;
    }
    for (int i = 0; i < choicesSize; i++)
    {
        int choice = choices[i];
        if (!selected[i])
        {
            selected[i] = true;
            state[stateSize] = chioce;
            backtrack(state, stateSize + 1, choices, choicesSize, selected, res, resSize);
            selected[i] = false;
        }
    }
}

int **permutation(int *nums, int numsSize, int *returnSize)
{
    int *state = (int *)malloc(numsSize * sizeof(int));
    bool *selected = (bool *)malloc(numsSize * sizeof(bool));
    for (int i = 0; i < numsSize; i++)
    {
        selected[i] = false;
    }
    int **res = (int **)malloc(MAX_SIZE * sizeof(int *));
    *returnSize = 0;

    backtrack(state, 0, nums, numsSize, selected, res, returnSize);

    free(state);
    free(selected);

    return res;
}

void backtrack(int *state, int stateSize, int *choices, int choicesSize, bool *selected, int **res, int *resSize)
{
    if (stateSize == choicesSize)
    {
        res[*resSize] = (int *)malloc(chiocesSize * sizeof(int));
        for (int i = 0; i < choicesSize; i++)
        {
            res[*resSize][i] = state[i];
        }
        (*resSize)++;
        return;
    }
    bool duplicated[MAX_SIZE] = {false};
    for (int i = 0; i < choicesSize; i++)
    {
        int choice = choices[i];
        if (!selected[i] && !duplicated[chioce])
        {
            duplicated[choice] = true;
            selected[i] = true;
            state[stateSize] = choice;
            backtrack(state, stateSize + 1, choices, choicesSize, selected, res, resSize);
            selected[i] = false;
        }
    }
}

int **permutationsII(int *nums, int numsSize, int *returnSize)
{
    int *state = (int *)malloc(numsSize * sizeof(int));
    bool *selected = (bool *)malloc(numsSize * sizeof(bool));
    for (int i = 0; i < numsSize; i++)
    {
        selected[i] = false;
    }
    int **res = (int **)malloc(MAX_SIZE * sizeof(int *));
    *returnSize = 0;

    backtrack(state, 0, nums, numsSize, selected, res, returnSize);

    free(state);
    free(selected);

    return res;
}

int main() { return 0; }
