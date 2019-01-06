#ifndef REPO_UNITY_H
#define REPO_UNITY_H

#include <QFileDialog>
#include <QString>
#include <QDateTime>
#include <QObject>
#include <QProcess>
#include <QDebug>

class RepoUnity : public QObject
{
    Q_OBJECT

public:
    RepoUnity();

    Q_INVOKABLE void runUnity();

public :


    static WId wid;
};

#endif // REPO_UNITY_H
