#include "document.h"

int main(int argc, const char *argv[]) {
  //  lxb_status_t status;
  //  lxb_html_document_t *document;

  //  const lxb_char_t *title;
  //  size_t title_len;

  static const std::string_view html =
      "<head><title>  Oh,    my...   </title></head>";

  const std::string_view new_title = "We change title";

  /* Initialization */
  //  document = lxb_html_document_create();
  //  if (document == NULL) {
  //    FAILED("Failed to create HTML Document");
  //  }
  lexbor::document document(html);

  /* Parse HTML */
  //  status = lxb_html_document_parse(document, html, html_len);
  //  if (status != LXB_STATUS_OK) {
  //    FAILED("Failed to parse HTML");
  //  }

  /* Print HTML tree */
  //  PRINT("HTML Tree: ");
  std::cout << "HTML Tree:";
  //  serialize(lxb_dom_interface_node(document));
  document.serialize();

  std::cout << '\n';
  /* Get title */
  //  title = lxb_html_document_title(document, &title_len);
  //  if (title == NULL) {
  //    PRINT("\nTitle is empty");
  //  } else {
  //    PRINT("\nTitle: %s", title);
  //  }
  auto title = document.title();
  if (title.empty()) {
    std::cout << "Title is empty" << '\n';
  } else {
    std::cout << "Title : " << title << '\n';
  }

  /* Get raw title */
  //  title = lxb_html_document_title_raw(document, &title_len);
  //  if (title == NULL) {
  //    PRINT("Raw title is empty");
  //  } else {
  //    PRINT("Raw title: %s", title);
  //  }
  title = document.title_raw();
  if (title.empty()) {
    std::cout << "Raw title is empty" << '\n';
  } else {
    std::cout << "Raw title : " << title << '\n';
  }

  /* Set new title */
  //  PRINT("\nChange title to: %s", new_title);
  std::cout << "Change title to: " << new_title << '\n';

  //  status = lxb_html_document_title_set(document, new_title, new_title_len);
  //  if (status != LXB_STATUS_OK) {
  //    FAILED("Failed to change HTML title");
  //  }
  document.title_set(new_title);

  /* Get new title */
  //  title = lxb_html_document_title(document, &title_len);
  //  if (title == NULL) {
  //    PRINT("New title is empty");
  //  } else {
  //    PRINT("New title: %s", title);
  //  }
  title = document.title();
  if (title.empty()) {
    std::cout << "New title is empty" << '\n';
  } else {
    std::cout << "New title : " << title << '\n';
  }

  /* Print HTML tree after change title */
  //  PRINT("\nHTML Tree after change title: ");
  //  serialize(lxb_dom_interface_node(document));
  std::cout << "\nHTML Tree after change title: " << '\n';
  document.serialize();

  /* Destroy document */
  //  lxb_html_document_destroy(document);

  return 0;
}
