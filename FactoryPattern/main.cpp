#include <QCoreApplication>
#include <QDebug>
enum ShapeName{
    Shape_Rectangle,
    Shape_Triangle,
    Shape_Square,
    Shape_Circle,
};

class Shape{
public:
    Shape(){}
    virtual void draw() = 0;
    virtual ~Shape(){}
};

class Rectangle : public Shape{
public:
    Rectangle(){}
    virtual void draw(){
        qDebug() << "Draw a Rectangle";
    }
};

class Triangle : public Shape{
public:
    Triangle(){}
    virtual void draw(){
        qDebug() << "Draw a Triangle";
    }
};

class Square : public Shape{
public:
    Square(){}
    virtual void draw(){
        qDebug() << "Draw a Square";
    }
};

class Circle : public Shape{
public:
    Circle(){}
    virtual void draw(){
        qDebug() << "Draw a Circle";
    }
};

class ShapeFactory{
public:
    static Shape* createShape(ShapeName name){
        switch (name) {
        case Shape_Rectangle:
            return new Rectangle();
        case Shape_Triangle:
            return new Triangle();
        case Shape_Square:
            return new Square();
        case Shape_Circle:
            return new Circle();
        default:
            return nullptr;
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Shape *shape1 = ShapeFactory::createShape(Shape_Rectangle);
    shape1->draw();
    delete shape1;
    shape1 = nullptr;

    return a.exec();
}
