#include <iostream>

#include <cstdlib>

#include <vector>

#include <fstream>

#include <map>

#include <bitset>

#include <string>

#include <vector>

using namespace std;

typedef struct treenode{
	int freq;
	int element;
	treenode *left,*right;
	treenode(int freq,int element)
	{
		this->freq = freq;
		this->element = element;
		left = right = NULL;
	}
};

typedef struct node{
	int element;
	int freq;
	treenode *root;
};

class fourwayHeap{

	private:

	vector <node> heap;

	int one(int parent);

	int two(int parent);

	int three(int parent);

	int four(int parent);

	int parent(int child);

	void heapifyup(int index);

	void heapifydown(int index);

	public:

	fourwayHeap()

	{}

	void Insert(int element,int freq, treenode *temp);

	void DeleteMin();

	node ExtractMin();

	int Size();

	int findmin(int one,int two,int three,int four);

};

int fourwayHeap::Size()
{

	return heap.size();

}


void fourwayHeap::Insert(int element,int freq, treenode *temp)
{
	if(heap.size() == 0)
	{
		heap.push_back(node());
		heap[heap.size() -1].element = -1;
		heap[heap.size() -1].freq = -1;	
		heap[heap.size() -1].root = NULL;
		heap.push_back(node());
		heap[heap.size() -1].element = -1;
		heap[heap.size() -1].freq = -1;	
		heap[heap.size() -1].root = NULL;
		heap.push_back(node());		
		heap[heap.size() -1].element = -1;
		heap[heap.size() -1].freq = -1;	
		heap[heap.size() -1].root = NULL;
	}	
	heap.push_back(node());
	heap[heap.size() -1].element = element;
	heap[heap.size() -1].freq = freq;	
	heap[heap.size() -1].root = temp;	
	heapifyup(heap.size() -1);
}

void fourwayHeap::DeleteMin()
{

	if (heap.size() == 3)

	{

		cout<<"Heap is Empty"<<endl;

		return;

	}

	heap[3] = heap.at(heap.size() - 1);

	heap.pop_back();

	heapifydown(3);
}


node fourwayHeap::ExtractMin()
{
	node p;
	p.element = 0;
	p.freq = 0;

	if (heap.size() == 0)
		return p;
	else
		return heap[3];
	
}


int fourwayHeap::one(int parent)
{

	int one = 4 * (parent - 3) + 4;

	if (one < heap.size())

		return one;

	else

		return -1;

}


int fourwayHeap::two(int parent)
{

	int two = 4 * (parent - 3) + 5;

	if (two < heap.size())

		return two;

	else

		return -1;

}

int fourwayHeap::three(int parent)
{

	int three = 4 * (parent - 3) + 6;

	if (three < heap.size())

		return three;

	else

		return -1;

}

int fourwayHeap::four(int parent)
{

	int four = 4 * (parent - 3) + 7;

	if (four < heap.size())

		return four;

	else

		return -1;

}


int fourwayHeap::parent(int child)
{

	int p = (child - 4)/4 + 3;

	if (child == 0)

		return -1;

	else

		return p;

}


void fourwayHeap::heapifyup(int in)
{
	node temp;

	if (in > 3 && parent(in) >= 3 && heap[parent(in)].freq > heap[in].freq)
	{

		temp = heap[parent(in)] ;

		heap[parent(in)] = heap[in];

		heap[in] = temp;

		heapifyup(parent(in));

	}

}

int fourwayHeap::findmin(int one,int two,int three,int four)
{
	int min = one;

	if(heap[two].freq < heap[min].freq && two > 3)
		min = two;
	if(heap[three].freq < heap[min].freq && three > 3)
		min = three;
	if(heap[four].freq < heap[min].freq && four > 3)
		min = four;

	return min;
}     


void fourwayHeap::heapifydown(int in)
{

	node temp;     

	int child1 = one(in);

	int child2 = two(in);

	int child3 = three(in);

	int child4 = four(in);

	int child = findmin(child1,child2,child3,child4);

	if (child > 3 && heap[in].freq > heap[child].freq)
	{
		temp = heap[in];

		heap[in] = heap[child];

		heap[child] = temp;

		heapifydown(child);
	}

}

