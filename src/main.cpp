#include "Context.hpp"
#include "Controller.hpp"

int main(int argc, char *argv[])
{
    Controller cntr(argc, argv);
    qDebug() << "started";
    return cntr.start();
}