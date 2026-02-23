/// Doar functiile de insert, pentru o orientare mai buna.
void RBInsert(RBNode* z){
        // insert like in a binary search tree
        RBNode *y = RBNode::Nil;
        RBNode *x = root;
        while (!isNil(x)){
            y = x;
            x = (z->key < x->key) ? x->left : x->right;
        }
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
            if(z->parent == z->parent->parent->left){ /// Stanga
                y = z->parent->parent->right; /// unchiul
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
            else{/// Dreapta
                y = z->parent->parent->left; /// unchiul
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
