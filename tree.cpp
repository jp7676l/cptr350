#include<iostream>
#include"tree.h"
bigbrown::bigbrown()
{
   
   root = NULL;
}

void bigbrown::dump(string order){ 
if (order == "inorder")
  {
     displayInOrder(root);
    }
else if (order == "preorder")
   {
     displayInOrder(root);
   }
 else if (order == "postorder")
   {
     displayPostOrder(root);
   }     
 else 
   {
     cout << "You can only get Inorder, Postorder, and Preorder" << endl;
   }
}    
  
   void bigbrown::displayPostOrder(treebs *root)
   {
    if (root)
   {
    displayInOrder(root->left);
    displayInOrder(root->right);
    cout << root->data->crop<< " ";
    cout << root->data->worker<< " ";
    cout << root->data->order<< " ";
    cout << root->data->color<< " ";
   }
} 
 
   void bigbrown::displayPreOrder(treebs *root)
   {
    if (root)
   {
    cout << root->data->crop<< " ";
    cout << root->data->worker<< " ";
    cout << root->data->order<< " ";
    cout << root->data->color<< " ";
    displayInOrder(root->left);
    displayInOrder(root->right);
   }
}

   void bigbrown::displayInOrder(treebs *root) 
   {
    if (root)
   {
    displayInOrder(root->left);
    cout << root->data->crop<< " ";
    cout << root->data->worker<< " ";
    cout << root->data->order<< " ";
    cout << root->data->color<< " ";
    displayInOrder(root->right);
   }
}    
 void bigbrown::insert(string item, string worker, int order, string color)
{
  insert( root, item, worker, order, color);
}

 void bigbrown::insert(treebs *&root, string crop, string worker, int order, string color)
{
 if(root==NULL)
{        
  root = new treebs;
  root->data=new myrecord;
  root->data->crop=crop;
  root->data->worker=worker;
  root->data->order=order;
  root->data->color=color;
  root->left = NULL;
  root->right = NULL;
}
             
  else if(crop<root->data->crop)
  {
   insert(root->left,crop,worker,order,color);
  }           
  else if(crop>root->data->crop)
  {
   insert(root->right,crop,worker,order,color);
  }     
}
 
myrecord *bigbrown::find(string item)
{
 return find(root, item);
}
myrecord *bigbrown::find(treebs *root, string item)
{
 if(root!=NULL)
 {  
    if(item==root->data->crop)
     return root->data;
   else if(item<root->data->crop)
     return find(root->left, item);
    else
    return find(root->right, item);
}
  else return NULL;
} 
/*void bigbrown::removetreebs(string item, string worker, string order, string color);
{
  removetreebsprivate(string item, string worker, int order, string  color, treebs);
}
void bigbrown:: removetreebsPrivate(string item, string worker, int order, string  color, treebs *lose);
{
 if(root!=NULL)return root;
 else if(data<=root->data)
  root->left=removetreebs(root->left, data);
  else if(data>root->data)
 else
 {
  if(root->right == NULL && root->left == NULL)
  
{
 
  
   else 
   {
    cout << " Ooops could not find what you were looking for!" << endl;
   }
 }
-- INSERT --

else 
 {
 cout << "The tree is empty or could not find:" << endl;
 }
}
 */
