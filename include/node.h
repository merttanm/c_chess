struct pointNode{
    struct Point *data;
    char *str_data;
    struct pointNode *next;
    struct pointNode *prev;
};

struct rectNode{
    struct SDL_Rect *data;
    struct rectNode *next;
    struct rectNode *prev;
};