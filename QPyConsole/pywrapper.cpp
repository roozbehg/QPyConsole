#include "pywrapper.h"

// References:
//1- https://github.com/t-cann/qtPythonConsoleCMake
//2- https://docs.python.org/3/extending/extending.html


// Construct a new py Wrapper::py Wrapper object
pyWrapper::pyWrapper() {

    program = Py_DecodeLocale("embeddingPythonWrapper", NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    Py_SetProgramName(program);  // optional but recommended 

    std::string stdOutErr =
"import sys\n\
class CatchOutErr:\n\
    def __init__(self):\n\
        self.value = ''\n\
    def write(self, txt):\n\
        self.value += txt\n\
catchOutErr = CatchOutErr()\n\
oldstdout = sys.stdout\n\
sys.stdout = catchOutErr\n\
oldstderr = sys.stderr\n\
sys.stderr = catchOutErr\n\
"; //this is python code to redirect stdouts/stderr

    Py_Initialize();

    pModule = PyImport_AddModule("__main__"); //create main module
    PyRun_SimpleString(stdOutErr.c_str()); //invoke code to redirect
    catcher = PyObject_GetAttrString(pModule,"catchOutErr"); //get our catchOutErr created above  
    PyErr_Print(); //make python print any errors
    output = PyObject_GetAttrString(catcher,"value"); //get the stdout and stderr from our catchOutErr object
}

// Destroy the py Wrapper::py Wrapper object
pyWrapper::~pyWrapper() {

    PyRun_SimpleString("sys.stdout = oldstdout");

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    Py_Finalize();
    PyMem_RawFree(program);
}

// Takes in a QString which is run in python and the output is captured and returned.
QString pyWrapper::pyRun(QString command) {

    QString input =  command; //"\"" + command + "\"";
    PyRun_SimpleString("catchOutErr.value = ''");
    PyRun_SimpleString(input.toStdString().c_str());

    catcher = PyObject_GetAttrString(pModule,"catchOutErr"); //get our catchOutErr created above
    PyErr_Print(); //make python print any errors

    output = PyObject_GetAttrString(catcher,"value"); //get the stdout and stderr from our catchOutErr object

    QString outstring = pyWrapper::ObjectToString(output);
    return outstring;
}

// Returns a QString if a PyObject is a Unicode String.
QString pyWrapper::ObjectToString(PyObject *poVal) {
    QString val;

    if(poVal != NULL) {
        if(PyUnicode_Check(poVal)) {

            // Convert Python Unicode object to UTF8 and return pointer to buffer
            const char *str = PyUnicode_AsUTF8(poVal);

            if(!hasError()) {
                val = QString::fromUtf8(str);
            }
        }

        // Release reference to object
        Py_XDECREF(poVal);
    }

    return val;
}

// Check whether Python has error if so outputs the error to stderr and clear error indicator.
bool pyWrapper::hasError() {
    bool error = false;

    if(PyErr_Occurred()) {
        // Output error to stderr and clear error indicator
        PyErr_Print();
        error = true;
    }

    return error;
}
