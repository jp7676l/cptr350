#include<iostream>
#include"tree.h"
#include"location.h"
lilbrown::lilbrown()

{
  root = new quadnode;
  root->data= NULL;
  root->nw = NULL;
  root->ne = NULL;
  root->sw = NULL;
  root->se = NULL;
  root->left = 0;
  root->right= 128;
  root->top= 128;
  root->bottom= 0;  
}

 void lilbrown::paint(myrecord *crop, int left, int bottom, int right, int top)
{
  paint(root, crop, left, bottom, right, top);
}

void lilbrown::paint(quadnode *root, myrecord *crop, int left, int bottom, int right, int top)
{
 if(left<=root->left&&root->right<=right&&bottom<=root->bottom&&root->top<=top)
  {
    root->data=crop;
  }
 else if(left>=root->right&&root->left>=right&&bottom>=root->top&&root->bottom>=top)
  {
    //Nothing
  }
 else
  {
    split(root);
    paint(root->nw,crop,left,bottom,right,top);
    paint(root->ne,crop,left,bottom,right,top);
    paint(root->sw,crop,left,bottom,right,top);
    paint(root->se,crop,left,bottom,right,top);
  }
 }
 
 void lilbrown::split(quadnode *root)
 {
 if(root->nw==NULL)
 {
   
  root->nw = new quadnode;
  root->nw->data=root->data;
  root->nw->left=root->left;
  root->nw->right=(root->left + root->right)/2;
  root->nw->top=root->top;
  root->nw->bottom=(root->top + root->bottom)/2;
  root->nw->ne=NULL;
  root->nw->sw=NULL;
  root->nw->se=NULL;
  root->nw->nw=NULL;
 
  root->ne = new quadnode;
  root->ne->data=root->data;
  root->ne->left=(root->left + root->right)/2;
  root->ne->right=root->right;
  root->ne->top=root->top;
  root->ne->bottom=(root->top + root->bottom)/2;
  root->ne->ne=NULL;
  root->ne->sw=NULL;
  root->ne->se=NULL;
  root->ne->nw=NULL;

  root->sw = new quadnode;
  root->sw->data=root->data;
  root->sw->left=root->left;
  root->sw->right=(root->left + root->right)/2;
  root->sw->top=(root->top + root->bottom)/2;
  root->sw->bottom=root->bottom;
  root->sw->ne=NULL;
  root->sw->sw=NULL;
  root->sw->se=NULL;
  root->sw->nw=NULL;

  root->se = new quadnode;
  root->se->data=root->data;
  root->se->left=(root->left + root->right)/2;
  root->se->right=root->right;
  root->se->top=(root->top + root->bottom)/2;
  root->se->bottom=root->bottom;
  root->se->ne=NULL;
  root->se->sw=NULL;
  root->se->se=NULL;
  root->se->nw=NULL;

 }
 } 

  void lilbrown::draw()
   {
   displaydraw(root);
   }
  void lilbrown::displaydraw(quadnode *root)
  {
  if(root!=NULL){
 
   if(root->data!=NULL)
    {
     cout<<root->data->crop<<" ";    
    }
   else
    {
     cout << " empty coordinates" << endl;
    }
  displaydraw(root->nw);
  displaydraw(root->ne);
  displaydraw(root->sw);
  displaydraw(root->se);
 }
}
 void lilbrown::erase( int left, int bottom, int right, int top)
 {
  erase(root,left, bottom, right, top);
 }
void lilbrown::erase(quadnode *root,int left, int bottom, int right, int top)
{
 cout << " Not done" << endl;
}
/* if(leftuser<=leftnode&&rightnode<=rightuser&&bottomuser<=bottomnode&&topnode<=topuser)
  {
   root->data=left;
  //would delete be a for loop
  }
 }
  
  else if(leftuser>=rightnode&&leftnode>=rightuser&&bottomuser>=topnode&&bottomnode>=topuser)
  {
   //nothing
  {
   
  erase(root->nw,left,bottom,right,top);
  erase(root->ne,left,bottom,right,top);
  erase(root->sw,left,bottom,right,top);
  erase(root->sw,left,bottom,right,top);
  
  }*/

myrecord *lilbrown::point(int x, int y)
 {
  return point(root, x, y);
 }
myrecord *lilbrown::point(quadnode *root, int x, int y)
 {
  if(root!=NULL)
  {
    int middleX=(root->left + root->right)/2;  
    int middleY=(root->top + root->bottom)/2;   
   
   if(root->nw==NULL)
   return root->data;
     
   else if(x<middleX&&y>middleY)
     return point(root->nw, x,y);
   
   else if(x>middleX&&y>middleY)
     return point(root->ne, x,y);
   
   else if(x<middleX&&y<middleY)
     return point(root->sw, x,y);
   
   else
    return point(root->sw,x,y);
 }
   else return NULL;
  }

myrecord *lilbrown::touch(int left, int bottom, int right, int top)
 {
  return touch(root, left, bottom, right, top); 
 }
myrecord *lilbrown::touch(quadnode *root, int left, int bottom, int right, in top)
 {
  if(root!=NULL)
 {
  if(left==root->right&&right==root->left&&bottom==root->top&&top==root->bottom)
   {
     return root->data;
   }
  
  else if(left==root->right&&right==root->left&&bottom==root->top&&top==root->bottom)
   }
    //nothing
   }
   {
  else
   {
    touch(root->nw,left,bottom,right,top);
    touch(root->ne,left,bottom,right,top);
    touch(root->sw,left,bottom,right,top);
    touch(root->se,left,bottom,right,top);
   }
}
 else return NULL;
}

myrecord *lilbrown::intersect(int left, int bottom, int right, int top)
 {
  return intersect(root, left, bottom, right, top);
 }
myrecord *lilbrown::intersect(quadnode *root, int left, int bottom, int right, in top)
 {
  if(root!=NULL)
  {
   if(root->nw==NULL)
    return root->data;
    
   else if(left<=root->left&&right<=root->right&&bottom<=root->bottom&&top<=root->top)
    return intersect(root->nw, left, bottom, right, top);
   
