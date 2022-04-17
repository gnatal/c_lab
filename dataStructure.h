typedef struct Data
{
    int integer;
    char *text;
    double numeric;
    struct Data *pointer;
} Data;

typedef struct definedData
{
    int integer;
    char *text;
    double numeric;
} definedData;

typedef struct TreeNode
{
    definedData data;
    struct TreeNode *left;
    struct TreeNode *right;
};
