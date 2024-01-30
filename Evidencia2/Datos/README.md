![Tec de Monterrey](images/logotecmty.png)
# Actividad Integradora 2

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>
En este repositorio encontrarás el archivo "main.cpp". En este archivo deberás desarrollar la implementación del problema presentado en esta actividad. En la parte superior del archivo coloca, en comentarios, tus datos. Por ejemplo:
```
// =========================================================
// File: main.cpp
// Authors:
//  Edward Elric - A00123456
//  Alphonse Elric - A00124598
// Date: 01/01/2021
// =========================================================
```
Implementa, <span style="text-decoration-line: underline;">en equipos de 2 personas (máximo)</span>, una solución para el conjunto de problemas que se describen a continuación.

## <span style="color: rgb(26, 99, 169);">**Descripción**</span>
La empresa "InternetMáximo" ha empezado operaciones en la ciudad. Actualmente con poco personal y dinero inicial, así que requiere tomar decisiones inteligentes que le permitan entrar pronto en competencia con las empresas ya instaladas.

### <span style="color: rgb(26, 99, 169);">**Problema 1. Cobertura máxima**</span>
Los ingenieros de la compañía han generado un mapa que muestra cada una de las colonias y las distancias máximas existente entre los centros geográficos de las mismas. Con el fin de poder empezar a competir, la empresa planea colocar fibra óptima para conectar todas las colonias. Sin embargo, el costo de interconectar todas las colonias entre sí es elevado, por lo que la empresa necesita determinar la forma de conectar todas las colonias con el menor número cantidad de fibra óptica posible.

### <span style="color: rgb(26, 99, 169);">**Problema 2. Publicidad y contratación**</span>
La empresa cuenta con poco personal así que la tareas de publicidad y contratación es manejada por un solo grupo de personas. La idea es recorrer cada una de las colonias, una solo vez cada una de ellas, y regresar al punto de inicio. A decir verdad, se desea que sea siempre la menor ruta posible.

### <span style="color: rgb(26, 99, 169);">**Problema 3. Máximo servicio que se puede ofrecer**</span>
Como se comentó antes, la empresa cuenta con pocos recursos, por lo que los equipos instalados son muy heterogéneos. Por lo mismo, las capacidades máximas (Mbps) en los diferentes enlaces son muy varias. La empresa desea determinar cuál es la transferencia máxima que se puede obtener entre dos colonias determinadas. Para ello ya se cuenta con un registro de las velocidades de transferencia máxima entre cada una de las colonias instaladas.

## <span style="color: rgb(26, 99, 169);">**Entrada**</span>
El programa recibe dos grafos: el primero no dirigido, el segundo dirigido. El primero lo usarás en los dos primeros problema, mientras que el segundo lo usarás para el tercer problema. Ambos grafos estarán en forma de matriz ponderada de adyacencias. La primera línea de entrada contiene un entero, *n* (7 <= *n* <= 15), indicando el número de vértices del grafo y dos enteros , *start* y *end* (0 <= *start*, *end* < n), vértices que se emplearan como inicio y fin para algunos problemas (para el primero y tercero).

A continuación, unas primeras *n*  líneas. La *i*-esima línea contiene *n* números.  El *j*-ésimo valor es la distancia, en kilómetros, entre el centro de la colonia *i* con el centro de la colonia *j* (10 <= *m[i][j]* <= 1000). En caso de no existir conexión, este valor será -1.

Las siguientes *n* líneas contienen las capacidad máximas de conexión. La *i*-esima línea contiene *n* números. El *j*-ésimo valor es la capacidad máxima, en Mbps, en el enlace que existe entre colonia *i* con la colonia *j* (10 <= *m[i][j]* <= 1000). En caso de no existir conexión, este valor será -1.

## <span style="color: rgb(26, 99, 169);">**Salida**</span>
En primer lugar, deberá desplegar la lista de arcos seleccionados para lograr la cobertura requerida. Los arcos aparecerán en orden descendente por costo. Cada arco deberá mostrarse como un par "(a, b)" donde a < b.

A continuación, se desplegará el costo y los vértices que integran la ruta requerida en el problema 2. Si el costo de la ruta es negativa, deberá desplegar el mensaje "There is no possible route.".

Por último, se desplegará la velocidad máxima de transferencia que se puede lograr entre los vértices *start* y *end*.

## <span style="color: rgb(26, 99, 169);">**Ejemplo de entrada**</span>
```
4 0 3
 0 16 45 32
16  0 18 21
45 18  0  7
32 21  7  0
0 48 12 -1
52 0 42 -1
18 -1 0 56
-1 -1 52 0
```

## <span style="color: rgb(26, 99, 169);">**Ejemplo de salida**</span>
```
-------------------------------------
Problem 1
(2, 3)
(0, 1)
(1, 2)
-------------------------------------
Problem 2
Minimum cost: 73
Path: 0 1 2 3
-------------------------------------
Problem 3
Maximum flow from 0 to 3 is 54
-------------------------------------
```

Para probar tu implementación, compila tu programa con el comando:
```
g++ -std=c++11 main.cpp -o app
```
Posteriormente, ejecuta tu programa. Para realizar las pruebas, puedes usar los archivos de salida que encuentran en el repositorio (*output1.txt*, *output2.txt*, *output3.txt*, *output4.txt*). Revisa que tu solución despliegue los mismos valores, aunque no necesariamente en el mismo orden.
Posteriormente, ejecuta tu programa. Para realizar las pruebas, puedes usar las siguientes líneas de código.
```
./app > mysolutionX.txt
diff mysolutionX.txt ouputX.txt
```

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **80%** - Para cada una de las funcionalidades se evaluará:

    - **Excelente (80%)** - pasa correctamente todos los casos de prueba.
    - **Muy Bien (60%)** - pasa correctamente el 75% de los casos de prueba.
    - **Bien (40%)** - pasa correctamente el 50% de los casos de prueba.
    - **Insuficiente (20%)** - pasa correctamente menos del 50% de los casos de prueba.

- **15%** - El documento de reflexión incluye la explicación de diferentes algoritmos aplicados a esta situación problema, así como la **complejidad computacional** de cada uno de ellas.
- **5%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación: <span class="instructure_file_holder link_holder">[liga_estándar_codificación](estandar.pdf)</span>

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>
Cuando hayas pasado todas las pruebas, recuerda publicar el código en tu repositorio (*git push*).

## <span style="color: rgb(26, 99, 169);">**Importante**</span>
Recuerda colocar el nombre y las matrículas de ambos integrantes en en los comentarios iniciales. En caso de que se incumpla este punto, se penalizará con 20 puntos sobre la calificación obtenida.
