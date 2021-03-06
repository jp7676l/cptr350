#include<string>
struct myrecord
{
  string crop;        // Like Wheat
  string worker;      // Like Mitch
  int order;          // Like 5
  string color;       // Like blue
};

struct treebs
{
  myrecord *data;
  treebs *left;
  treebs *right;
};

class bigbrown 
{
   private:          // Internal parts to hold information
   treebs *root;    
    
    void displayPostOrder(treebs *root);
    void displayPreOrder(treebs *root);
    void displayInOrder(treebs *root);
   //void removetreebsPrivate(string item, string worker, int order, string  color, treebs *lose);
    void insert(treebs * &root, string crop, string worker, int order, string  color);
    myrecord *find(treebs *root, string items);
   //void AddinsertPrivate(string item, string worker, string order, string  color, treebs *ptr);

   
  
   public:           // Outside controls for user
     bigbrown();
   myrecord *find(string item);
   void dump(string order);
 //void remove treebs(string item, string worker, int order, string  color);  
   void insert(string items, string worker, int order, string color); 
};

