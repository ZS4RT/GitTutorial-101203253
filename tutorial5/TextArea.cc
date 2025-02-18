#include "TextArea.h"
#include <iostream>

TextArea::TextArea() : rect{0,0,0,0}, id(""), text(""), fill(RGB::BLACK()), border(RGB::BLACK()) {}

TextArea::TextArea(int x, int y, int w, int h, const string& id, const string& text)
    : rect{x, y, w, h}, id(id), text(text), fill(RGB::BLACK()), border(RGB::BLACK()) {}

TextArea::TextArea(const Rectangle& r, const string& id, const string& text)
    : rect(r), id(id), text(text), fill(RGB::BLACK()), border(RGB::BLACK()) {}

TextArea::TextArea(const TextArea& other)
    : rect(other.rect), id(other.id), text("DUPLICATE"), fill(other.fill), border(other.border) {}

void TextArea::setFill(const RGB& color) { fill = color; }
void TextArea::setBorder(const RGB& color) { border = color; }

bool TextArea::overlaps(const TextArea& other) const {
    return rect.overlaps(other.rect);
}



void TextArea::print() const {
    cout << "TextArea ID: " << id << "\n"
         << "Position: (" << rect.x << ", " << rect.y << ")\n"
         << "Size: " << rect.width << "x" << rect.height << "\n"
         << "Text: " << text << "\n" << endl;
}