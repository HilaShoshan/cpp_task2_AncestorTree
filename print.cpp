void printTree(Node* root)
{
        if (root == NULL)
        {
                return;
        }

        cout << root->val << endl;
        printSubtree(root, "");
        cout << endl;
}

void printSubtree(Node* root, const string& prefix)
{
        if (root == NULL)
        {
                return;
        }

        bool hasLeft = (root->left != NULL);
        bool hasRight = (root->right != NULL);

        if (!hasLeft && !hasRight)
        {
                return;
        }

        cout << prefix;
        cout << ((hasLeft  && hasRight) ? "├── " : "");
        cout << ((!hasLeft && hasRight) ? "└── " : "");

        if (hasRight)
        {
                bool printStrand = (hasLeft && hasRight && (root->right->right != NULL || root->right->left != NULL));
                string newPrefix = prefix + (printStrand ? "│   " : "    ");
                cout << root->right->val << endl;
                printSubtree(root->right, newPrefix);
        }

        if (hasLeft)
        {
                cout << (hasRight ? prefix : "") << "└── " << root->left->val << endl;
                printSubtree(root->left, prefix + "    ");
        }
}
