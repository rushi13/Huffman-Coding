
#include <iostream>

#include <cstdlib>

#include <vector>

#include <iterator>

#include <fstream>

#include <map>

#include <string> 

#include <bitset>

using namespace std;

typedef struct treenode{

	string element;
	treenode *left,*right;
	treenode(string element)
	{
		this->element = element;
		left = right = NULL;
	}
};

void printcodes(treenode *root,string str)
{

	
    if (root == NULL)
        return;
 
    cout<<root->element<<" "<<str<<endl; 
    printcodes(root->left, str + "0");
    printcodes(root->right, str + "1");
	
}
int main(int argc, char *argv[])
{
	map<string,string> huffman;   
	treenode *root = NULL,*temp = NULL;
	ifstream f;
	remove( "decoded.txt" );
	f.open(argv[2]);
	string i,k;
	int j = 0;
	while(f>>i)
	{
		if(j%2 == 1)
			huffman[k] = i;
		k = i;	
		j++;	
		//cout<<i<<endl;
	}
	for(std::map<string,string>::iterator it=huffman.begin(); it!=huffman.end(); ++it)
	{
//		cout<<it->first<<" "<<it->second<<endl;
//		cout<<it->first<<" : "<<it->second<<endl;
	
	}
	root = new treenode("-1");
	for(std::map<string,string>::iterator it=huffman.begin(); it!=huffman.end(); ++it)
	{
		temp = root;
		for(j = 0;j<it->second.length();j++)
		{
			if(it->second[j] == '0')
			{
				if(temp->left == NULL)
					temp->left = new treenode("-1");
				temp = temp->left;			
			}
			else
			{
				if(temp->right == NULL)
					temp->right = new treenode("-1");
				temp = temp->right;			
			}
				
		}
		if(j == it->second.length())
		{
			temp->element = it->first;	
		}
//		cout<<it->first<<" : "<<it->second<<endl;
	
	}
	f.close();
	int kz = 0;
	bitset<8> x;
//	printcodes(root,"");
	std::ofstream fo("decoded.txt", std::ios::out | std::ios::app);
	char c;
	temp = root;
	std::ifstream input(argv[1], std::ios::binary | ios::in);
	while (input.get(c))
	{
//		cout<<c<<"c";
    		for (int i = 7; i >= 0; i--) // or (int i = 0; i < 8; i++)  if you want reverse bit order in bytes
		{
//	        	cout << ((c >> i) & 1);
//			cout<<endl;
//			cout<<c;
//			cout<<x[i];
			if(((c >> i) & 1) == 0)
				temp = temp->left;
			else 
				temp = temp->right;
			if(temp->element != "-1")
			{
				fo<<temp->element<<endl;
				temp = root;
			}
		}
//		cout<<endl;
	}
//	cout<<endl;
	input.close();
	return 0;
}


