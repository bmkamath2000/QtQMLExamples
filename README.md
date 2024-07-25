Creating a Qt App

Install Qt Creator 9.0.1 from the site https://www.qt.io/download-dev

Upon Launching here is how it looks like:
![image](https://github.com/user-attachments/assets/bffd5351-4925-4f0b-a0b3-df946d450d40)

Create a New Qt Quick Application named Calculator2 based on QMake. It could also be
CMake based but for the present lets make a qmake based one. After creation of project right
click on the name of it in project explorer and=>
Add a class called Backend with files Backend.h and Backend.cpp. While main.qml and
main.cpp would be already created for you.
Following should be the folder structure after the changes:

![image](https://github.com/user-attachments/assets/36a80c28-bfae-472f-b9e0-3aca8e1b9984)
Modify Backend.cpp, .h, main.qml to have code in calculator2 app

Alternatively open QtCreator and open pro file, configure and run.
