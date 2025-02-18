#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include <vector>
#include <iostream>
#include <string>

class TAArray {
private:
    std::vector<TextArea*> elements;

public:
    TAArray();
    ~TAArray();
    
    void add(TextArea* textArea);
    void add(TextArea* textArea, int index); 

    TextArea* remove(int index);             
    TextArea* remove(const std::string& id); 

    TextArea* get(int index) const;         
    TextArea* get(const std::string& id) const; 

    int getSize() const;
};

#endif
