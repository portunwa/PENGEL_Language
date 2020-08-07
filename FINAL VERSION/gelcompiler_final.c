/*
 * This file is part of the GELCOMPILER distribution (https://github.com/jirapasjipipob/pengel_language).
 * Copyright (c) 2019 PENGEL INTERACTIVE.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
//GELCOMPILER FINAL VERSION
#include <stdio.h>
#include <stdlib.h>
//function main
int main()
{
  while(1)
  {
    FILE *read; //read file variable
    FILE *write; //write file variable
    char fname[64]; //file name storage
    char length[256]; //max length
    printf("gelcompiler>>>");
    scanf("%s", fname); //input file name
    printf("compiling... %s\n", fname); //display file name
    read = fopen(fname, "r"); //open file
    write = fopen("output.html", "w"); //write file
    int nt = 0; // New Technology Mode = off
    for(int i=0; fgets(length, 256, read) != NULL; i++) //translation loop
    {
      //code
      if (length[0] == 'n' && length[1] == 't' && length[2] == '[')
      {
        nt = 1;
      }
      else if(length[0] == ']' && length[1] == ';')
      {
        nt = 0;
      }
      else if (nt == 1) { //New Technology Mode On
        fprintf(write, "%s", length);
      }
      else if (nt == 0) { //New Technology Mode Off
        	//start
        	if (length[0] == 'm' && length[1] == 'a' && length[2] == 'i' && length[3] == 'n' && length[4] == '{')
          {
            fprintf(write, "<script>\n");
          }

          else if (length[0] == '}' && length[1] == ';')
          {
            fprintf(write, "</script>\n");
          }
          //print > console.log
          else if (length[0] == 'p' && length[1] == 'r' && length[2] == 'i' && length[3] == 'n' && length[4] == 't' && length[5] == '(')
          {
          	fprintf(write, "console.log("); //first part

         		for(int z=6; z<256 ; z++) //second part
         		{
                    fprintf(write, "%c", length[z]);
                    if (length[z] == ')' && length[z+1] ==';')
                    {
                        break;
                    }
                }
                fprintf(write, ";\n"); //third part
     	 		}

     	 		//stop > debugger
      		else if (length[0] == 's' && length[1] == 't' && length[2] == 'o' && length[3] == 'p' && length[4] == ';')
      		{
        		fprintf(write, "debugger;\n");
      	  }

      		//show > alert
      		else if (length[0] == 's' && length[1] == 'h' && length[2] == 'o' && length[3] == 'w' && length[4] == '(')
          {
              fprintf(write, "alert("); //first part
         		for(int z=5; z<256 ; z++) //second part
         		{
                    fprintf(write, "%c", length[z]);
                    if (length[z] == ')' && length[z+1] ==';')
                    {
                        break;
                    }
                }
                fprintf(write, ";\n"); //third part
     	 		}

      		//create; > var
      		else if (length[0] == 'c' && length[1] == 'r' && length[2] == 'e' && length[3] == 'a' && length[4] == 't' && length[5] == 'e')
      		{
        		fprintf(write, "var"); //first part

        		for(int z=6; length[z] != ';'; z++) //second part
        		{
          		fprintf(write, "%c", length[z]);
        		}

        		fprintf(write, "\n"); //third part
      		}

      		//cube(v) > v = v*v*v
      		else if (length[0] == 'c' && length[1] == 'u' && length[2] == 'b' && length[3] == 'e' && length[4] == '(')
      		{
      			for(int z=5; length[z] !=')'; z++) //first part
        		{
          		fprintf(write, "%c", length[z]);
        		}
        		fprintf(write, " = ");
        		for(int z=5; length[z] !=')'; z++) //second part
       		  {
        		  fprintf(write, "%c", length[z]);
       		  }
       		  fprintf(write, "*");
       		  for(int z=5; length[z] !=')'; z++) //third part
       		  {
        		  fprintf(write, "%c", length[z]);
       		  }
       		  fprintf(write, "*");
        	  for(int z=5; length[z] !=')'; z++) //fourth part
       		  {
        		  fprintf(write, "%c", length[z]);
       		  }
        	  fprintf(write, ";\n");
      		}

      		//square(v) > v = v*v
      		else if (length[0] == 's' && length[1] == 'q' && length[2] == 'u' && length[3] == 'a' && length[4] == 'r' && length[5] == 'e' && length[6] == '(')
      		{
      			for(int z=7; length[z] !=')'; z++) //first part
        		{
          		fprintf(write, "%c", length[z]);
        		}
        		fprintf(write, " = ");
        		for(int z=7; length[z] !=')'; z++) //second part
        		{
          		fprintf(write, "%c", length[z]);
        		}
        		fprintf(write, "*");
        		for(int z=7; length[z] !=')'; z++) //third part
        		{
          		fprintf(write, "%c", length[z]);
        		}
        		fprintf(write, ";\n");
      		}
        //Short NT Mode
        else if (length[0] == '.')
        {
          length[0] = ' ';
          fprintf(write, "%s", length);
        }
        //Universal Constant Shortcut(UCS)
         else if (length[0] == 's' && length[1] == 'c' && length[2] == 'i' && length[3] == '(')
         {
           //sci(c) > var c = 299792458 ms-1
           if(length[4] == 'c' && length[5] == ')')
           {
             fprintf(write, "var c = 299792458\n");
           }

           //sci(g) > var g = 9.8 ms2
           else if(length[4] == 'g' && length[5] == ')')
           {
             fprintf(write, "var g = 9.8\n");
           }

           //sci(G) > var G = m3kg-1s-2
           else if(length[4] == 'G' && length[5] == ')')
           {
             fprintf(write, "var G = 6.6738480 / 100000000000\n");
           }

           //sci(h) > var h = js
           else if(length[4] == 'h' && length[5] == ')')
           {
             fprintf(write, "var h = 6.6260695729 / 10000000000000000000000000000000000\n");
           }

           //sci(k) > var k =  nm2c-2
           else if(length[4] == 'k' && length[5] == ')')
           {
             fprintf(write, "var k = 9 * 1000000000\n");
           }
         }
        //write(v) > document.write(v)
        else if(length[0] == 'w' && length[1] == 'r' && length[2] == 'i' && length[3] == 't' && length[4] == 'e' && length[5] == '(')
        {
          fprintf(write, "document.write(");
          for(int z=6; length[z] != ')'; z++)
          {
           fprintf(write, "%c", length[z]);
          }
          fprintf(write, ");\n");
        }
        //enable extra math function v.0.1
        else if(length[0] == 'i' && length[1] == 'm' && length[2] == 'p' && length[3] == 'o' && length[4] == 'r' && length[5] == 't' && length[6] == ' ' && length[7] == 'm' && length[8] == 'a' && length[9] == 't' && length[10] == 'h' && length[11] == ';')
        {
          //log function (x = base)
          fprintf(write, "function log(x, y) { return Math.log(y) / Math.log(x); }\n");
          //limit random int
          fprintf(write, "function random(max) { return Math.floor(Math.random() * Math.floor(max));}\n");
          //triangle function (x=base y=height)
          fprintf(write, "function triangle(x, y) {return 0.5 * x * y;}\n");
          //rectangle function (x=width y=height)
          fprintf(write, "function rectangle(x, y) {return x * y;}\n");
          //pentagon function (x=side)
          fprintf(write, "function pentagon(x) {return 1.72 * x * x;}\n");
          //hexagon function (x=side)
          fprintf(write, "function hexagon(x) {return 2.598 * x * x;}\n");
          //heptagon function (x=side)
          fprintf(write, "function heptagon(x) {return 3.634 * x * x;}\n");
          //octagon function (x=side)
          fprintf(write, "function octagon(x) {return 4.828 * x * x;}\n");
          //nonagon function (x=side)
          fprintf(write, "function nonagon(x) {return 6.182 * x * x;}\n");
          //decagon function (x=side)
          fprintf(write, "function decagon(x) {return 7.694 * x * x;}\n");
          //circle function (x=side)
          fprintf(write, "function circle(x) {return Math.PI * x * x;}\n");
          //circumcular function (r)
          fprintf(write, "function circum(r) {return 2 * Math.PI * r;}\n");
        }
        //enable extra physics function v.0.1
        else if(length[0] == 'i' && length[1] == 'm' && length[2] == 'p' && length[3] == 'o' && length[4] == 'r' && length[5] == 't' && length[6] == ' ' && length[7] == 'p' && length[8] == 'h' && length[9] == 'y' && length[10] == 's' && length[11] == 'i' && length[12] == 'c' && length[13] == 's' && length[14] == ';')
        {
          //velocity function (s=displacement t=time)
          fprintf(write, "function velocity(s,t) {return s / t;}\n");
          //Force function (m=mass a=acceleration)
          fprintf(write, "function force(m, a) {return m * a;}\n");
          //Chachiyo's Formula
          fprintf(write, "function chachiyo(r) {a = (Math.LN2 - 1) / (2 * Math.PI * Math.PI ); b = 20.4562557; return a * (Math.log(1+(b/r)+(b/(r*r))) / Math.log(Math.E));}\n");
          //Ohm's Law
          fprintf(write, "function voltage(i, r) {return i * r;}\n");
          //Kinetic Energy
          fprintf(write, "function ek(m, v) {return 0.5 * m * v * v;}\n");
          //Potential Energy
          fprintf(write, "function ep(m, h) {return m * 9.8 * h;}\n");
          //Density
          fprintf(write, "function density(m, v) {return m / v;}\n");
        }
        //enable extra chemistry function v.0.1
        else if(length[0] == 'i' && length[1] == 'm' && length[2] == 'p' && length[3] == 'o' && length[4] == 'r' && length[5] == 't' && length[6] == ' ' && length[7] == 'c' && length[8] == 'h' && length[9] == 'e' && length[10] == 'm' && length[11] == 'i' && length[12] == 's' && length[13] == 't' && length[14] == 'r' && length[15] == 'y' && length[16] == ';')
        {
          //number of electron in New Bohr's model
          fprintf(write, "function ne(n) {return 2 * n * n;}\n");
          //celsius to kelvin
          fprintf(write, "function celsius_to_kelvin(c) {return c + 273.15;}\n");
          //celsius to farenheit
          fprintf(write, "function celsius_to_fahrenheit(c) {return c + 32 + (9 / 5);}\n");
          //celsius to romer
          fprintf(write, "function celsius_to_romer(c) {return c * (21/40) + 7.5;}\n");
          //kelvin to celsius
          fprintf(write, "function kelvin_to_celsius(k) {return k - 273.15 ;}\n");
          //farenheit to celsius
          fprintf(write, "function farenheit_to_celsius(f) {return f - 32 - (9 / 5);}\n");
          //farenheit to kelvin
          fprintf(write, "function kelvin_to_farenheit(k) {return 1.8 * ( k - 273 ) + 32;}\n");

        }
      }
      //end code

    }
    fclose(read); //stop reading file
    fclose(write); //stop writing file
  }
}
