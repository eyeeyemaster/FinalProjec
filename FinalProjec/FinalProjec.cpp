// FinalProjec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/* takes a 3 - 5 string and turns it into a 5-3 string and than converts that string into rna */
string anti(string dna)
{
	int size, i, b;
	string converted = "";
	size = dna.length();
	b = dna.length() - 1;
	for (i=0; i < size; i++)
	{
		 converted = converted + dna[b];
		 b--;
	}
	for (i=0; i < size; i++)
	{
		if (converted[i] == 'c')
		{
			converted[i] = 'g';
		}
		else if (converted[i] == 'g')
		{
			converted[i] = 'c';
		}
		else if (converted[i] == 't')
		{
			converted[i] = 'a';
		}
		else if (converted[i] == 'a')
		{
			converted[i] = 'u';
		}
		else if (converted[i] == 'u')
		{
			cout << "I think you might have typed in the rna sequence by mistake, please check. ";
			return;
		}
		else
		{
			converted[i] = converted[i];
		}
	}
	return converted;
}
/* takes a dna string and transforms it into an rna string */
string convert(string dna)
{
	int size, i=0;
	size = dna.length();
	for (i; i < size; i++)
	{
		if (dna[i] == 't' || dna[i] == 'T')
		{
			dna[i] = 'u';
		}
	}
	return dna;
}
/* takes an rna string and makes it a protien sequence */
string convprotien(string rna)
{
	int size, i = 0;
	string protein = "";
	size = rna.length();
	for (i; i < size - 2; i = i + 3)
	if (rna[i] == 'a')
	{
		if (rna[i + 1] == 'a')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c')
			{
				protein = protein + "Asn ";
			}
			else if (rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Lys ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else if (rna[i + 1] == 'c')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c' || rna[i + 2] == 'a' || rna[i + 2] == 'g')	// Added by Matt
			{
				protein = protein + "Thr ";
			}
			else	// Added by Matt
			{
				protein = protein + "--- "; // Added by Matt
			}

		}
		else if (rna[i + 1] == 'g') 
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c')
			{
				protein = protein + "Ser ";
			}
			else if (rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Arg ";
			}
			else // Added by Matt
			{
				protein = protein + "--- "; // Added by Matt
			}
		}
		else if (rna[i + 1] == 'u')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c' || rna[i + 2] == 'a')
			{
				protein = protein + "Ile ";
			}
			else if (rna[i + 2] == 'g')
			{
				protein = protein + "Met ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else // Edit by Matt: Problem fixed
		{
			protein = protein + "--- ";
		}
	}
	else if (rna[i] == 'u')
	{
		if (rna[i + 1] == 'u')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c')
			{
				protein = protein + "Phe ";
			}
			else if (rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Leu ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else if (rna[i + 1] == 'c')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c' || rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Ser ";
			}
			else // Added by Matt
			{
				protein = protein + "--- "; // Added by Matt
			}
		}
		else if (rna[i + 1] == 'a')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c')
			{
				protein = protein + "Tyr ";
			}
			else if (rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Stop ";
				return protein;
				//break;
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		// Statements below added by Matt
		else if (rna[i + 1] == 'g')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c')
			{
				protein += "Cys ";
			}
			else if (rna[i + 2] == 'a')
			{
				protein += "Stop ";
				return protein;
				//break;
			}
			else if (rna[i + 2] == 'g')
			{
				protein += "Trp ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else
		{
			protein = protein + "--- ";
		}
	}
	else if (rna[i] == 'c')
	{
		if (rna[i + 1] == 'u')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c' || rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Leu ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else if (rna[i + 1] == 'c')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c' || rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Pro ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else if (rna[i + 1] == 'a')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c')
			{
				protein = protein + "His ";
			}
			else if (rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Gln ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else if (rna[i + 1] == 'g')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c' || rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Arg ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else
		{
			protein = protein + "--- ";
		}
	}
	else if (rna[i] == 'g')
	{
		if (rna[i + 1] == 'u')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c' || rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Val ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else if (rna[i + 1] == 'c')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c' || rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Ala ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else if (rna[i + 1] == 'a')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c')
			{
				protein = protein + "Asp ";
			}
			else if (rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Glu ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else if (rna[i + 1] == 'g')
		{
			if (rna[i + 2] == 'u' || rna[i + 2] == 'c' || rna[i + 2] == 'a' || rna[i + 2] == 'g')
			{
				protein = protein + "Gly ";
			}
			else
			{
				protein = protein + "--- ";
			}
		}
		else
		{
			protein = protein + "--- ";
		}
	}
	// Statements above added by Matt
	else
	{
		protein = protein + "--- ";
	}

	return protein;

}
/*takes a string and makes all the letters into lowercase chars */
string convertlower(string mystring)
{
	int size = mystring.length();
	for (int i=0; i < size; i++)
	{
		mystring[i] = tolower(mystring[i]);
	}
	return mystring;
}
	
/* helpful menu that helps you convert your dna, antisence dna, or rna into its protien sequence */
void main()
{
	char DNA, dna2, q3, run = 'y';
	int count, x = 0;
	ifstream fin;
	string mystring, rna, protien, newstring;
	while (run == 'y' || run == 'Y')
	{
		cout << "Is the sequence in a file? (y/n) ";
		cin >> q3;
		if (q3 == 'y' || q3 == 'Y')
		{
			cout << "Please enter the file name.";
			cin >> newstring;
			fin.open(newstring);
			if (fin.fail())
			{
				cout << "error opening file";
				exit(-1);
			}
			else
			{
				fin >> mystring;
				x = 1;
			}
		}
		cout << "Is the sequence Dna? (y/n) ";
		cin >> DNA;
		if (DNA == 'y' || DNA =='Y')
		{
			cout << "Is the sequence the Antisence strand? (y/n) ";
			cin >> dna2;
			if (dna2 == 'y' || dna2 =='Y')
			{
				count = 2;
			}
			else
			{
				count = 1;
			}
		}
		else
		{
			count = 0;
		}
		if (x == 0)
		{
			cout << "What is the sequence? " << endl;
			cin >> mystring;
		}
		mystring = convertlower(mystring);
		if (count == 1)
		{
			rna = convert(mystring);
		}
		else if (count == 2)
		{
			rna = anti(mystring);
			cout << rna;
		}
		else
		{
			rna = mystring;
		}
		protien = convprotien(rna);
		cout << protien << endl;
		cout << "Do you want to run again? (y/n) ";
		cin >> run;
	}
	return;
}

