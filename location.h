#include<string>
struct quadnode
{
  myrecord *data;
  quadnode *nw;
  quadnode *ne;
  quadnode *sw;
  quadnode *se;
  int left;
  int right;
  int bottom;
  int top;
};
 
class lilbrown
{
  private:
  quadnode *root;
 
  void paint(quadnode *root, myrecord *crop, int left, int bottom, int right, int top);
  void split(quadnode *root);
  void erase(quadnode *root,int left, int bottom, int right, int top);
  void displaydraw(quadnode *root);
  myrecord *point(quadnode *root, int x, int y);
  myrecord *touch(quadnode *root, int left, int bottom, int right, int top);
  myrecord *intersect(quadnode *root, int left, int bottom, int right, int top);

  public:
  lilbrown();
  void paint(myrecord *crop, int left, int bottom, int right, int top);
  void draw();
  void erase(int left, int bottom, int right, int top);
  myrecord *point(int x, int y);
  myrecord *touch(int left, int bottom, int right, int top);
  myrecord *intersect(int left, int bottom, int right, int top);
 };  
  
