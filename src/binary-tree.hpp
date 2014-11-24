/**
 * @file binary-tree.hpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-24
 */

#include <iostream>
#include <stack>

template<typename T, T Nil = 0>
struct BTreeNodeBase 
{ 
    typedef T value_type;
    typedef BTreeNodeBase<T> this_type;
    static const T NIL = Nil;

    value_type val; 
    this_type *left;
    this_type *right;
    BTreeNodeBase(const T &x): val(x), left(0), right(0){}
};

template<typename T>
static BTreeNodeBase<T> *makeBTreeNode(const T &v)
{
    return new BTreeNodeBase<T>(v);
}


template<typename T, T Nil = 0>
class BTreeBase
{
    static void nodeDeletor(void *ptr)
    {
        node_type *node = (node_type*)ptr;
        if(node){
            nodeDeletor(node->left);
            nodeDeletor(node->right);

            delete node;
        }
    }
public:
    typedef BTreeNodeBase<T, Nil> node_type;

    BTreeBase(node_type *root)
        : m_root(root, std::ptr_fun(nodeDeletor))
    {
    }
    BTreeBase()
        : m_root(0)
    {
    }

    BTreeBase(const BTreeBase &other)
        : m_root(other.m_root, std::ptr_fun(nodeDeletor))
    {
    }

    BTreeBase &operator=(const BTreeBase &other)
    {
        if(&other != this){
            m_root = other.m_root;
        }

        return *this;
    }

    ~BTreeBase()
    {
    }

    node_type *root()
    {
        return m_root.get();
    };

private:
    std::shared_ptr<node_type> m_root; 
};

template<typename T, T Nil>
static std::ostream &operator<<(std::ostream &os, BTreeBase<T, Nil> &tree)
{
    typedef BTreeBase<T, Nil> BTree;
    typedef BTreeBase<T, Nil>::node_type BTreeNode;

    if(tree.root()){
        std::stack<BTreeNode*> toAccess;
        toAccess.push(tree.root());
		bool first = true;

        while(toAccess.size()){
            BTreeNode* top = toAccess.top();
			toAccess.pop();

            if(!top){
                os << (first ? "" : " ") << Nil;
            }
            else{
                os << (first ? "" : " ") << top->val;
                toAccess.push(top->right);
                toAccess.push(top->left);
            }

			first = false;
        }
    }
    return os;
}



template<typename T, T Nil>
static std::istream &operator>>(std::istream &is, BTreeBase<T, Nil> &tree)
{
    if(is.eof())
        return is;

    typedef BTreeBase<T, Nil> BTree;
    typedef BTreeBase<T, Nil>::node_type BTreeNode;

    BTreeNode *root = 0;
    std::stack<BTreeNode*> toConstruct;
    std::stack<int> directs;
    T v;
    is >> v;

    if(!is.good())
        return is;

    root = makeBTreeNode(v);
    //
    BTree t(root);

    toConstruct.push(root);
    directs.push(0);

    while(!is.eof() && toConstruct.size()){
        BTreeNode *node = 0;
        is >> v;
        if(!is.good())
            v = Nil; //

        if(v != Nil){
            node = makeBTreeNode(v);
            if(directs.top() == 0)
                toConstruct.top()->left = node;
            else
                toConstruct.top()->right = node;
        }

        ++ directs.top();
        if(directs.top() == 2){
            toConstruct.pop();
            directs.pop();
        }

        if(node){
            toConstruct.push(node);
            directs.push(0);
        }
    }

    tree = t;

    return is;
}


