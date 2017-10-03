#include <iostream>

using namespace std;

struct bst {
    bst * p, * left, * right;
    int val;
};

bst * root = NULL;


void tree_insert(bst * & root, int x) {
    bst * pom = new bst;
    pom -> val = x;
    pom -> left = pom -> right = NULL;

    bst * parent = NULL;
    bst * son = root;

    while (son) {
        parent = son;
        if (son -> val > pom -> val)
            son = son -> left;
        else son = son -> right;
    }
    pom -> p = parent;
    if (parent == NULL)
        root = pom;
    else if (parent -> val > pom -> val) parent -> left = pom;
    else parent -> right = pom;

}

void inorder(bst * & root) {
    bst * x = root;
    if (x) {
        inorder(x -> left);

        cout << x -> val << " ";

        inorder(x -> right);
    }
}

bst * tree_search(bst * & root, int x) {
    bst * roott = root;
    if (roott == NULL || x == roott -> val) return roott;
    if (roott -> val > x) return tree_search(roott -> left, x);
    else return tree_search(roott -> right, x);
}

bst * iterative_tree_search(bst * & root, int x) {
    bst * roots = root;
    while (roots != NULL && x != roots -> val) {
        if (x < roots -> val)
            roots = roots -> left;
        else roots = roots -> right;
    }
    return roots;
}

bst * min(bst * & root) {
    bst * min = root;
    while (min -> left)
        min = min -> left;
    return min;
}

bst * max(bst * & root) {
    bst * max = root;
    while (max -> right)
        max = max -> right;
    return max;
}


bst * tree_successor(bst * & rootP) {

    if (rootP == NULL) return NULL;

    if (rootP -> right != NULL)
        return min(rootP -> right);

    bst * y = rootP -> p;

    while (y != NULL && y -> right == rootP) {
        rootP = y;
        y = y -> p;
    }
    return y;


}

void tree_delete(bst * & tree, bst * node) {
    bst * y = NULL;

    if (node -> left != NULL && node -> right != NULL)
        y = tree_successor(node);
    else
        y = node;

    bst * x = NULL;

    if (y -> left != NULL)
        x = y -> left;
    else
        x = y -> right;

    if (x != NULL)
        x -> p = y -> p;

    if (y -> p != NULL) {
        if (y == y -> p -> left)
            y -> p -> left = x;
        else
            y -> p -> right = x;
    } else tree = x;
    if (y != node)
        node -> val = y -> val;
    delete y;
}


int main() {

    tree_insert(root, 14);
    tree_insert(root, 5);
    tree_insert(root, 25);
    tree_insert(root, 2);
    tree_insert(root, 13);
    tree_insert(root, 81);
    tree_insert(root, 2137);
    tree_insert(root, 4);

    bst * sth = root -> left;

    inorder(root);
    cout << endl;

    cout << tree_search(root, 13) << " = " << tree_successor(sth) << endl;
    tree_delete(root, sth);
    inorder(root);
    cout << endl;


    system("pause");
    return 0;
}