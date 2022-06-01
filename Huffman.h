#pragma once
#include "huffman_tree_node.h"
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
class huffman_coding
{
private:
    pointer_huffman root_;
    std::map <char, std::string> replace_acb;
    std::string encode;
    std::string decode;
public:
    struct compare
    {
        bool operator()(Node* l, Node* r)
        {
            return ((*l).freq_ > (*r).freq_);
        }
    };
    void printCodes(Node* root, std::string str);                        
    void HuffmanCodes(std::string ch, int freq[], bool flag);                                                                                    
    void encode_text(std::string text);                                              
    std::string get_encode();                                                         
    void output_file(std::string filename, bool flag);                                                                      
    std::string decode_text(std::string str, bool flag);                           
};
void huffman_coding::output_file(std::string filename, bool flag)
{
    std::fstream file;
    file.open(filename, std::ios::out);
    if (flag)
    {
        for (int i = 0; i < encode.size(); ++i) file << encode[i];       
    }
    else 
    {
        for (int i = 0; i < decode.size();++i) file << decode[i];
    }
    file.close();
}
std::string huffman_coding::get_encode()
{
    return encode;
}
void huffman_coding::encode_text(std::string text)
{
    for (int i = 0; i < text.size(); ++i)
    {
        for (auto it = replace_acb.begin(); it != replace_acb.end(); ++it)
        {
            if (text[i] == it->first) encode += it->second;
        }
    }
}
void huffman_coding::printCodes(Node* root, std::string str)
{
    if (!root)
    {
        return;
    }

    if (root->ch_ != '*')
    {
        std::cout << root->ch_ << ": " << str << std::endl;
        replace_acb.insert(std::pair <char, std::string>(root->ch_, str));
    }
    printCodes(root->l, str + "0");
    printCodes(root->r, str + "1");
}
void huffman_coding::HuffmanCodes(std::string ch, int freq[], bool flag)
{
    pointer_huffman left, right, top;
    std::priority_queue<pointer_huffman, std::vector<Node*>, compare> min_heap;
    for (int i = 0; i < ch.size(); ++i)
    {
        pointer_huffman temp = new Node(ch[i], freq[i]);
        min_heap.push(temp);
    }
    while (min_heap.size() != 1)
    {
        left = min_heap.top();
        min_heap.pop();
        right = min_heap.top();
        min_heap.pop();
        top = new Node('*', (*left).freq_ + (*right).freq_);
        (*top).l = left;
        (*top).r = right;
        min_heap.push(top);
    }
    root_ = min_heap.top();
    if (flag) printCodes(root_, "0");
    else printCodes(root_, "");    
}



