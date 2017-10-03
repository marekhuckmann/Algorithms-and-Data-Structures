#include <iostream>

using namespace std;

struct bst {
    bst * p, * left, * right;
    int val;
};

bst * root = NULL;


void treeInsert(bst * & root, int x) {
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

bst * treeSearch(bst * & root, int x) {
    bst * roott = root;
    if (roott == NULL || x == roott -> val) return roott;
    if (roott -> val > x) return treeSearch(roott -> left, x);
    else return treeSearch(roott -> right, x);
}

bst * iterativeTreeSearch(bst * & root, int x) {
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


bst * treeSuccessor(bst * & rootP) {

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

void treeDelete(bst * & tree, bst * node) {
    bst * y = NULL;

    if (node -> left != NULL && node -> right != NULL)
        y = treeSuccessor(node);
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

    treeInsert(root, 14);
    treeInsert(root, 5);
    treeInsert(root, 25);
    treeInsert(root, 2);
    treeInsert(root, 13);
    treeInsert(root, 81);
    treeInsert(root, 2137);
    treeInsert(root, 4);

    bst * sth = root -> left;

    inorder(root);
    cout << endl;

    cout << treeSearch(root, 13) << " = " << treeSuccessor(sth) << endl;
    treeDelete(root, sth);
    inorder(root);
    cout << endl;


    system("pause");
    return 0;
}
