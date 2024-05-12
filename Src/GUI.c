#include <stdio.h>
#include <gtk/gtk.h>

static void click1_cb(GtkButton *button) {
	const char *s;

	s = gtk_button_get_label(button);
	if(g_strcmp0(s,"Hello World")==0)
		gtk_button_set_label(button,"Exit");
	else
		gtk_button_set_label(button,"Hello World");
}

static void click2_cb(GtkButton *button,GtkWindow *window) {
	gtk_window_destroy(window);
}

static void app_activate (GApplication *app) {
	GtkWidget *window;
	GtkWidget *box;
	GtkWidget *button1;
	GtkWidget *button2;
	GtkWidget *Scroll;
	GtkWidget *TextView;
	GtkTextBuffer *TextBuffer;
	gchar *text;

	text = "line 1\n"
		"line 2\n"
		"line 2\n"
		"line 3\n";
	
	window = gtk_application_window_new (GTK_APPLICATION (app));
	gtk_window_set_title (GTK_WINDOW (window), "TITLE");
	gtk_window_set_default_size (GTK_WINDOW (window), 400,300);
	
	Scroll = gtk_scrolled_window_new();
	gtk_window_set_child(GTK_WINDOW(window),Scroll);

	TextView = gtk_text_view_new();
	TextBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(TextView));
	gtk_text_buffer_set_text(TextBuffer,text,-1);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(TextView),GTK_WRAP_WORD_CHAR);
	
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
	gtk_box_set_homogeneous(GTK_BOX(box),TRUE);
	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(Scroll),box);

	button1=gtk_button_new_with_label("Hello World");
	g_signal_connect(button1,"clicked",G_CALLBACK(click1_cb),NULL);

	button2=gtk_button_new_with_label("Close");
	g_signal_connect(button2,"clicked",G_CALLBACK(click2_cb),window);

	gtk_box_append(GTK_BOX(box),TextView);
	gtk_box_append(GTK_BOX(box),button1);
	gtk_box_append(GTK_BOX(box),button2);

	gtk_window_present(GTK_WINDOW(window));
}

int main (int argc, char **argv) {
	GtkApplication *app;
	int stat;

	app = gtk_application_new ("com.poop.toilet.splash", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
	stat =g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

return stat;
}
