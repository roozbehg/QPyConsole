#ifndef PYWRAPPER_H
#define PYWRAPPER_H
#define PY_SSIZE_T_CLEAN


#pragma push_macro("slots")
#undef slots
#include "Python.h"
#pragma pop_macro("slots")

#include <QDebug>
#include <QString>
#include <string>

class pyWrapper
{
private:
    wchar_t *program;
    bool hasError();
    PyObject *catcher;
    PyObject *output;
    PyObject *pModule;

public:
    pyWrapper();
    ~pyWrapper();
    QString pyRun(QString );
    QString ObjectToString(PyObject*);
};


#endif //PYWRAPPER_H
