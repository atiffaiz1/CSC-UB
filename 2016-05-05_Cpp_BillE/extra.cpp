//
// Created by Bill on 4/30/2016.
//
int main(){
    char (*array)[11] = new char[5][11];
    for (int k = 0; k < 5; ++k){
        strcpy(array[k], "hellohello");
    }
    for (int k = 0; k < 5; ++k) cout << array[k] << endl;

    for (int k = 0; k < 5; ++k) delete[] array[k];
    delete array;
}


class Shape {// An abstract class
public:
    virtual void draw() = 0;//pure virtual function
    virtual void rotate(int i) = 0;
    virtual bool is_closed() = 0;//pure virtual function
    virtual ~Shape() { }//empty virtual destructor
};

class Circle: public Shape {// Circle is derived from Shape
private:
    int x;//coordinates of center
    int y;
    double r;
public:
    Circle(int,int,double);
    void rotate(int) { }
    void draw();
    bool is_closed() { return true; }
};

class Polygon: public Shape{//An abstract class derived from Shape
public:
    bool is_closed() { return true; }
};

class Square: public Polygon{// Square is derived from Polygon
private:
    int* corners;//coordinates of corners even indices x coord odd indices y coord
public:
    Square(int, int);
    ~Square() { delete[] corners}
    void rotate(int);
    void draw();
};