class BinaryHeap
{

	private:

	vector <node> heap;

	int left(int parent);

	int right(int parent);

	int parent(int child);

	void heapifyup(int index);

	void heapifydown(int index);

	public:

	BinaryHeap()

	{}

	void Insert(int element,int freq,treenode *temp);

	void DeleteMin();

	node ExtractMin();

	int Size();

};

int BinaryHeap::Size()
{

	return heap.size();

}


void BinaryHeap::Insert(int element,int freq, treenode *temp)
{

	heap.push_back(node());
	heap[heap.size() -1].element = element;
	heap[heap.size() -1].freq = freq;	
	heap[heap.size() -1].root = temp;	
	heapifyup(heap.size() -1);

}

void BinaryHeap::DeleteMin()
{

	if (heap.size() == 0)
	{
		cout<<"Heap is Empty"<<endl;
		return;
	}

	heap[0] = heap.at(heap.size() - 1);

	heap.pop_back();

	heapifydown(0);

}


node BinaryHeap::ExtractMin()
{
	node p;
	p.element = 0;
	p.freq = 0;

	if (heap.size() == 0)
		return p;
	else
		return heap.front();

}



int BinaryHeap::left(int parent)
{

	int l = 2 * parent + 1;

	if (l < heap.size())

		return l;

	else

		return -1;

}


int BinaryHeap::right(int parent)
{

	int r = 2 * parent + 2;

	if (r < heap.size())

		return r;

	else

		return -1;

}


int BinaryHeap::parent(int child)
{

	int p = (child - 1)/2;

	if (child == 0)

		return -1;

	else

		return p;

}


void BinaryHeap::heapifyup(int in)
{

	node temp;

	if (in >= 0 && parent(in) >= 0 && heap[parent(in)].freq > heap[in].freq)
	{

		temp = heap[parent(in)] ;

		heap[parent(in)] = heap[in];

		heap[in] = temp;

		heapifyup(parent(in));

	}

}



void BinaryHeap::heapifydown(int in)
{

	node temp;

	int child = left(in);

	int child1 = right(in);

	if (child >= 0 && child1 >= 0 && heap[child].freq > heap[child1].freq)
		child = child1;

	if (child > 0 && heap[in].freq > heap[child].freq)
	{

		temp = heap[in];

		heap[in] = heap[child];

		heap[child] = temp;

		heapifydown(child);

	}

}


class PairingNode
{

	public:

	treenode *root;

	int element,freq;

	PairingNode *leftChild;

	PairingNode *nextSibling;

	PairingNode *prev;

	PairingNode(int freq,int element,treenode *root)
	{
		this->root = root;

		this->element = element;

		this->freq = freq;

		leftChild = NULL;

		nextSibling = NULL;

		prev = NULL;

	}

};


class PairingHeap
{

	private:

	PairingNode *root;

	void Link(PairingNode * &first, PairingNode *second);

	PairingNode *Combine(PairingNode *firstSibling);

	public:

	int size = 0;

	PairingHeap();

	bool isEmpty();

	treenode *findMin();

	void Insert(int x,int freq,treenode *root);

	void deleteMin();

};



PairingHeap::PairingHeap()
{

	root = NULL;

}


void PairingHeap::Insert(int freq,int x,treenode *temp)
{

	PairingNode *newNode = new PairingNode(freq,x,temp);

	if (root == NULL)

		root = newNode;

	else

		Link(root, newNode);
}


treenode *PairingHeap::findMin()
{
	
	return this->root->root;

}


void PairingHeap::deleteMin()
{

	if (isEmpty())
	{

		cout<<"The Heap is Empty"<<endl;

		return;

	}

	PairingNode *oldRoot = root;

	if (root->leftChild == NULL)
	root = NULL;

	else
	root = Combine(root->leftChild);

	delete oldRoot;

}



bool PairingHeap::isEmpty()
{

	return root == NULL;

}


