#include <iostream>
#include<string>
#include "tree.h"
#include "location.h"
using namespace std;
 

int main()
{
   bigbrown crop; 
   lilbrown map;
 
   int top, bottom, left, right;
   myrecord *savedinfo;
   string input;
   string traversal;
   string coor;
    
   cout << ">" << flush;
   cin >> input;
   while (input != "quit")
   {
      if(input == "insert")
      {  
         string items, worker, color;
         int order;
         cin>>items;
         cin >>worker;
         cin>>order;
         cin>>color;
         crop.insert(items, worker, order, color);
         cout << "ADDED" << " " <<  " " << items << "  " << endl; 
      }
 
      else if (input == "dump")
      {
         cin >> traversal;
         crop.dump(traversal);
      }
      else if(input == "find")
      {
         string items;
         cout << "What are  you seeking to find?" << endl;
         cin >>items;
         crop.find(items);
         cout << "Here is what you asked for " << endl;
         cout << items << endl;
//       else
//       { 
//          cout << "Item could not be found!" << endl; 
//       } 
      }
      else if(input == "remove")
      {
         cout << " What will you like to remove?" << endl;
      }
      else if(input == "paint")
      { 
         string resource;
         cin>>resource;
         cin>>left;
         cin>>bottom;
         cin>>right;
         cin>>top;
         savedinfo = crop.find(resource);
         if(savedinfo!=NULL)
         {
         map.paint(savedinfo, left, bottom, right, top);
         cout<< "Paint" << " " << resource << " " << left << " " << bottom << " " <<  right << " " <<  top << endl; 
         }
         else
          {
            cout << "Could not find crop " << endl;
          }
      }
      else if(input=="draw")
      {
        map.draw();
      }
      else  
      {
         cout << "Invalid command" << endl;
      }

      cout << ">" << flush;
      cin >> input;
   } 

   cout << " Have a nice day " << endl;

   return 0;
}


