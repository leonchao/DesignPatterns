#include <QCoreApplication>

class Game{
public:
    virtual void init() = 0;
    virtual void startPlay() = 0;
    virtual int endPlay() = 0;
    void play() final{
        init();
        startPlay();
        endPlay();
    }
};

class BasketballGame : public Game{
public:
    virtual void init(){

    }
    virtual void startPlay(){

    }
    virtual int endPlay(){

    }
};

class FootballGame : public Game{
public:
    virtual void init(){

    }
    virtual void startPlay(){

    }
    virtual int endPlay(){

    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
