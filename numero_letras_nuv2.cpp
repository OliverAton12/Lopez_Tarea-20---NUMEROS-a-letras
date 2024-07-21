//fecha: 18/07/24
////Autor: Lopez Quiroz Wagner
//tema: Numero letras En el mismo programa, diseñe una función que genere 100 números aleatorios comprendidos entre 1 y 999.999. LA función debe imprimir el valor numérico y su equivalente en letras.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const string unidades[] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis",
                           "siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince",
                           "dieciseis", "diecisiete", "dieciocho", "diecinueve"};

const string decenas[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta",
                          "sesenta", "setenta", "ochenta", "noventa"};

const string centenas[] = {"", "cien", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos",
                           "seiscientos", "setecientos", "ochocientos", "novecientos"};

/**
 * Devuelve la representación en palabras de las unidades.
 * 
 * @param num Número entero entre 0 y 19.
 * @return La representación en palabras del número.
 */
string GetUnidades(int num) {
    return unidades[num];
}

/**
 * Devuelve la representación en palabras de las decenas.
 * 
 * @param num Número entero entre 0 y 99.
 * @return La representación en palabras del número.
 */
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

/**
 * Devuelve la representación en palabras de las centenas.
 * 
 * @param num Número entero entre 100 y 999.
 * @return La representación en palabras del número.
 */
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

/**
 * Devuelve la representación en palabras de los miles.
 * 
 * @param num Número entero entre 1000 y 99999.
 * @return La representación en palabras del número.
 */
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

/**
 * Devuelve la representación en palabras de los cientos de miles.
 * 
 * @param num Número entero entre 100000 y 999999.
 * @return La representación en palabras del número.
 */
string GetCientosMiles(int num) {
    int x = num / 1000;
    int resto = num % 1000;
    string aux = GetCentenas(x) + " mil";

    if (resto > 0)
        aux = aux + " " + GetCentenas(resto);

    return aux;
}

/**
 * Devuelve la representación en palabras de un número.
 * 
 * @param num Número entero entre 0 y 999999.
 * @return La representación en palabras del número.
 */
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

/**
 * Genera e imprime 100 números aleatorios entre 1 y 999999,
 * mostrando tanto su valor numérico como su representación en palabras.
 */
void GenerarYImprimirNumerosAleatorios() {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        int num = rand() % 999999 + 1;
        string resultado = NumberToWords(num);
        cout << num << " : " << resultado << endl;
    }
}

int main() {
    GenerarYImprimirNumerosAleatorios();
    return 0;
}
