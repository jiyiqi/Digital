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
     cout<<"����һ����"<<endl;
	 cin>>c;
	 binaryTree.insert(c);
	 binaryTree.printTreeInPrev();
     cout <<endl;
	 binaryTree.printTree();
     cout <<endl;
	 cout<<"ɾ��һ����"<<endl;
	 cin>>c;
	 bool h=binaryTree.contains(c);
	 if(h==0)
	 {
	 cout<<"�����������"<<endl;
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