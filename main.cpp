#include <QtGui/QApplication>

#include"welcomedialog.h"

#include"itemlist.h"
#include"QTime"
#include"fstream"
#include"QSplashScreen"
using namespace std;
ofstream logfile;

void SimpleLoggingHandler(QtMsgType type, const char *msg)
{
    switch (type) {
    case QtDebugMsg:
        logfile << QTime::currentTime().toString().toAscii().data() << " Debug: " << msg << "\n";
        break;
    case QtCriticalMsg:
        logfile << QTime::currentTime().toString().toAscii().data() << " Critical: " << msg << "\n";
        break;
    case QtWarningMsg:
        logfile << QTime::currentTime().toString().toAscii().data() << " Warning: " << msg << "\n";
        break;
    case QtFatalMsg:
        logfile << QTime::currentTime().toString().toAscii().data() <<  " Fatal: " << msg << "\n";
        abort();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //logfile
    logfile.open("./logfile.txt", ios::app);
    qInstallMsgHandler(SimpleLoggingHandler);



    //create QSplashScreen
    QSplashScreen *splash=new QSplashScreen(QPixmap("./images/cafelogo.png"));
    splash->show();
    // NOW u can call ur code that u wanna exec indisguise behind Splash ;)

    welcomeDialog w;
    Qt::Alignment mms=Qt::AlignBottom | Qt::AlignLeft;
     // Establishing connections
    splash->showMessage("Connecting to DataBase",mms,Qt::gray);

#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.show();
#endif

    splash->finish(&w);

    return a.exec();
}
