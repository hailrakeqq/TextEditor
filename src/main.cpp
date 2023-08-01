#include "../include/Menubar.h"

int main(int argc, char *argv[]) {
    Fl_Window *window = new Fl_Window(800, 600, "Simple text editor");

    SearchWindow *searchWindow;

    Fl_Text_Editor *editor = new Fl_Text_Editor(10, 28, window->w() - 15, window->h() - 30);
    editor->take_focus(); 

    Menubar *menubar = new Menubar(0, 0, window->w(), 25, searchWindow, editor);

    editor->buffer(*textbuffer);

    window->end();
    window->show(argc, argv);
    return Fl::run();
}