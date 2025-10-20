# Sistemas de recomendación. Métodos de filtrado colaborativo
## AUTORES  
- Joel Saavedra Páez
- Alejandro
- Guillermo
## DESCRIPCIÓN GENERAL
Este proyecto implementa un **sistema de recomendación básico** desarrollado en **C++**.  
El programa recibe una **matriz de puntuaciones(usuario-item), una métrica, un tipo de predicción y un número de vecinos** y predice los ítems no valorados por cada usuario, generando así recomendaciones personalizadas.
## INSTALACIÓN
El proyecto requiere, únicamente, un compilador **g++**.
## EJECUCIÓN
Primero debemos compilar nuestro código, para esto se dispone de un Makefile que nos facilita el proceso.
```bash
make
```
Para eliminar los archivos resultantes de la compilación disponemos del comando:
```bash
make clean
```
Una vez compilado el programa, podemos ejecutar el sistema de recomendación con el siguiente comando:
```bash
./recommender-system -mx <archivo_matriz> -mc <métrica> -nb <num_vecinos> -pd <tipo_predicción>
```

## PARÁMETROS
- **-mx**: Ruta al archivo que contiene la matriz usuario-ítem
- **-mc**: Métrica de similitud (entero):
  - 1: Correlación de Pearson
  - 2: Similitud Coseno
  - 3: Distancia Euclidiana
- **-nb**: Número de vecinos a considerar para las predicciones (mínimo 3)
- **-pd**: Tipo de predicción (entero):
  - 1: Predicción Simple
  - 2: Diferencia de Medias

## EJEMPLOS DE USO

### Ejemplo 1: Matriz pequeña con correlación de Pearson
```bash
./recommender-system -mx matrices/utility-matrix-5-10-1.txt -mc 1 -nb 3 -pd 1
```
Este comando ejecuta el sistema con:
- Matriz de 5 usuarios y 10 ítems
- Métrica de correlación de Pearson
- 3 vecinos más cercanos
- Predicción simple

### Ejemplo 2: Matriz mediana con similitud coseno y diferencia de medias
```bash
./recommender-system -mx matrices/utility-matrix-25-100-5.txt -mc 2 -nb 5 -pd 2
```
Este comando ejecuta el sistema con:
- Matriz de 25 usuarios y 100 ítems
- Métrica de similitud coseno
- 5 vecinos más cercanos
- Predicción por diferencia de medias

### Ejemplo 3: Matriz grande con distancia euclidiana
```bash
./recommender-system -mx matrices/utility-matrix-100-1000-1.txt -mc 3 -nb 10 -pd 1
```
Este comando ejecuta el sistema con:
- Matriz de 100 usuarios y 1000 ítems
- Métrica de distancia euclidiana
- 10 vecinos más cercanos
- Predicción simple

### Ayuda del programa
Para obtener información detallada sobre el uso del programa:
```bash
./recommender-system --help
```
o
```bash
./recommender-system -h
```

## FORMATO DE ENTRADA
El archivo de matriz debe seguir el siguiente formato:
```
<número_de_usuarios>
<número_de_ítems>
<puntuación_u1_i1> <puntuación_u1_i2> ... - <puntuación_u1_in>
<puntuación_u2_i1> <puntuación_u2_i2> ... - <puntuación_u2_in>
...
```
Donde `-` representa valores no puntuados por el usuario.

## SALIDA DEL PROGRAMA
El programa muestra los siguientes resultados:
1. **Predicciones**: Puntuaciones predichas para los ítems no valorados por cada usuario
2. **Matriz de Similitudes**: Matriz que muestra la similitud entre usuarios
3. **Matriz Resultante**: Matriz completa con puntuaciones calculadas
4. **Vecinos**: Lista de vecinos elegidos para cada usuario
5. **Matriz de utilidad original**: Muestra la matriz de puntuaciones original con los valores no puntuados
6. **Datos de entrada**: Muestra los parámetros utilizados en la ejecución del programa
7. Los resultados se muestran en pantalla con formato tabular