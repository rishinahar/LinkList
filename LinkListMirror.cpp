struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode (int data){
	
	struct node* node = (struct node*)
                       malloc(sizeof(struct node));

    node->data =data;
    node->left=null;
    node->right = null;
  return (node);
}

void mirror (Struct node* node)
{
	if (node == null)
	  return;
    else
    {
    Struct node* temp;
  
	  mirror (node->left);
	  Cout << node->data;
	  mirror (node->right);

	    temp = node->left;
	    node->left = noed->right;
	    node->right = temp;

}

void swap(Struct node* node)
{
	if (node == null)
	  return;
    else
    {
    Struct node* temp;
  
	  mirror (node->left);
	  Cout << node->data;
	  mirror (node->right);

	    temp = node->left;
	    node->left = node->right;
	    node->right = temp;

}


int main ()
{
	Struct node *root= newNode(1);
	root->left = newNode(2);

}