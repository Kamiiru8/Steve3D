#include<QApplication>
#include"steve.hpp"

int main(int argc, char **argv){
    QApplication a(argc, argv);
    GlowneOkno okno;
    okno.show();
    return a.exec();
}
