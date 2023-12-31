#ifndef MENUBAR_H
#define MENUBAR_H

#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Editor.H>
#include <vector>
#include <iostream>
#include "globals.h"
#include "SearchWindow.h"

class Menubar
{
public:
    Fl_Menu_Bar *menuBar;

    Menubar(int x, int y, int w, int h,  SearchWindow* searchWindow, Fl_Text_Editor* editor, const char* label = 0);
    
    static void new_cb(Fl_Widget* widget, void* data);
    static void open_cb(Fl_Widget* widget, void* data);
    static void save_cb(Fl_Widget* widget, void* data);
    static void saveas_cb(Fl_Widget* widget, void* data);
    static void quit_cb(Fl_Widget* widget, void* data);
    static void undo_cb(Fl_Widget* widget, void* data);
    static void cut_cb(Fl_Widget* widget, void* data);
    static void copy_cb(Fl_Widget *widget, void *data);
    static void paste_cb(Fl_Widget* widget, void* data);
    static void delete_cb(Fl_Widget* widget, void* data);
    static void find_cb(Fl_Widget* widget, void* data);
    static void replace_cb(Fl_Widget* widget, void* data);

private:
    SearchWindow *searchWindow;
    Fl_Text_Editor *editor;

    void createAndOpenSearchWindow();
    void initialMenu(int windowWidth);
    std::vector<Fl_Menu_Item> menuItems = {
    { "&File",              0, 0, 0, FL_SUBMENU },
      { "&New File",        0, (Fl_Callback *)new_cb },
      { "&Open File...",    FL_CTRL + 'o', (Fl_Callback *)open_cb },
      { "&Save File",       FL_CTRL + 's', (Fl_Callback *)save_cb },
      { "Save File &As...", FL_CTRL + FL_SHIFT + 's', (Fl_Callback *)saveas_cb, 0, FL_MENU_DIVIDER },
      { "E&xit", FL_CTRL + 'q', (Fl_Callback *)quit_cb, 0 },
    { 0 },
    { "&Edit", 0, 0, 0, FL_SUBMENU },
      { "&Undo",       FL_CTRL + 'z', (Fl_Callback *) undo_cb, 0, FL_MENU_DIVIDER },
      { "Cu&t",        FL_CTRL + 'x', (Fl_Callback *) cut_cb, this },
      { "&Copy",       FL_CTRL + 'c', (Fl_Callback *) copy_cb, this },
      { "&Paste",      FL_CTRL + 'v', (Fl_Callback *) paste_cb, this },
      { "&Delete",     0, (Fl_Callback *)delete_cb },
    { 0 },
    { "&Search", 0, 0, 0, FL_SUBMENU },
        { "&Find...",       FL_CTRL + 'f', (Fl_Callback *)find_cb, this},
        { "&Replace...",    FL_CTRL + 'r', replace_cb },      
        { 0 },
    { 0 }
    };
};

#endif // MENUBAR_H
