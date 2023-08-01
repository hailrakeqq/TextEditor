#include "../include/SearchWindow.h"

SearchWindow::SearchWindow() {}

void SearchWindow::createWindow() {
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

void SearchWindow::show() {
    window->show();
    searchInput->take_focus();
}

void SearchWindow::hide() {
    window->hide();
}

const char* SearchWindow::getSearchText() const {
    return searchInput->value();
}

void SearchWindow::staticSearchCallback(Fl_Widget* widget, void* data) {
    SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
    searchWindow->onSearchCallback();
}

void SearchWindow::staticReplaceCallback(Fl_Widget* widget, void* data) {
    SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
    searchWindow->onReplaceCallback();
}

void SearchWindow::staticReplaceAllCallback(Fl_Widget* widget, void* data){
    SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
    searchWindow->onReplaceAllCallback();
}

void SearchWindow::staticReplaceNextCallback(Fl_Widget* widget, void* data){
    SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
    searchWindow->onReplaceNextCallback();
}

void SearchWindow::staticCancelCallback(Fl_Widget* widget, void* data){
    SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
    searchWindow->onCancelCallback();
}

void SearchWindow::staticWindowCallback(Fl_Widget* widget, void* data) {
    SearchWindow* searchWindow = static_cast<SearchWindow*>(data);
    searchWindow->hide();
}

void SearchWindow::onSearchCallback() {
    const char* searchText = getSearchText();
    if (searchText != nullptr && *searchText != '\0') {
        printf("Searching for: %s\n", searchText);
    }
}

void SearchWindow::onReplaceCallback() {
    // TODO: Implement replace functionality
}

void SearchWindow::onReplaceAllCallback(){
    // TODO: Implement replace all functionality
}

void SearchWindow::onReplaceNextCallback() {
    // TODO: Implement replace next functionality
}

void SearchWindow::onCancelCallback(){
    hide();
}