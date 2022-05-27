# QPyConsole

This simple project demonstrates the embedding of python interpreter into C++/QT application.

# What's Next?

Using pybind11 or PythonQt to create Python bindings to existing C++ code.

# Pre-Requisites / Versions used to build

1) Qt 5.15.1 ( QTCore + QTWidgets)
2) Python 3.8 + Dev and Libs  ( need headers (.h) and libraries (.so/.a) )

# Build

1) Make sure Python is installed in your computer.
2) Open "QPyConsole.pro" and make sure link to python folder and it's libraries are correct (i.e. modify "/Python/Python38-32/" and "libs -lpython38" )
3) Open QtCreator then open "QPyConsole.pro" file and build the project.

# Screenshot

![](https://github.com/roozbehg/QPyConsole/blob/master/screenshots/QPyConsole.png)

# Contact

* www.roozbehgm.com
* www.geowizard.org

# References

* https://forum.qt.io/topic/28765/command-terminal-using-qtextedit/3
* https://github.com/t-cann/qtPythonConsoleCMake
* https://docs.python.org/3/extending/extending.html
