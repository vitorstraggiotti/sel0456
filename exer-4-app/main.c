/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Aplication with graphical interface to calculate wire cross section and 
 * recomended fuse based on wire length and current
 *
 * Author: Vitor Henrique Andrade Helfensteller Straggiotti Silva
 * Start date: 31/10/2021
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
#include <stdlib.h>

#include <gtk/gtk.h>
 
void button_calcular(GtkWidget *widget, gpointer data);
void destroy(GtkWidget *widget, gpointer data);

GtkBuilder	*Builder;

GtkWidget	*LabelWireSection;
GtkWidget	*LabelFuse;
GtkWidget	*Window;
GtkWidget	*ButtonCalcular;

int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	
	Builder = gtk_builder_new_from_file("interface.glade");
	
/*	gtk_builder_add_callback_symbols(Builder,
									 (const gchar *)"destroy", G_CALLBACK(destroy),
									 (const gchar *)"on_buttonCalcular_clicked",
									 		G_CALLBACK(button_calcular), NULL);

	gtk_builder_connect_signals(Builder, NULL);
*/	
	Window = GTK_WIDGET(gtk_builder_get_object(Builder, "window"));
	g_signal_connect(Window, "destroy", G_CALLBACK(destroy), NULL);
	
	ButtonCalcular = GTK_WIDGET(gtk_builder_get_object(Builder, "buttonCalcular"));
	g_signal_connect(ButtonCalcular, "on_buttonCalcular_clicked", G_CALLBACK(button_calcular), NULL);
	
	gtk_builder_connect_signals(Builder, NULL);

	LabelWireSection = GTK_WIDGET(gtk_builder_get_object(Builder, "labelWireSection"));
	LabelFuse = GTK_WIDGET(gtk_builder_get_object(Builder, "labelFuse"));
	
	gtk_widget_show_all(Window);
	
	gtk_main();	
	
	return 0;
}
//==============================================================================
void destroy(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}

void button_calcular(GtkWidget *widget, gpointer data)
{
	//Read entry info
	
	//Calculate parameters
	
	//Print results
	gtk_label_set_text(GTK_LABEL(labelWireSection), (const gchar *) "Teste1");
	gtk_label_set_text(GTK_LABEL(labelFuse), (const gchar *) "Teste2");
}