void PairingHeap::Link(PairingNode * &first, PairingNode *second)
{

	if (second == NULL)

	return;

	if (second->freq <= first->freq)
	{

		second->prev = first->prev;

		first->prev = second;

		first->nextSibling = second->leftChild;

		if (first->nextSibling != NULL)

		first->nextSibling->prev = first;

		second->leftChild = first;

		first = second;

	}

	else
	{

		second->prev = first;

		first->nextSibling = second->nextSibling;

		if (first->nextSibling != NULL)

		first->nextSibling->prev = first;

		second->nextSibling = first->leftChild;

		if (second->nextSibling != NULL)

		second->nextSibling->prev = second;

		first->leftChild = second;

	}

}


PairingNode *PairingHeap::Combine(PairingNode *firstSibling)
{

	if (firstSibling->nextSibling == NULL)

		return firstSibling;

	static vector<PairingNode *> treeArray(5);

	int numSiblings = 0;

	for (; firstSibling != NULL; numSiblings++)
	{

		if (numSiblings == treeArray.size())

			treeArray.resize(numSiblings * 2);

		treeArray[numSiblings] = firstSibling;

		firstSibling->prev->nextSibling = NULL;

		firstSibling = firstSibling->nextSibling;

	}

	if (numSiblings == treeArray.size())

		treeArray.resize(numSiblings + 1);

	treeArray[numSiblings] = NULL;

	int i = 0;

	for (; i + 1 < numSiblings; i += 2)

		Link(treeArray[i], treeArray[i + 1]);

	int j = i - 2;

	if (j == numSiblings - 3)

		Link (treeArray[j], treeArray[j + 2]);

	for (; j >= 2; j -= 2)

		Link(treeArray[j - 2], treeArray[j] );

	return treeArray[0];

}

map<int,string> huffman;     


void printcodes(treenode *root, string str)
{

	if (root == NULL)
		return;

	if (root->element >= 0)
		huffman[root->element] = str;
	
	printcodes(root->left, str + "0");
	printcodes(root->right, str + "1");

}

void build_tree_using_4way_heap(char* filename)
{
	fourwayHeap h;
	treenode *left = NULL,*right = NULL,*root = NULL;
	node p,q;
	int freq[1000000] = {0};
	int ij = -1;
	ifstream f;
	
	while (!huffman.empty())
		huffman.erase(huffman.begin());
		
	remove( "code_table.txt" );
	remove( "encoded.bin" );

	f.open(filename);
	int i;
	while(f>>i)
		freq[i]++;
	
	for(i = 0;i<1000000;i++)
	{
		if(freq[i] != 0)
		{
			root = new treenode(freq[i],i);
			h.Insert(i,freq[i],root);
		}	
	}
	f.close();	

	while(h.Size() > 4)
	{
		p = h.ExtractMin();       

		h.DeleteMin();

		left = p.root;

		q = h.ExtractMin();       

		h.DeleteMin();

		right = q.root;

		root = new treenode(left->freq + right->freq,ij);

		root->left = left;

		root->right = right;

		h.Insert(ij--,left->freq + right->freq,root);
	}       

	printcodes(root,"");

}

void build_tree_using_binary_heap(char* filename)
{

	BinaryHeap h;
	treenode *left = NULL,*right = NULL,*root = NULL;
	node p,q;
	int freq[1000000] = {0};
	int ij = -1;
	ifstream f;

	while (!huffman.empty())
		huffman.erase(huffman.begin());

	remove( "code_table.txt" );
	remove( "encoded.bin" );

	f.open(filename);
	int i;

	while(f>>i)
		freq[i]++;

	for(i = 0;i<1000000;i++)
	{
		if(freq[i] != 0)
		{
			root = new treenode(freq[i],i);
			h.Insert(i,freq[i],root);
		}	
	}
	f.close();

	while(h.Size() > 1)
	{
		p = h.ExtractMin();       

		h.DeleteMin();

		left = p.root;

		q = h.ExtractMin();       

		h.DeleteMin();

		right = q.root;

		root = new treenode(p.freq + q.freq,ij);

		root->left = left;

		root->right = right;

		h.Insert(ij--,p.freq + q.freq,root);

	}       

	printcodes(root,"");

}


