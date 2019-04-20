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
//GELCOMPILER v.0.1b
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

         		for(int z=6; length[z] != ')'; z++) //second part
         		{
          		fprintf(write, "%c", length[z]);
       	 		}

        	  fprintf(write, ");\n"); //third part
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

        		for(int z=5; length[z] != ')'; z++) //second part
            {
          		fprintf(write, "%c", length[z]);
            }

            fprintf(write, ");\n"); //third part
          }

      		//create; > var
      		else if (length[0] == 'c' && length[1] == 'r' && length[2] == 'e' && length[3] == 'a' && length[4] == 't' && length[5] == 'e')
      		{
        		fprintf(write, "var"); //first part

        		for(int z=6; length[z] != ';'; z++) //second part
        		{
          		fprintf(write, "%c", length[z]);
        		}

        		fprintf(write, "\n");
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
      }
      //end code
    }
    fclose(read); //stop reading file
    fclose(write); //stop writing file
  }
}
