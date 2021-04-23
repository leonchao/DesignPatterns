#include <QCoreApplication>
#include <QDebug>

class Shape{
public:
    Shape(){}
    ~Shape(){}
    virtual void draw() = 0;
};
class Color{
public:
    Color(){}
    ~Color(){}
    virtual void fill() = 0;
};

class Rectangle : public Shape{
public:
    Rectangle() : Shape(){}
    ~Rectangle(){}
    virtual void draw(){
        qDebug() << "Draw a Rectangle";
    }
};

class Circle : public Shape{
public:
    Circle() : Shape(){}
    ~Circle(){}
    virtual void draw(){
        qDebug() << "Draw a Circle";
    }
};

class Red : public Color{
public:
    Red() : Color(){}
    ~Red(){}
    virtual void fill(){
        qDebug() << "Fill with Red";
    }
};

class Blue : public Color{
public:
    Blue() : Color(){}
    ~Blue();
    virtual void fill(){
        qDebug() << "Fill with Blue";
    }
};

class AbstractFactory{
public:
    AbstractFactory(){}
    ~AbstractFactory(){}
    virtual Shape* createShape(QString shape) = 0;
    virtual Color* createColor(QString color) = 0;
};

class ShapeFactory : public AbstractFactory{
public:
    ShapeFactory() : AbstractFactory() {}
    ~ShapeFactory(){}
    virtual Shape* createShape(QString shape){
        if(shape == "Rectangle")
            return new Rectangle();
        else if(shape == "Circle")
            return new Circle();
        else
            return nullptr;
    }
    virtual Color* createColor(QString color){
        return nullptr;
    }
};

class ColorFactory : public AbstractFactory{
public:
    ColorFactory() : AbstractFactory() {}
    ~ColorFactory(){}
    virtual Shape* createShape(QString shape){
        return nullptr;
    }
    virtual Color* createColor(QString color){
        if(color == "Red")
            return new Red();
        else if(color == "Blue")
            return new Blue();
        else
            return nullptr;
    }
};

class FactoryProducer{
public:
    static AbstractFactory* createFactory(QString factory) throw{
        if(factory == "Shape")
            return new ShapeFactory();
        else if(factory == "Color")
            return new ColorFactory();
        else
            return nullptr;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    return a.exec();
}
