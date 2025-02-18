#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "defs.h"
#include "RGB.h"
#include <string>

using namespace std; // Add this line

class TextArea {
private:
    Rectangle rect;
    string id;
    string text;
    RGB fill;
    RGB border;
public:
    TextArea();
    TextArea(int x, int y, int width, int height, const string& id, const string& text);
    TextArea(const Rectangle& rect, const string& id, const string& text);
    TextArea(const TextArea& other);
    std::string getID() const;
    void setFill(const RGB& color);
    void setBorder(const RGB& color);
    bool overlaps(const TextArea& other) const;
    void print() const;
    // Getters
    const Rectangle& getRect() const { return rect; }
    const string& getId() const { return id; }
    const string& getText() const { return text; }
    const RGB& getFill() const { return fill; }
    const RGB& getBorder() const { return border; }
};

#endif