#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>

class SearchWindow {
public:
    SearchWindow() {}

    void createWindow() {
        window_ = new Fl_Window(300, 100, "Search");
        searchInput_ = new Fl_Input(70, 20, 200, 30, "Search:");
        searchInput_->callback(staticSearchCallback, this);
        window_->callback(staticWindowCallback, this);
        window_->set_modal();
    }

    void show() {
        window_->show();
        searchInput_->take_focus(); // Set focus to the search input field
    }

    void hide() {
        window_->hide();
    }

    const char* getSearchText() const {
        return searchInput_->value();
    }
private:
    // Fl_Window *replace_dlg;
    // Fl_Input *replace_find;
    // Fl_Input *replace_with;
    // Fl_Button *replace_all;
    // Fl_Return_Button *replace_next;
    // Fl_Button *replace_cancel;
    // char search[256];
    Fl_Window* window_;
    Fl_Input* searchInput_;

    // Static callback for the search input
    static void staticSearchCallback(Fl_Widget* widget, void* data) {
        SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
        searchWindow->onSearchCallback();
    }

    // Static callback for the search window
    static void staticWindowCallback(Fl_Widget* widget, void* data) {
        SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
        searchWindow->hide();
    }

    // Actual callback for the search input
    void onSearchCallback() {
        // Perform the search here
        const char* searchText = getSearchText();
        // Implement your search logic here
        // For demonstration purposes, let's just print the search text
        if (searchText != nullptr && *searchText != '\0') {
            printf("Searching for: %s\n", searchText);
        }
    }
};