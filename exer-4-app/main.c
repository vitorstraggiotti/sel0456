/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Aplication with graphical interface to calculate wire cross section and 
 * recomended fuse based on wire length and current
 *
 * Author: Vitor Henrique Andrade Helfensteller Straggiotti Silva
 * Start date: 31/10/2021
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
#include <stdlib.h>
#include <stdio.h>

#include <gtk/gtk.h>

//Callback functions
void button_calcular(GtkWidget *widget, gpointer data);
void destroy(GtkWidget *widget, gpointer data);
//Helper functions
float choose_fuse(float Current);

//Resistivity of materials at 20°C [ohm.meter]
const float RhoCopper		= 1.68e-8;
const float RhoSilver		= 1.59e-8;
const float RhoGold			= 2.44e-8;
const float RhoAluminium	= 2.65e-8;
const float RhoNickel		= 6.99e-8;
const float RhoIron			= 9.70e-8;

//Acceptable voltage drop [percentage]
const float VoltageDrop		= 2.5;

int main(int argc, char *argv[])
{
	GtkBuilder	*Builder;

	GtkWidget	*LabelWireSection;
	GtkWidget	*LabelFuse;
	GtkWidget	*Window;
	GtkWidget	*ButtonCalcular;
	
	gtk_init(&argc, &argv);
	
	Builder = gtk_builder_new_from_file("interface.glade");
	
	gtk_builder_add_callback_symbols(Builder,
									 (const gchar *)"on_window_destroy", G_CALLBACK(destroy),
									 (const gchar *)"on_buttonCalcular_clicked",
									 		G_CALLBACK(button_calcular), NULL);

	gtk_builder_connect_signals(Builder, (gpointer *)Builder);
	
	Window = GTK_WIDGET(gtk_builder_get_object(Builder, "window"));
	
	gtk_widget_show_all(Window);
	
	gtk_main();	
	
	return 0;
}
//========================== CALLBACK FUNCTIONS ================================
void destroy(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}

void button_calcular(GtkWidget *widget, gpointer data)
{
	GtkBuilder *Builder = (GtkBuilder *)data;
	char WireSection[80];
	char Fuse[80];
	float WireCurrent, WireLength, WireVoltage;
	float CrossSection, FuseValue, Rho;
	
	GtkWidget *CurrentEntry = GTK_WIDGET(gtk_builder_get_object(Builder, "input_current"));
	GtkWidget *LengthEntry = GTK_WIDGET(gtk_builder_get_object(Builder, "input_length"));
	GtkWidget *VoltageEntry = GTK_WIDGET(gtk_builder_get_object(Builder, "input_voltage"));
	GtkWidget *LabelWireSection = GTK_WIDGET(gtk_builder_get_object(Builder, "labelWireSection"));
	GtkWidget *LabelFuse = GTK_WIDGET(gtk_builder_get_object(Builder, "labelFuse"));

	//Read entry info
	WireCurrent = strtof(gtk_entry_get_text(GTK_ENTRY(CurrentEntry)), NULL);
	WireLength = strtof(gtk_entry_get_text(GTK_ENTRY(LengthEntry)), NULL);
	WireVoltage = strtof(gtk_entry_get_text(GTK_ENTRY(VoltageEntry)), NULL);
	if(WireCurrent == 0)
	{
		gtk_label_set_text(GTK_LABEL(LabelWireSection), (const gchar *) "Erro! Valor de corrente inválido");
		gtk_label_set_text(GTK_LABEL(LabelFuse), (const gchar *) "Erro! Valor de corrente inválido");
		return;
	}
	if(WireLength == 0)
	{
		gtk_label_set_text(GTK_LABEL(LabelWireSection), (const gchar *) "Erro! Valor de comprimento inválido");
		gtk_label_set_text(GTK_LABEL(LabelFuse), (const gchar *) "Erro! Valor de comprimento inválido");
		return;
	}
	if(WireVoltage == 0)
	{
		gtk_label_set_text(GTK_LABEL(LabelWireSection), (const gchar *) "Erro! Valor de tensão inválido");
		gtk_label_set_text(GTK_LABEL(LabelFuse), (const gchar *) "Erro! Valor de tensão inválido");
		return;
	}
	
	//Config resistivity value
	Rho = RhoCopper;
	
	//Calculate parameters
	CrossSection = (Rho * WireLength * WireCurrent * 1.0e6) / ((VoltageDrop / 100.0) * WireVoltage);
	sprintf(WireSection, "%.2f", CrossSection);
	
	FuseValue = choose_fuse(WireCurrent);
	if(FuseValue != 0)
		sprintf(Fuse, "%.2f", FuseValue);
	else
		sprintf(Fuse, "Sem valor comercial");
	
	//Print results
	gtk_label_set_text(GTK_LABEL(LabelWireSection), (const gchar *) WireSection);
	gtk_label_set_text(GTK_LABEL(LabelFuse), (const gchar *) Fuse);
	printf("Current: %f\n", WireCurrent);
	printf("Length: %f\n", WireLength);
	printf("Voltage: %f\n\n", WireVoltage);
}
//==================== HELPER FUNCTIONS ========================================
//Return the commercial value fuse for a given current. Return 0 if not found
float choose_fuse(float Current)
{
	float CommercialValues[] = {0.1, 0.125, 0.15, 0.2, 0.25, 0.3, 0.315, 0.35,
									0.4, 0.5, 0.8, 1.0, 1.25, 1.5, 1.6, 2.0, 2.5,
									3.0, 3.15, 3.5, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,
									10.0, 15.0, 20.0, 25.0, 30.0, 40.0, 50.0, 0.0};
	
	for(int i = 0; CommercialValues[i] != 0.0; i++)
	{
		if(Current < CommercialValues[i])
			return CommercialValues[i];
	}
	
	return 0;
}






