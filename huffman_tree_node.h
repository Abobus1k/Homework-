#include "Huffman.h"
#include <cstddef>

class Node
{
private:
    char ch_;                                               
    unsigned freq_;                                            
    Node*l, *r;                           
    friend class huffman_coding;
public:
    Node() {};
    Node(char ch, unsigned freq);               
};

typedef Node* pointer_huffman;
typedef Node** ppointer_huffman;

inline Node::Node(char ch, unsigned freq)
{
    l = r = nullptr;
    ch_ = ch;
    freq_ = freq;
}