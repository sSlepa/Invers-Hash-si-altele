///https://cses.fi/problemset/task/1662/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
 
using namespace std;
 
struct RBNode{
 
    long long key;       
    int fr;
    RBNode *parent;
    RBNode *left;   
    RBNode *right;  
    enum color { RED, BLACK };
    color col;
 
    static RBNode* Nil; 
 
    RBNode(long long k, int f, RBNode *l = Nil, RBNode *r = Nil, RBNode *p = Nil, color c = RBNode::BLACK) :
        key(k), fr(f), parent(p), left(l), right(r), col(c) { }
 
    ~RBNode(){
        if (this != Nil){
            if(left != Nil)
                delete left;
            if(right != Nil)
                delete right;
        }
    }
};
 
RBNode* RBNode::Nil = new RBNode(0,0);
 
struct RBTree{
    RBNode* root;
    RBTree(){
        root = RBNode::Nil;
    }
 
    RBNode* createNode(long long key){
        return new RBNode(key,1);
    }
    bool isNil(RBNode* n){
        return (n == RBNode::Nil);
    }
    RBNode* search(RBNode* w, long long key){
        if(isNil(w) || w->key == key)
            return w;
 
        return search( (key < w->key) ? w->left : w->right, key);
    }
    void LeftRotate(RBNode* x){
        RBNode* y = x->right;
        x->right = y->left;
        if (y->left != RBNode::Nil)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == RBNode::Nil)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }
    void RightRotate(RBNode* y){
        RBNode* x = y->left;
        y->left = x->right;
        if (x->right != RBNode::Nil)
            x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == RBNode::Nil)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        x->right = y;
        y->parent = x;
    }
    void RBInsert(RBNode* z){
        RBNode *y = RBNode::Nil;
        RBNode *x = root;
        while (!isNil(x)){
            y = x;
            if(x->key == z->key){
                x->fr++;
                return;
            }
 
            x = (z->key < x->key) ? x->left : x->right;
        }
        z->fr = 1;
        z->parent = y;
        if (isNil(y))
            root = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
        z->left = z->right = RBNode::Nil;
        z->col = RBNode::RED;
        RBInsertFixup(z);
    }
 
    void RBInsertFixup(RBNode* z){
        RBNode* y;
        while(z->parent->col == RBNode::RED){
            if(z->parent == z->parent->parent->left){ 
                y = z->parent->parent->right;
                if(y->col == RBNode::RED){
                    z->parent->col = RBNode::BLACK;
                    y->col = RBNode::BLACK;
                    z->parent->parent->col = RBNode::RED;
                    z = z->parent->parent;
                }
                else if(z == z->parent->right){
                    z = z->parent;
                    LeftRotate(z);
                    z->parent->col = RBNode::BLACK;
                    z->parent->parent->col = RBNode::RED;
                    RightRotate(z->parent->parent);
                }
                else if(z == z->parent->left){
                    z->parent->col = RBNode::BLACK;
                    z->parent->parent->col = RBNode::RED;
                    RightRotate(z->parent->parent);
                }
 
            }
            else{
                y = z->parent->parent->left; 
                if(y->col == RBNode::RED){
                    z->parent->col = RBNode::BLACK;
                    y->col = RBNode::BLACK;
                    z->parent->parent->col = RBNode::RED;
                    z = z->parent->parent;
                }
                else if(z == z->parent->left){
                    z = z->parent;
                    RightRotate(z);
                    z->parent->col = RBNode::BLACK;
                    z->parent->parent->col = RBNode::RED;
                    LeftRotate(z->parent->parent);
                }
                else if(z == z->parent->right){
                    z->parent->col = RBNode::BLACK;
                    z->parent->parent->col = RBNode::RED;
                    LeftRotate(z->parent->parent);
                }
            }
        }
        root->col = RBNode::BLACK;
    }
    
};
 
 
RBTree* RB = new RBTree();
 
int n;
long long x;
 
int main(){
 
    cin >> n;
    RB->RBInsert(RB->createNode(0));
     
    long long sum = 0, rez = 0;
    for(int i = 1 ; i <= n ; ++i){
 
        cin >> x;
        sum += x;
 
        sum %= n;
        
        while(sum < 0)
            sum += n;
 
        RBNode* caut = RB->search(RB->root,sum);
        if(!RB->isNil(caut)){
            rez += caut->fr;
        }
        RB->RBInsert(RB->createNode(sum));
 
    }
    cout << rez;
    
 
    
    
    return 0;
}
