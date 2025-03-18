#include <iostream>

class Node
{
public:
    Node* left;
    Node* right;
    int value;

    int subtree_size;

    Node(int _value) : value(_value), left(nullptr), right(nullptr), subtree_size(0) {}
};

class BST
{
private:
    Node* head;
    int size;

    Node* insertHelper(Node* _node, int _parent, int _value)
    {
        if (_node != nullptr)
        {
            if (_node->value == _parent)
            {   
                if (_node->left == nullptr) { _node->left = insertHelper(_node->left, _parent, _value); }
                else if (_node->right == nullptr) { _node->right =insertHelper(_node->right, _parent, _value); }

                _node->subtree_size++;

                this->size++;
            }
            else
            {
                insertHelper(_node->left, _parent, _value);
                insertHelper(_node->right, _parent, _value);
            }

            return _node;
        }     
        
        return (new Node(_value));
    }

    void inOrderHelper(Node* _node)
    {
        if (_node != nullptr)
        {
            this->inOrderHelper(_node->left);
            this->inOrderHelper(_node->right);

            std::cout << _node->value << ' ';
        }
    }

    void printHelper(Node* _node)
    {
        if (_node != nullptr)
        {
            std::cout << _node->value << ": ";
            std::cout << (_node->left != nullptr ? _node->left->value : -1) << ' ';
            std::cout << (_node->right != nullptr ? _node->right->value : -1) << ", ";
            std::cout << "size: " << _node->subtree_size << '\n';

            printHelper(_node->left);
            printHelper(_node->right);
        }
    }

    void recursiveDelete(Node* _node)
    {
        if (_node != nullptr)
        {
            this->recursiveDelete(_node->left);
            this->recursiveDelete(_node->right);

            delete _node;
        }
    }

public:
    BST(void) : head(new Node(1)), size(0) {}
    ~BST(void) { this->recursiveDelete(this->head); }

    void insert(int _parent, int _value)
    {
        this->head = this->insertHelper(this->head, _parent, _value);
    }

    void inOrder(void)
    {
        this->inOrderHelper(this->head);
        std::cout << '\n';
    }

    void print(void)
    {
        this->printHelper(this->head);
    }

    int getSize(void) { return this->size; }
}; 

int main(void)
{
    int t = 0;
    std::cin >> t;

    while (t--)
    {
        BST binaryTree;

        int n = 0;
        std::cin >> n;

        while (--n)
        {
            int parent = 0;
            int value = 0;

            std::cin >> parent >> value;
            // std::cout << parent << " " << value << '\n';

            binaryTree.insert(parent, value);
        }
        
        // binaryTree.print();
        std::cout << binaryTree.getSize() << '\n';
    }
    

    return 0;
}