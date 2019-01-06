#include "repo_unity.h"

WId RepoUnity::wid = 0;

RepoUnity::RepoUnity() : QObject()
{
//    this->wid = wid;
}

void RepoUnity::runUnity()
{
    //GET FILE
    QString fileName = "C:/Users/jozef/Dropbox (3D Repo)/3D Repo Team Folder/Release/3drepounity/3D Repo Unity 2.8.0/3D Repo Unity 2_8_0.exe";

    // PASS ARGS
    QString _args = QString("%1").arg(wid);

    //
//    PROCESS_INFORMATION procInfo = {0};
//    STARTUPINFO startupInfo = {0};
//    startupInfo.cb = sizeof(startupInfo);
//    startupInfo.dwFlags = STARTF_USESTDHANDLES;
//    startupInfo.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
//    startupInfo.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//    startupInfo.hStdError = GetStdHandle(STD_ERROR_HANDLE);

//    //
//    HWND hwnd = (HWND) uwid;
//    LPWSTR cmd = (LPWSTR) fileName.utf16();
//    LPWSTR args = (LPWSTR) _args.utf16();



    QProcess *process = new QProcess();
//       process.setCreateProcessArgumentsModifier([] (QProcess::CreateProcessArguments *args)
//       {
//           args->flags |= CREATE_NEW_CONSOLE;
//           args->arguments = (QString("-parentHWND %1").arg(wid)).utf16();
//           args->startupInfo->dwFlags &= ~STARTF_USESTDHANDLES;
//           args->startupInfo->dwFlags |= STARTF_USEFILLATTRIBUTE;
//           args->startupInfo->dwFillAttribute = BACKGROUND_BLUE | FOREGROUND_RED
//                                              | FOREGROUND_INTENSITY;
//       });
       process->start(fileName, QStringList() << "-parentHWND" << _args);
//        process.waitForFinished(-1);


//       process.waitForStarted(-1);
        qDebug() << wid;


//    BOOL bProcessStarted = QProcess::CreateProcess(cmd,args , NULL, NULL, TRUE, CREATE_NO_WINDOW,
//                                         NULL, NULL, &startupInfo, &procInfo);
//    if(!bProcessStarted) ;// TODO: show error

    //WAIT FOR START
    qint64 before = QDateTime::currentMSecsSinceEpoch();
//    Sleep(100);
    //  WaitForInputIdle(ProcessInfo.hProcess, INFINITE);
    qint64 after = QDateTime::currentMSecsSinceEpoch();
//    qDebug() << "Waited " << (after-before);

    //GET UNITY WINDOW HANDLE
//    EnumChildWindows(hwnd, MainWindow::EnumChildGet, 0);
}
