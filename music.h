#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node 
{ 
    public:
    string genre;
    string songname;
    string singer;
    int year;
    int count;
    node *left, *right,*root; 

}; 

node* newNode(string g,string sn,string s,int y) 
{ 
    node* Node = new node();
    Node->genre = g; 
    Node->songname = sn;
    Node->singer = s;
    Node->year =y;
    Node->left = Node->right = NULL; 
    return (Node); 
} 

node *rightRotate(node *x) 
{ 
    node *y = x->left; 
    x->left = y->right; 
    y->right = x; 
    return y; 
} 

node *leftRotate(node *x) 
{ 
    node *y = x->right; 
    x->right = y->left; 
    y->left = x; 
    return y; 
} 
  
node *splay(node *root, string sn) 
{ 
    if (root == NULL || root->songname == sn) 
        return root; 
    if (root->songname > sn) 
    { 
        if (root->left == NULL) 
			return root;  
        if (root->left->songname > sn) 
        { 
            root->left->left = splay(root->left->left, sn); 
            root = rightRotate(root); 
        } 
        else if (root->left->songname < sn) 
        { 
            root->left->right = splay(root->left->right, sn);  
            if (root->left->right != NULL) 
                root->left = leftRotate(root->left); 
        } 
        return (root->left == NULL)? root: rightRotate(root); 
    } 
    else 
    { 
        if (root->right == NULL) 
			return root; 
        if (root->right->songname > sn) 
        { 
            root->right->left = splay(root->right->left, sn); 
            if (root->right->left != NULL) 
                root->right = rightRotate(root->right); 
        } 
        else if (root->right->songname < sn) 
        {  
            root->right->right = splay(root->right->right, sn); 
            root = leftRotate(root); 
        } 
        return (root->right == NULL)? root: leftRotate(root); 
    } 
} 


void traversal(node *root) 
{
    if(root == NULL)
        return;
    traversal(root->left);
    cout<<root->genre;
    cout << "\t\t"<<root->songname;
    cout<<"\t\t"<<root->singer;
    cout<<"\t\t"<<root->year<<"\n";
    traversal(root->right);
}


void display(node *root)
{
    cout<<"GENRE\t\tSONG NAME \tSINGER\t\tYEAR OF RELEASE"<<endl;
    traversal(root);
}
node *Insert(node *root, string g,string sn,string s,int y)
{
    if (root == NULL) 
		return newNode(g,sn,s,y);
    root = splay(root, sn);
    if (root->songname == sn) 
		return root;
    node *newnode = newNode(g,sn,s,y);
    if (root->songname > sn)
    {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }
    else
    {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
    return newnode; 
}
node* search(node* t,string data){
/*if(t==nullNode){
return nullNode;
}*/
if(data<t->songname){
return search(t->left,data);
}
else if(data>t->songname){
return search(t->right,data);
}
else{
    t->count=(1+t->count);
//cout<<t->count<<endl;
cout<<t->songname;
cout<<"\t\t\t"<<t->genre;
cout<<"\t\t"<<t->singer;
cout<<"\t\t"<<t->year;
return t;
}
}

void search1(node *t,string data){
node* temp=search(t,data);
if(temp!=NULL){
cout<<endl<<"Found "<<data<<" in the splay tree"<<endl;
}
else{
cout<<endl<<"Not Found "<<data<<" in the splay tree"<<endl;
}
}

void check1(node* root,string gen)
{
	if(root == NULL)
        return;
    if(root->genre.compare(gen) == 0)
    {
        cout<<root->genre<<"\t"<< root->songname <<endl;
	}
    check1(root->left,gen);
    check1(root->right,gen);
}
void old(node* root)
{
	if(root == NULL)
        return;
    if(root->year>= 1800 && root->year<=1899)
    {
        cout<< root->songname <<"\t"<<root->singer<<"\t"<<root->year<<endl;
	}
    old(root->left);
    old(root->right);
}
void retro(node* root)
{
	if(root == NULL)
        return;
    if(root->year>= 1900 && root->year<=1999)
    {
        cout<< root->songname <<"\t"<<root->singer<<"\t"<<root->year<<endl;
	}
    retro(root->left);
    retro(root->right);
}
void New(node* root)
{
	if(root == NULL)
        return;
    if(root->year>= 2000 && root->year<=2010)
    {
        cout<< root->songname <<"\t"<<root->singer<<"\t"<<root->year<<endl;
	}
    New(root->left);
    New(root->right);
}
void vNew(node* root)
{
	if(root == NULL)
        return;
    if(root->year>= 2011 && root->year<=2020)
    {
        cout<< root->songname <<"\t"<<root->singer<<"\t"<<root->year<<endl;
	}
    vNew(root->left);
    vNew(root->right);
}
void rNew(node* root)
{
	if(root == NULL)
        return;
    if(root->year==2021)
    {
        cout<< root->songname <<"\t"<<root->singer<<"\t"<<root->year<<endl;
	}
    rNew(root->left);
    rNew(root->right);
}
void sing(node* root,string singe)
{
	if(root == NULL)
        return;
    if(root->singer.compare(singe) == 0)
    {
        cout<<root->singer<<"\t"<< root->songname <<endl;
	}
    sing(root->left,singe);
    sing(root->right,singe);
}
void freq(node *t,vector<pair<int,string> >&m)
{
    if(t==NULL)
    {
        return;
    }
    if(t->count!=0){

        //cout<<"SONG NAME "<<"\t"<<"FREQUENCY "<<endl;
        //cout<<t->songname<<"\t\t"<<t->count<<endl;
        m.push_back({t->count,t->songname});
    }
        freq(t->left,m);
        freq(t->right,m);
}

void Partial_Match_Names(node *root,string s)
	{
		stack<node*> stk;
		vector<std::string >songname;
vector<std::string >genre;
vector<std::string >singer;
		bool flag = false;
		stk.push(root);
		while (stk.size() != 0)
		{
			node *temp = stk.top();
			stk.pop();
		songname.push_back(temp->songname);
genre.push_back(temp->genre);
singer.push_back(temp->singer);
			if (temp->right != NULL)
{
				stk.push(temp->right);
}
			if (temp->left != NULL)
{
				stk.push(temp->left);
}
		}
		int count = 1;
		for (int i = 0; i < songname.size(); i++)
		{
			int m = songname[i].size(), n = s.size();
			int LCS[m + 1][n + 1];
			int result = 0;
			for (int k = 0; k <= m; k++)
			{
				for (int l = 0; l <= n; l++)
				{
					if (l == 0 || k == 0)
					{
						LCS[k][l] = 0;
						continue;
					}
					if (songname[i][k - 1] == s[l - 1])
					{
						LCS[k][l] = LCS[k - 1][l - 1] + 1;
						result = max(result, LCS[k][l]);
					}
					else
					{
						LCS[k][l] = 0;
					}
				}
			}
			if (result >= 3)
			{
				if (count == 1)
				{
					//cout << "PARTIAL MATCHES ARE:";
					flag = true;
				}
				cout << endl;

				cout << count << "."<<"\t" << songname[i]<<"\t\t"<<genre[i]<<"\t"<<singer[i]<<endl;
				count++;
			}
		}
		if (flag == false)
		{
			cout << "NO PARTIAL MATCHES!" << endl << endl;
		}
		cout << endl;
	}
	
node* delete_key(node *root, string key)
{
    node *temp;
    if (!root)
        return NULL;   
    root = splay(root, key);
    if (key != root->songname)
        return root; 
    if (!root->left)
    {
        temp = root;
        root = root->right;
    }
    else
    {
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }
    free(temp);
    return root;
      
}
