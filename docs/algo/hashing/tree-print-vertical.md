# Print Vertical Tree

O(n) under the assumption that we have good hashing function
but map stl -> self balancing binary tree -> O(nlogn)
the above solution may not print nodes in same vertical order as they appear in tree


```
void getVerticalOrder(Node* root, int hd, map<int, vector<int>> &m)
{
	if (root == NULL)
		return;

	m[hd].push_back(root->key);-

	getVerticalOrder(root->left, hd-1, m);

	getVerticalOrder(root->right, hd+1, m);
}

void printVerticalOrder(Node* root)
{
	map < int,vector<int> > m;
	int hd = 0;
	getVerticalOrder(root, hd,m);

	map< int,vector<int> > :: iterator it;
	for (it=m.begin(); it!=m.end(); it++)
	{
		for (int i=0; i<it->second.size(); ++i)
			cout << it->second[i] << " ";
		cout << endl;
	}
}
```