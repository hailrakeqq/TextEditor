#include "../include/Menubar.h"

Menubar::Menubar(int x, int y, int w, int h, SearchWindow* searchWindow, Fl_Text_Editor* editor, const char* label)
    : searchWindow(searchWindow), editor(editor) {
    initialMenu(w);
}
void Menubar::createAndOpenSearchWindow()
{
    searchWindow->createWindow();
    searchWindow->show();
}

void Menubar::initialMenu(int windowWidth)
{
    menuBar = new Fl_Menu_Bar(0, 0, windowWidth, 25);
    menuBar->copy(menuItems.data());
}

void Menubar::new_cb(Fl_Widget* widget, void* data) {
    std::cout << "New File menu item clicked." << std::endl;
}

void Menubar::open_cb(Fl_Widget* widget, void* data) {
    std::cout << "Open File menu item clicked." << std::endl;
}

void Menubar::save_cb(Fl_Widget* widget, void* data) {
    std::cout << "Save File menu item clicked." << std::endl;
}

void Menubar::saveas_cb(Fl_Widget* widget, void* data){
    std::cout << "Save As File menu item clicked." << std::endl;
}

void Menubar::quit_cb(Fl_Widget* widget, void* data){
    delete Fl::first_window();
}

void Menubar::undo_cb(Fl_Widget* widget, void* data){
    std::cout << "Undo menu item clicked." << std::endl;
}

void Menubar::cut_cb(Fl_Widget* widget, void* data){
    Menubar* menubar = static_cast<Menubar*>(data);
    Fl_Text_Editor::kf_cut(0, menubar->editor);
    Fl::focus(menubar->editor);
}

void Menubar::copy_cb(Fl_Widget* widget, void* data){
    Menubar* menubar = static_cast<Menubar*>(data);
    Fl_Text_Editor::kf_copy(0, menubar->editor);
    menubar->editor->take_focus();
}

void Menubar::paste_cb(Fl_Widget* widget, void* data){
    Menubar* menubar = static_cast<Menubar*>(data);
    Fl_Text_Editor::kf_paste(0, menubar->editor); 
    menubar->editor->take_focus();
}

void Menubar::delete_cb(Fl_Widget* widget, void* data){
    textbuffer->remove_selection();
}

void Menubar::find_cb(Fl_Widget* widget, void* data){
    std::cout << "Find menu item clicked." << std::endl;
    Menubar* menuBar = static_cast<Menubar*>(data);
    menuBar->createAndOpenSearchWindow();
}

void Menubar::replace_cb(Fl_Widget* widget, void* data){
    std::cout << "Replace menu item clicked." << std::endl;
}

