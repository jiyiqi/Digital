 #include<iostream>
using namespace std;
 #include "BinarySearchTree.h"
 
 int main()
{
    BinarySearchTree<int> binaryTree;
	int c;
for(int a=0;a<6;a++)
{
	cin>>c;
	binaryTree.insert(c);
}
   binaryTree.printTreeInPrev();
     cout <<endl;
  binaryTree.printTree();
     cout <<endl;
     cout<<"加入一个数"<<endl;
	 cin>>c;
	 binaryTree.insert(c);
	 binaryTree.printTreeInPrev();
     cout <<endl;
	 binaryTree.printTree();
     cout <<endl;
	 cout<<"删除一个数"<<endl;
	 cin>>c;
	 bool h=binaryTree.contains(c);
	 if(h==0)
	 {
	 cout<<"这个数不存在"<<endl;
	 }
	 else if(h==1)
	 {
	 binaryTree.remove(c);
	    binaryTree.printTreeInPrev();
     cout <<endl;
	  binaryTree.printTree();
      cout <<endl;
     }

	 system("pause");
 }