void build_tree_using_pairing_heap(char* filename)
{
	int ij = -1;
	PairingHeap h;
	treenode *left = NULL,*right = NULL,*root = NULL;	
	long freq[1000000] = {0};
	ifstream f;
	remove( "code_table.txt" );
	remove( "encoded.bin" );
	f.open(filename);
	int i;
	while (!huffman.empty())
		huffman.erase(huffman.begin());
	
	while(f>>i)
		freq[i]++;
	
	for(i = 0;i<1000000;i++)
	{
		if(freq[i] != 0)
		{
			root = new treenode(freq[i],i);
			h.Insert(freq[i],i,root);
			h.size++;	
		}	
	}

	while(h.size>1)
	{
		left = h.findMin();
		h.deleteMin();
		right = h.findMin();
		h.deleteMin();
		root = new treenode(left->freq + right->freq,ij);
		root->left = left;
		root->right = right;
		h.Insert(left->freq + right->freq,ij--,root);
		h.size--;
	}

	f.close();

	printcodes(root,"");


}

int main(int argc, char *argv[])
{
	clock_t pairing_start_time,pairing_finish_time; 

	pairing_start_time = clock(); 

	for(int xyz = 0;xyz  < 10;xyz++)
		build_tree_using_pairing_heap(argv[1]);

	pairing_finish_time = clock();

	cout << "Time using pairing heap (microsecond):  " << (pairing_finish_time - pairing_start_time)/10 << endl; 

	clock_t binary_start_time,binary_finish_time; 

	binary_start_time = clock(); 

	for(int xyz = 0;xyz  < 10;xyz++)
		build_tree_using_binary_heap(argv[1]);

	binary_finish_time = clock();

	cout << "Time using binary heap (microsecond):  " << (binary_finish_time - binary_start_time)/10 << endl; 

	clock_t fourway_start_time,fourway_finish_time; 

	fourway_start_time = clock(); 

	for(int xyz = 0;xyz  < 10;xyz++)
		build_tree_using_4way_heap(argv[1]);

	fourway_finish_time = clock();

	cout << "Time using fourway heap (microsecond):  " << (fourway_finish_time - fourway_start_time)/10 << endl; 

	if(((binary_finish_time - binary_start_time) < (pairing_finish_time - pairing_start_time)) && ((binary_finish_time - 		binary_start_time) < (fourway_finish_time - fourway_start_time)))
	{
		cout<<"Binary heap is the fastest"<<endl;
		build_tree_using_binary_heap(argv[1]);
	}

	else if(((pairing_finish_time - pairing_start_time) < (binary_finish_time - binary_start_time) ) && ((pairing_finish_time - pairing_start_time) < (fourway_finish_time - fourway_start_time)))
	{
		cout<<"Pairing heap is the fastest"<<endl;
		build_tree_using_pairing_heap(argv[1]);
	}

	else if(((fourway_finish_time - fourway_start_time) < (binary_finish_time - binary_start_time) ) && ((fourway_finish_time - fourway_start_time) < (pairing_finish_time - pairing_start_time)))
	{
		cout<<"Four way heap is the fastest"<<endl;
		build_tree_using_4way_heap(argv[1]);	
	}

	ifstream f;

	std::ofstream fo("code_table.txt", std::ios::out | std::ios::app);

	for(std::map<int,string>::iterator it=huffman.begin(); it!=huffman.end(); ++it)
		fo<<it->first<<" "<<it->second<<endl;
	
	string c;
	bitset<8> x;
	int ab = 7,i;
	f.open(argv[1]);
	x.reset();
	std::ofstream fs("encoded.bin", std::ios::out | std::ios::binary | std::ios::app);
	while(f>>i)
	{
		c = huffman[i];
		for(int kz = 0;kz < c.length();kz++)
		{
			if(c[kz] != '0')
			x.set(ab);		
			ab--;
			if(ab == -1)
			{
				ab = 7;			
				fs.write((char*)&x, sizeof(char));
				x.reset();
			}
		}		
	}
	fs.close();
	f.close();
	return 0;

}
