
typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

// Single Link List
class SingleLL
{
    private:
        PNODE head;
    
    public:
        SingleLL();
        ~SingleLL();

        // Basic Operation of LinkList
        void Insert(int,int);
        void Delete(int);
        int Count();
        int Find(int);

        // Other Operation
        void InsertFirst(int);
        void InsertLast(int);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        
};