#define MAX_FRAMES    32
#define MAX_PARAMS     8
#define MAX_ARR_SIZE  16
#define MAX_STR       32
#define C_OK           0
#define C_NOK         -1

typedef struct {
  char name[MAX_STR];
  int  *value;
} ParamType;

typedef struct {
  char      funcName[MAX_STR];
  int       numParams;
  ParamType *params[MAX_PARAMS];
} FrameType;

typedef struct {
  int numFrames;
  FrameType frames[MAX_FRAMES];
} StackType;

/*  Stack functions  */
void st_init(StackType*);
void st_push(StackType*, char*, int, ParamType**);
void st_pop(StackType*);
void st_dump(StackType*);
void st_createParam(char*, int*, ParamType**);

/*  Loop functions  */
void sumIterative(StackType*, int, int*, int*);
void sumRecursive(StackType*, int, int*, int*);
int getArrayData(int*, int*);


