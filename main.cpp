#include "iostream"
#include "string"
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

int main(void){
    string file, type;
    list<string> vars;
    string operations = " ";
	cin >> file;
	cin >> type;
    ifstream fin(file);
    string var;
    string operation;
    while (fin >> var)
    {
        operations += var + " ";
        if (fin >> operation)
        {
            operations += operation + " ";
        }
        vars.emplace_back(var);
    }

    list<string> unique_list;

    for (string variable : vars)
    {
        bool is_unique = true;
        for (string variable_un : unique_list)
            if (!variable.compare(variable_un))
                is_unique = false;

        if (is_unique)
            unique_list.emplace_back(variable);
    }

	ofstream fout("f.cpp");

	fout << "#include <iostream>" << endl;

	fout << "int f(";

    for (string variable : unique_list)
    {
        fout << type << " " << variable;
        if (variable != unique_list.back())
            fout << ", ";
    }

    fout << ") {"<< endl;

	fout << "\tstd::cout << " << operations << " << std::endl;" << endl;
	fout << "\treturn 0;" << endl;
	fout << "}" << endl;

    fout << "int main() {" << endl;
    fout << "\tf(";
    for (string variable : unique_list)
    {
        fout << "1";
        if (variable != unique_list.back())
            fout << ", ";
    }
    fout << ");" << endl;
    fout << "}";
	fout.close();

    ofstream fout_h("f.h");

    fout_h << "#pragma once" << endl;

    fout_h << endl;

	fout_h << "int f(";

    for (string variable : unique_list)
    {
        fout_h << type << " " << variable;
        if (variable != unique_list.back())
            fout_h << ", ";
    }

    fout_h << ");";
	fout_h.close();

	return 0;
}