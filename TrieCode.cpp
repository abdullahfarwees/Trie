#include "onepgm.h"

Node::Node()
{
	NodeStr= "";
	info = '\0';
	flag = false;

	for(int i = 0 ; i < 256; i++)
	{
		ptrs[i] = NULL;
	}
}

Node::~Node()
{
cout<<"destructor";
}

void Node::insert(string localStr, int posistion , class Node *root)
{
 cout<<"-->"<<posistion<<endl;


// base case for stopping recurssion
 if(localStr.length() == posistion)
 {
	 	root->NodeStr= localStr;
		cout<<"note here-->"<<posistion<<endl;
		return;
 }

// insert the string if empty
	if( root->ptrs[word[posistion]] == NULL )
	{
		cout<<"\ncreating new branch";
		Node *currentnode = new Node;
		currentnode->info = localStr[posistion];
		cout<<"\nword[pos] -->"<<word[posistion];
		root->ptrs[localStr[posistion]] = currentnode;
		insert(localStr,posistion+1,root->ptrs[localStr[posistion]]);
	}
	else // increment posistion by +1
	{
		cout<<"\nNot Empty";
		insert(localStr,posistion+1,root->ptrs[localStr[posistion]]);
	}

}

void Node::suggest(string localStr, int posistion , class Node *root)
{
	if( (localStr != root->NodeStr) && (root->ptrs[localStr[posistion]] != NULL ) )
	{
		suggest(localStr,posistion+1,root->ptrs[localStr[posistion]]);
	}
	else
	{
		printfunc(root);
	}
}

void Node::findword(string localStr, int posistion , class Node *root)
{
	if( (root->NodeStr!= localStr) && (root->ptrs[localStr[posistion]] != NULL) )
	{
		findword(localStr,posistion+1,root->ptrs[localStr[posistion]]);
	}
	else
	{
		if( localStr == root->NodeStr)
		{
			cout<<endl<<localStr<<" and "<<root->NodeStr<<" Correct"<<endl;
		}
		else
		{
			cout<<"\n\nWord not found!";
		}
	}

}

void Node::printfunc(class Node *root)
{
	//cout<<"\nprintfunc";
	for(int i = 0; i < 256 ; i++)
	{
		if(root->ptrs[i] != NULL)
		{
				printfunc(root->ptrs[i]);
		}

	}
	if( root->NodeStr!= "")
		cout<<"------------------------------------>"<<root->NodeStr<<endl;

}

void Node::closeFunction()
{
	fin.close();
	exit(0);
}


int main()
{

	Node *root = new Node;
	Node node;

	fin.open("data2.txt");
	while( !fin.eof() )
	{
		fin>>word;
		cout<<endl<<word;
		node.insert(word,0,root);
	}

	cout<<"\n\nSuccessful : Trie construction ";

while(1)
{
	cout<<"\n\nEnter option :\n1.print Trie\n2.Search\n3.Exit\n\n---->";
	cin>>option;
	switch(option)
	{
case 1:
	node.printfunc(root);
	break;

case 2:
	cout<<"\n\nEnter string to search :";
	cin>>s;
	node.findword(s,0,root);
	break;

case 3:
	cout<<"\n\nstopped...";
	node.closeFunction();
	break;

default :
	cout<<"Invalid options ! Try Again!!";
 }

}

	fin.close();

return 0;
}
