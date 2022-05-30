#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;



int main()
{
	string fnombre;
	cout<<"Grupo:\nIgor Bustos Zurita\nJose Carmona Sanchez \n \n"<<"Nombre del Archivo: ";
	cin>>fnombre;
 
	//vector<string> row;
        //vector<vector<string>> total;
        //vector<string> dato;
	string line, word,texto="", letra, nombre="", ingresar="", puntaje_d="", nota_d="";
        char respuestas[12]={'A','E','C','B','B','D','A','B','E','C','B','D'};
        int buenas=0,malas=0,omitidas=0,indice=0, primera_fila=0;
        float puntaje, nota;
//Lectura de csv y se guardan en un vector 
	fstream file (fnombre, ios::in);
	if(file.is_open())
	{
		std::ofstream pruebas_salida;
                pruebas_salida.open ("pruebas_salida.csv");
                while(getline(file, line))
		{
			//row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
                            for(int k=0;k<word.size();k++)
                            {
                                letra=word[k];
                                
                                if(letra!=";" && primera_fila!=0){
                                    texto=texto+word[k];
                                }
                                if(letra==";" && primera_fila!=0){
                                    //1-11 respuestas
                                    indice=indice+1;
                                    if(texto[1]=='-' && texto.size()==3)
                                    {
                                        omitidas=omitidas+1;

                                    }
                                    else
                                    {
                                        
                                        if(texto[1]==respuestas[buenas+malas+omitidas] && texto.size()==3)
                                        {
                                            buenas=buenas+1;
                                        }
                                        else
                                        {
                                            if(texto.size()==3)
                                            {
                                                malas=malas+1;
                                            }
                                        }
                                    }
                                    if(indice==1 && primera_fila!=0)
                                    {
                                        nombre=texto;
                                        indice=indice+1;
                                    }
                                    texto="";
                                }
                            }
                        //ultima respuesta
                        if(primera_fila!=0){
                        if(texto[1]=='-')
                        {
                           omitidas=omitidas+1;
                        }
                        else
                        {
                           if(texto[1]==respuestas[buenas+malas+omitidas] && texto.size()==3)
                           {
                               buenas=buenas+1;
                           }
                           else
                           {
                               malas=malas+1;
                           }
                        }
                        }
                        if(primera_fila==0)
                        {
                            
                            primera_fila=1;
                            ingresar='"'+nombre+"Token de Estudiante"+'"'+";"+'"'+"Preguntas Buenas"+'"'+";"+'"'+"Preguntas Malas"+'"'+";"+'"'+"Preguntas Omitidas"+'"'+";"+'"'+"Puntaje"+'"'+";"+'"'+"Nota"+'"';
                            cout<<ingresar<<"\n";
                            pruebas_salida<< ingresar<<"\n";
                        }
                        else{
                        puntaje=(buenas*0.5)-(malas*0.12);
                        puntaje_d=to_string(puntaje);
                        if (puntaje_d.size()<4)
                        {
                            puntaje_d=puntaje_d.substr(0,3);
                        }
                        else
                        {
                            puntaje_d=puntaje_d.substr(0,4);
                        }
                        nota=1+puntaje;
                        nota_d=to_string(nota);
                        if (nota_d.size()<4)
                        {
                            nota_d=nota_d.substr(0,3);
                        }
                        else
                        {
                            nota_d=nota_d.substr(0,4);
                        }
                        //cout<<nombre<<";"<<'"'<<buenas<<'"'<<";"<<'"'<<malas<<'"'<<";"<<'"'<<omitidas<<'"'<<";"<<'"'<<puntaje<<'"'<<";"<<'"'<<nota<<'"'<<"\n";
                        ingresar=nombre+";"+'"'+to_string(buenas)+'"'+";"+'"'+to_string(malas)+'"'+";"+'"'+to_string(omitidas)+'"'+";"+'"'+puntaje_d+'"'+";"+'"'+to_string(nota).substr(0,3)+'"';
                        cout<<ingresar<<"\n";
                        pruebas_salida<< ingresar<<"\n";
                        }
                        ingresar="";
                        texto="";
                        nombre="";
                        buenas=0;
                        malas=0;
                        omitidas=0;
                        puntaje=0;
                        nota=0;
                        indice=0;
			//contenido.push_back(row);
                        
		}
                pruebas_salida.close();
	}
	else
        {
            cout<<"Could not open the file\n";
        }
//modifica los datos del csv  que feuron guardados en el vector
//se separan los datos en cada columna.
	/*
        for(int i=0;i<contenido.size();i++)
	{
                string texto="", sample,letra;
                for(int j=0;j<contenido[i].size();j++)
		{ 
                    dato.clear();
                    sample=contenido[i][j];
                    for(int k=0;k<sample.size();k++){
                        letra=sample[k];
                        if(letra!=";"){
                            texto=texto+sample[k];
                        }
                        if(letra==";"){
                            //dato.push_back(texto);
                            texto="";
                        }
                    }
                    //dato.push_back(texto);
                    //total.push_back(dato);
		}
	}
        */
//Se utilizan los datos para trabajar con las formulas correspondientes. 
        
        /*
        char respuestas[12]={'A','E','C','B','B','D','A','B','E','C','B','D'};
        for(int i=0;i<total.size();i++)
        {
            int buenas=0, malas=0, omitidas=0;
            float puntaje=0,nota=1;
            for(int j=0;j<total[i].size();j++)
            {
                if(j!=0)
                {
                    if(total[i][j][1]=='-')
                    {
                        omitidas=omitidas+1;
                    }
                    else
                    {
                        if(total[i][j][1]==respuestas[j-1])
                        {
                            buenas=buenas+1;
                        }
                        else
                        {
                            malas=malas+1;
                        }
                    }
                }
                else
                {
                    //cout<<total[i][j];
                }
            }
            //puntaje=(buenas*0.5)-(malas*0.12);
            //nota=nota+puntaje;
            //cout<<" B:"<<buenas<<", M:"<<malas<<", O:"<<omitidas<<", P:"<<puntaje<<", N:"<<nota;
            //cout<<"\n";
        }
        */
        return 0;
}
 
