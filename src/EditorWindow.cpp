#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Native_File_Chooser.H>

class EditorWindow
{
public:
    EditorWindow(int x, int y, int width, int height)
        : buffer_(new Fl_Text_Buffer()), editor_(new Fl_Text_Editor(x, y, width, height)) {
        editor_->buffer(buffer_);
    }

    void show() {
        editor_->parent()->show();
    }

private:
    Fl_Text_Buffer* buffer_;
    Fl_Text_Editor* editor_;
};