#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <iostream>
#include <vector>
#include "SearchWindow.cpp"

class Menubar {
public:
    Menubar(int x, int y, int w, int h,  SearchWindow* searchWindow, const char* label = 0)
    :searchWindow(searchWindow) {
        initialMenu(w);
    }

private:
    Fl_Menu_Bar *menuBar;
    SearchWindow* searchWindow;

    void createAndOpenSearchWindow() {
        searchWindow->createWindow();
        searchWindow->show();
    }

    void initialMenu(int windowWidth)
    {
        menuBar = new Fl_Menu_Bar(0, 0, windowWidth, 25);
        menuBar->copy(menuItems.data());
    }

    static void new_cb(Fl_Widget* widget, void* data) {
        std::cout << "New File menu item clicked." << std::endl;
    }

    static void open_cb(Fl_Widget* widget, void* data) {
        std::cout << "Open File menu item clicked." << std::endl;
    }

    static void save_cb(Fl_Widget* widget, void* data) {
        std::cout << "Save File menu item clicked." << std::endl;
    }

    static void saveas_cb(Fl_Widget* widget, void* data){
        std::cout << "Save As File menu item clicked." << std::endl;
    }

    static void quit_cb(Fl_Widget* widget, void* data){
        delete Fl::first_window();
    }

    static void undo_cb(Fl_Widget* widget, void* data){
        std::cout << "Undo menu item clicked." << std::endl;
    }

    static void cut_cb(Fl_Widget* widget, void* data){
        std::cout << "Cut menu item clicked." << std::endl;
    }

     static void copy_cb(Fl_Widget* widget, void* data){
        std::cout << "Copy menu item clicked." << std::endl;
    }

    static void paste_cb(Fl_Widget* widget, void* data){
        std::cout << "Paste menu item clicked." << std::endl;
    }

    static void delete_cb(Fl_Widget* widget, void* data){
        std::cout << "Delete menu item clicked." << std::endl;
    }

    static void find_cb(Fl_Widget* widget, void* data){
        std::cout << "Find menu item clicked." << std::endl;
        Menubar* menuBar = static_cast<Menubar*>(data);
        menuBar->createAndOpenSearchWindow();
    }

    static void replace_cb(Fl_Widget* widget, void* data){
        std::cout << "Replace menu item clicked." << std::endl;
    }

    std::vector<Fl_Menu_Item> menuItems = {
        { "&File",              0, 0, 0, FL_SUBMENU },
          { "&New File",        0, (Fl_Callback *)new_cb },
          { "&Open File...",    FL_CTRL + 'o', (Fl_Callback *)open_cb },
          { "&Save File",       FL_CTRL + 's', (Fl_Callback *)save_cb },
          { "Save File &As...", FL_CTRL + FL_SHIFT + 's', (Fl_Callback *)saveas_cb, 0, FL_MENU_DIVIDER },
          { "E&xit", FL_CTRL + 'q', (Fl_Callback *)quit_cb, 0 },
        { 0 },

        { "&Edit", 0, 0, 0, FL_SUBMENU },
          { "&Undo",       FL_CTRL + 'z', (Fl_Callback *)undo_cb, 0, FL_MENU_DIVIDER },
          { "Cu&t",        FL_CTRL + 'x', (Fl_Callback *)cut_cb },
          { "&Copy",       FL_CTRL + 'c', (Fl_Callback *)copy_cb },
          { "&Paste",      FL_CTRL + 'v', (Fl_Callback *)paste_cb },
          { "&Delete",     0, (Fl_Callback *)delete_cb },
        { 0 },

        { "&Search", 0, 0, 0, FL_SUBMENU },
            { "&Find...",       FL_CTRL + 'f', (Fl_Callback *)find_cb, this},
            { "&Replace...",    FL_CTRL + 'r', replace_cb },      
            { 0 },
        { 0 }
    };
};
