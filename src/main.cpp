#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Editor.H>

#include "globals.cpp"
#include "EditorWindow.cpp"
#include "Menubar.cpp"
// #include "SearchWindow.cpp"

int main(int argc, char *argv[]) {
    textbuf = new Fl_Text_Buffer;
    Fl_Window *window = new Fl_Window(800, 600, "Simple text editor");
    
    SearchWindow searchWindow;
    Menubar *menuBar = new Menubar(0, 0, window->w(), 25, &searchWindow);
    
    Fl_Text_Editor *editor = new Fl_Text_Editor(10, 25, window->w() - 15, window->h() - 30);
    editor->buffer(textbuf);

    window->end();
    window->show(argc, argv);
    return Fl::run();
}