#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<ctime>
#include<chrono>
#include<fstream>
#include<vector>

//template <typename T>
//void rbtree_out(std::ofstream fout, const RedBlackTree<T>& rbt, Node<T>* node = rbt.root);

template <typename T>
struct Node {
  public:
    T data;
    std::string color;
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;

    // Constructor to initialize node with data and color
    Node(T value) : data(value), color("red"), parent(nullptr), left(nullptr), right(nullptr) {}
};

template <typename T>
class RedBlackTree {
    //friend void rbtree_out(std::ofstream fout, const RedBlackTree<T>& rbt, Node* node);

  private:
    Node<T>* root; // Root of the Red-Black Tree

    // Utility function: Left Rotation
    void rotateLeft(Node<T>*& node)
    {
        Node<T>* child = node->right;
        node->right = child->left;
        if (node->right != nullptr) {
            node->right->parent = node;
        }
        child->parent = node->parent;
        if (node->parent == nullptr) {
            root = child;
        } else if (node == node->parent->left) {
            node->parent->left = child;
        } else {
            node->parent->right = child;
        }
        child->left = node;
        node->parent = child;
    }

    // Utility function: Right Rotation
    void rotateRight(Node<T>*& node)
    {
        Node<T>* child = node->left;
        node->left = child->right;
        if (node->left != nullptr) {
            node->left->parent = node;
        }
        child->parent = node->parent;
        if (node->parent == nullptr) {
            root = child;
        } else if (node == node->parent->left) {
            node->parent->left = child;
        } else {
            node->parent->right = child;
        }
        child->right = node;
        node->parent = child;
    }

