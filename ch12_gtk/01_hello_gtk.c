#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) {
  g_print("Hello World\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Hello GTK+3.0");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

  GtkButtonBox *button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add(GTK_CONTAINER(window), button_box);
  GtkButton *button = gtk_button_new_with_label("Press me!");
  gtk_container_add(GTK_CONTAINER(button_box), button);

  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_close), window);

  gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
  GtkApplication *app = gtk_application_new("hello_gtk.shingo", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  int status = g_application_run(app, argc, argv);

  g_object_unref(app);

  return 0;
}
