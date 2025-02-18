#include "TAArray.h"
#include <algorithm> 

TAArray::TAArray() {}

TAArray::~TAArray() {
    for (TextArea* textArea : elements) {
        delete textArea;
    }
    elements.clear();
}

void TAArray::add(TextArea* textArea) {
    elements.push_back(textArea);
}

void TAArray::add(TextArea* textArea, int index) {
    if (index < 0 || static_cast<size_t>(index) > elements.size()) {
        std::cerr << "Error: Invalid index " << index << " for add()." << std::endl;
        return;
    }
    elements.insert(elements.begin() + index, textArea);
}

TextArea* TAArray::remove(int index) {
    if (index < 0 || static_cast<size_t>(index) >= elements.size()) {
        std::cerr << "Error: Invalid index " << index << " provided for remove()." << std::endl;
        return nullptr;
    }
    TextArea* removedTextArea = elements[index];
    elements.erase(elements.begin() + index);
    return removedTextArea;
}

TextArea* TAArray::remove(const std::string& id) {
    auto it = std::find_if(elements.begin(), elements.end(), [&](TextArea* ta) {
        return ta->getId() == id;
    });

    if (it != elements.end()) {
        TextArea* removedTextArea = *it;
        elements.erase(it);
        return removedTextArea;
    }

    std::cerr << "Error: TextArea with ID '" << id << "' not found for remove()." << std::endl;
    return nullptr;
}

TextArea* TAArray::get(int index) const {
    if (index < 0 || static_cast<size_t>(index) >= elements.size()) {
        std::cerr << "Error: Invalid index " << index << " provided for get()." << std::endl;
        return nullptr;
    }
    return elements[index];
}

TextArea* TAArray::get(const std::string& id) const {
    auto it = std::find_if(elements.begin(), elements.end(), [&](TextArea* ta) {
        return ta->getId() == id;
    });

    if (it != elements.end()) {
        return *it;
    }

    std::cerr << "Error: TextArea with ID '" << id << "' not found for get()." << std::endl;
    return nullptr;
}

int TAArray::getSize() const {
    return static_cast<int>(elements.size()); 
}
