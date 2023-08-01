#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

class SearchWindow {
public:
    SearchWindow();

    void createWindow();
    void show();
    void hide();
    const char* getSearchText() const;

private:
    Fl_Button *replace_all;
    Fl_Button *replace_next;
    Fl_Button *replace_cancel;
    Fl_Window* window;
    Fl_Input* searchInput;
    Fl_Input *replaceInput;

    static void staticSearchCallback(Fl_Widget* widget, void* data);
    static void staticReplaceCallback(Fl_Widget* widget, void* data);
    static void staticReplaceAllCallback(Fl_Widget* widget, void* data);
    static void staticReplaceNextCallback(Fl_Widget* widget, void* data);
    static void staticCancelCallback(Fl_Widget* widget, void* data);
    static void staticWindowCallback(Fl_Widget* widget, void* data);

    void onSearchCallback();
    void onReplaceCallback();
    void onReplaceAllCallback();
    void onReplaceNextCallback();
    void onCancelCallback();
};

#endif // SEARCHWINDOW_H
