class Codec {
    TreeNode* makeTree(queue<string> &q) {
        string s = q.front();
        q.pop();
        if(s=="null")
            return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = makeTree(q);
        root->right = makeTree(q);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "null,";
      return to_string(root->val)+","+ serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s ="";
        queue <string> q;
        for(char c: data) {
            if(c ==',') {
                q.push(s);
                s="";
                continue;
            }
            s+=c;
        }
        return makeTree(q);
    }
};