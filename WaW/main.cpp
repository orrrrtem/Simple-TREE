#include <iostream>
#include <fstream>

using namespace std;


struct NODE{
    char ch;
    unsigned long count;
    NODE *left;
    NODE *right;
};

NODE* addToTree(NODE* root, char ch){
    if(root == nullptr){
        root = new NODE;
        root->ch = ch;
        root->count = 1;
        root->left = root->right = nullptr;
    }
    else if(root->ch>ch)
        root->left = addToTree(root->left, ch);
    else if(root->ch < ch)
        root->right = addToTree(root->right, ch);
    else if(root->ch=ch)
        root->count++;
    return root;

}

void printTree(NODE* root){
    if(root){
        printTree(root->left);
        cout << root->ch<< " "<< root->count << endl;
        printTree(root->right);
    }
}

int main() {


    ifstream f("/Users/artemaroslankin/Documents/Progacpp/WaW/WaW.txt");
    //f.open("WaW.txt");
    if(f.fail()){
        cout <<" error reading";
        return 0;
    }

    NODE* root = nullptr;
    while(!f.eof())
        root = addToTree(root, (char)f.get());
    f.close();
    printTree(root);
    return 0;
}