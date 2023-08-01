#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

class SearchWindow {
public:
    SearchWindow() {}

    void createWindow() {
        window = new Fl_Window(300, 105, "Search");
        
        searchInput = new Fl_Input(70, 10, 200, 25, "Find:");
        searchInput->callback(staticSearchCallback, this);

        replaceInput = new Fl_Input(70, 40, 200, 25, "Replace:");
        replaceInput->callback(staticReplaceCallback, this);

        replace_all = new Fl_Button(10, 70, 90, 25, "Replace All");
        replace_all->callback(staticReplaceAllCallback, this);

        replace_next = new Fl_Button(105, 70, 120, 25, "Replace Next");
        replace_next->callback(staticReplaceNextCallback, this);

        replace_cancel = new Fl_Button(230, 70, 60, 25, "Cancel");
        replace_cancel->callback(staticCancelCallback, this);

        window->callback(staticWindowCallback, this);
        window->set_modal();
    }

    void show() {
        window->show();
        searchInput->take_focus();
    }

    void hide() {
        window->hide();
    }

    const char* getSearchText() const {
        return searchInput->value();
    }
private:
    Fl_Button *replace_all;
    Fl_Button *replace_next;
    Fl_Button *replace_cancel;
    Fl_Window* window;
    Fl_Input* searchInput;
    Fl_Input *replaceInput;

    static void staticSearchCallback(Fl_Widget* widget, void* data) {
        SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
        searchWindow->onSearchCallback();
    }

    static void staticReplaceCallback(Fl_Widget* widget, void* data) {
        SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
        searchWindow->onReplaceCallback();
    }

    static void staticReplaceAllCallback(Fl_Widget* widget, void* data){
        SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
        searchWindow->onReplaceAllCallback();
    }

    static void staticReplaceNextCallback(Fl_Widget* widget, void* data){
        SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
        searchWindow->onReplaceNextCallback();
    }

    static void staticCancelCallback(Fl_Widget* widget, void* data){
        SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
        searchWindow->onCancelCallback();
    }

    static void staticWindowCallback(Fl_Widget* widget, void* data) {
        SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
        searchWindow->hide();
    }

    void onSearchCallback() {
        const char* searchText = getSearchText();
        if (searchText != nullptr && *searchText != '\0') {
            printf("Searching for: %s\n", searchText);
        }
    }

    void onReplaceCallback() {
        
    }

    void onReplaceAllCallback(){

    }

    void onReplaceNextCallback() {

    }

    void onCancelCallback(){
        hide();
    }
};