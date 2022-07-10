// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node* root, Node* nxt){
    Node* curr = (root->data <= nxt->data)? root : nxt;
    Node* ans = curr;
    
    Node* left = (curr==root)? root->bottom : root;
    Node* right = (curr== nxt)? nxt->bottom : nxt;
        
    //merge left & right nodes in curr
    while(left && right){
        if(left->data<= right->data){
            curr->bottom = left;
            curr = curr->bottom;
            left = left->bottom;
        }
        else{
            curr->bottom = right;
            curr = curr->bottom;
            right = right->bottom;   
        }
    }
        
    if(left)
        curr->bottom = left;
        
    if(right)
        curr->bottom = right;

    
    return ans;
}

Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL)
        return root;

    Node* ans = root;
    while(root->next){
        ans = merge(ans, root->next);
        root-> next = root->next->next;
    }
       
    return ans;
}

