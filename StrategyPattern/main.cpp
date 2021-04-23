#include <QCoreApplication>

class Strategy{
public:
    virtual int doOperate(int a,int b) = 0;
};

class AddStrategy : public Strategy{
public:
    virtual int doOperate(int a, int b){
        return a + b;
    }
};

class SubStrategy : public Strategy{
public:
    virtual int doOperate(int a, int b){
        return a - b;
    }
};

class MulStrategy : public Strategy{
public:
    virtual  int doOperate(int a, int b){
        return a * b;
    }
};

class Context{
public:
    Context(Strategy *strategy) : _stragety(strategy){}
    int getResult(int a,int b){
        if(_stragety)
            return _stragety->doOperate(a,b);
        throw "Bad Stragety";
    }

private:
    Strategy *_stragety = nullptr;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