    // Utility function: Fixing Insertion Violation
    void fixInsert(Node<T>*& node)
    {
        Node<T>* parent = nullptr;
        Node<T>* grandparent = nullptr;
        while (node != root && node->color == "red" && node->parent->color == "red") {
            parent = node->parent;
            grandparent = parent->parent;
            if (parent == grandparent->left) {
                Node<T>* uncle = grandparent->right;
                if (uncle != nullptr && uncle->color == "red") {
                    grandparent->color = "red";
                    parent->color = "black";
                    uncle->color = "black";
                    node = grandparent;
                } else {
                    if (node == parent->right) {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            } else {
                Node<T>* uncle = grandparent->left;
                if (uncle != nullptr && uncle->color == "red") {
                    grandparent->color = "red";
                    parent->color = "black";
                    uncle->color = "black";
                    node = grandparent;
                } else {
                    if (node == parent->left) {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }
        root->color = "black";
    }

    // Utility function: Fixing Deletion Violation
    void fixDelete(Node<T>*& node)
    {
        while (node != root && node->color == "black") {
            if (node == node->parent->left) {
                Node<T>* sibling = node->parent->right;
                if (sibling->color == "red") {
                    sibling->color = "black";
                    node->parent->color = "red";
                    rotateLeft(node->parent);
                    sibling = node->parent->right;
                }
                if ((sibling->left == nullptr || sibling->left->color == "black") && (sibling->right == nullptr || sibling->right->color == "black")) {
                    sibling->color = "red";
                    node = node->parent;
                }
                else {
                    if (sibling->right == nullptr || sibling->right->color == "black") {
                        if (sibling->left != nullptr) {
                            sibling->left->color = "black";
                        }
                        sibling->color = "red";
                        rotateRight(sibling);
                        sibling = node->parent->right;
                    }
                    sibling->color = node->parent->color;
                    node->parent->color = "black";
                    if (sibling->right != nullptr) {
                        sibling->right->color = "black";
                    }
                    rotateLeft(node->parent);
                    node = root;
                }
            } else {
                Node<T>* sibling = node->parent->left;
                if (sibling->color == "red") {
                    sibling->color = "black";
                    node->parent->color = "red";
                    rotateRight(node->parent);
                    sibling = node->parent->left;
                }
                if ((sibling->left == nullptr || sibling->left->color == "black") && (sibling->right == nullptr || sibling->right->color == "black")) {
                    sibling->color = "red";
                    node = node->parent;
                }
                else {
                    if (sibling->left == nullptr || sibling->left->color == "black") {
                        if (sibling->right != nullptr) {
                            sibling->right->color = "black";
                        }
                        sibling->color = "red";
                        rotateLeft(sibling);
                        sibling = node->parent->left;
                    }
                    sibling->color = node->parent->color;
                    node->parent->color = "black";
                    if (sibling->left != nullptr) {
                        sibling->left->color = "black";
                    }
                    rotateRight(node->parent);
                    node = root;
                }
            }
        }
        node->color = "black";
    }

    // Utility function: Find Node with Minimum Value
    Node<T>* minValueNode(Node<T>*& node)
    {
        Node<T>* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // Utility function: Transplant nodes in Red-Black Tree (change u to v)
    void transplant(Node<T>*& root, Node<T>*& u, Node<T>*& v)
    {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v != nullptr)
            v->parent = u->parent;
    }

    // Utility function: Delete all nodes in the Red-Black Tree
    void deleteTree(Node<T>* node)
    {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

  public:
    // Constructor: Initialize Red-Black Tree
    RedBlackTree() : root(nullptr) {}

    // Destructor: Delete Red-Black Tree
    ~RedBlackTree() { deleteTree(root); }

    // Public function: Insert a value into Red-Black Tree
    void insert(T key)
    {
        Node<T>* node = new Node(key);
        Node<T>* parent = nullptr;
        Node<T>* current = root;
        while (current != nullptr) {
            parent = current;
            if (node->data < current->data)
                current = current->left;
            else
                current = current->right;
        }
        node->parent = parent;
        if (parent == nullptr)
            root = node;
        else if (node->data < parent->data)
            parent->left = node;
        else
            parent->right = node;
        fixInsert(node);
    }

    // Public function: Remove a value from Red-Black Tree
    void remove(T key)
    {
        Node<T>* node = root;
        Node<T>* z = nullptr;
        Node<T>* x = nullptr;
        Node<T>* y = nullptr;
        while (node != nullptr) {
            if (node->data == key) {
                z = node;
            }
            if (node->data <= key) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }

        if (z == nullptr) {
            std::cout << "Key not found in the tree" << std::endl;
            return;
        }

        y = z;
        std::string yOriginalColor = y->color;
        if (z->left == nullptr) {
            x = z->right;
            transplant(root, z, z->right);
        }
        else if (z->right == nullptr) {
            x = z->left;
            transplant(root, z, z->left);
        }
        else {
            y = minValueNode(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z) {
                if (x != nullptr)
                    x->parent = y;
            } else {
                transplant(root, y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(root, z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (yOriginalColor == "black") {
            fixDelete(x);
        }
    }

    friend void rbtree_out<T>(std::ofstream& fout, const RedBlackTree<T>& rbt, Node<T>* node);
};

template <typename T>
void rbtree_out(std::ofstream& fout, const RedBlackTree<T>& rbt, Node<T>* node = nullptr) {
    if(node == nullptr)
        node = rbt.root;
    if(node->left != nullptr)
        rbtree_out(fout, rbt, node->left);
    fout << node->data.id << " " << node->data.author << " " << node->data.title << "\n";
    if(node->right != nullptr)
        rbtree_out(fout, rbt, node->right);
}

class Book {
  public:
    int id;
    std::string author;
    std::string title;
    
    Book(int i = 0, std::string a = "Unknown", std::string t = "Unknown") : id(i), author(a), title(t) {}
};

bool operator<(const Book& a, const Book& b) {
    return a.id < b.id;
}

bool operator<=(const Book& a, const Book& b) {
    return a.id <= b.id;
}

bool operator==(const Book& a, const Book& b) {
    return a.id <= b.id;
}

int main()
{
    int a;
    Book x = Book();
    std::srand(std::time(0));
    RedBlackTree<Book> rbtree;
    std::map<int, Book> mapp;
    std::ofstream(fout);
    fout.open("output.txt");

    for(int i = 0; i < 10000; i++) 
        a = std::rand();
        x = Book(a, std::to_string(a), std::to_string(a));
        mapp[a] = x;
        rbtree.insert(x);

    rbtree_out<Book>(fout, rbtree);

    std::vector<Book> q;
    for(int i = 0; i < 100; i++) 
        a = std::rand();
        x = Book(a, std::to_string(a), std::to_string(a));
        q.push_back(x);
    
    std::cout << "Red-Black Tree | std::map\n\nAdding 100 elements:\n";
    auto t0 = std::chrono::high_resolution_clock::now();
    for(auto it = q.begin(); it != q.end(); ++it)
        rbtree.insert(*it);
    auto t1 = std::chrono::high_resolution_clock::now();
    for(auto it = q.begin(); it != q.end(); ++it)
        mapp[it->id] = *it;
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0) << " | " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1) << "\n\nRemoving 100 elements:\n";

    t0 = std::chrono::high_resolution_clock::now();
    for(auto it = q.begin(); it != q.end(); ++it)
        rbtree.insert(*it);
    t1 = std::chrono::high_resolution_clock::now();
    for(auto it = q.begin(); it != q.end(); ++it)
        mapp[it->id] = *it;
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0) << " | " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1) << "\n";
}