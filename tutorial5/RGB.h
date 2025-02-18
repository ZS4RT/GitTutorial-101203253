#ifndef RGB_H
#define RGB_H

class RGB {
private:
    int r, g, b;
public:
    RGB(int red, int green, int blue);
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();
    static RGB WHITE();
    static RGB BLACK();
    int getR() const;
    int getG() const;
    int getB() const;
};

#endif