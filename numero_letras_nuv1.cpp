//fecha: 18/07/24
////Autor: Lopez Quiroz Wagner
//tema: Numero letras  Utilice el programa de conversión de NUMEROS a LETRAS realizado en clases y complete hasta el número 999.999.
#include<iostream>
using namespace std;

const string unidades[] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis",
                           "siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince",
                           "dieciseis", "diecisiete", "dieciocho", "diecinueve"};

const string decenas[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta",
                          "sesenta", "setenta", "ochenta", "noventa"};

const string centenas[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos",
                           "seiscientos", "setecientos", "ochocientos", "novecientos"};

// Devuelve las unidades del array de string
string GetUnidades(int num) {
    return unidades[num];
}

string GetDecenas(int num) {
    int x = num / 10;
    int resto = num % 10;
    string aux = "";

    if (num < 20)
        aux = GetUnidades(num);
    else {
        aux = decenas[x];
        aux = resto > 0 ? aux + " y " + GetUnidades(resto) : aux;
    }
    return aux;
}

string GetCentenas(int num) {
    int x = num / 100;
    int resto = num % 100;
    string aux = "";

    if (num == 100) {
        aux = "cien";
    } else if (num < 100) {
        aux = GetDecenas(num);
    } else {
        aux = centenas[x];
        aux = resto > 0 ? aux + " " + GetDecenas(resto) : aux;
    }
    return aux;
}

string GetMiles(int num) {
    int x = num / 1000;
    int resto = num % 1000;
    string aux = "";

    if (x == 1)
        aux = "mil";
    else
        aux = GetCentenas(x) + " mil";

    if (resto > 0)
        aux = aux + " " + GetCentenas(resto);

    return aux;
}

string GetCientosMiles(int num) {
    int x = num / 1000;
    int resto = num % 1000;
    string aux = GetCentenas(x) + " mil";

    if (resto > 0)
        aux = aux + " " + GetCentenas(resto);

    return aux;
}

string NumberToWords(int num) {
    if (num < 100)
        return GetDecenas(num);
    else if (num < 1000)
        return GetCentenas(num);
    else if (num < 100000)
        return GetMiles(num);
    else
        return GetCientosMiles(num);
}

int main() {
    for (int k = 1; k <= 999999; k++) {
        string aux = NumberToWords(k);
        cout << k << " : " << aux << endl;
    }

    return 0;
}