<!-- LOGO -->
<br />
<a name="arriba"></a>
<div align="center">
    <img src="imagenes/logo.png" alt="Logo" width="180" height="80">
 <!-- TITULO -->   
  <p align="center">
    Estructura de Datos Taller 3 - Anais Rodriguez
  </p>
</div>
<!-- INDICE -->
<details>
  <summary>Indice</summary>
  <ol>
    <li>
        <a href="#resumen-del-taller">Resumen del Taller</a>
    </li>
    <li>
        <a href="#librerías">Librerías</a>
    </li>
    <li>
        <a href="#código">Código</a>
        <ul>
          <li><a href="#main">main</a></li>
          <li><a href="#generateFiles">generateFiles</a></li>
          <li><a href="#readFiles">readFiles</a></li>
          <li><a href="#displayMenu">displayMenu</a></li>
          <li><a href="#validateOption">validateOption</a></li>
          <li><a href="#bellmanFord">bellmanFord</a></li>
          <li><a href="#cargarDesdeCSV">cargarDesdeCSV</a></li>
          <li><a href="#logicGraph">logicGraph</a></li>
      </ul>
    </li>
  </ol>
</details>

<!-- RESUMEN DEL TALLER -->
## Resumen del Taller
Se desarrolló el algoritmo para una Aplicación de Mensajería:

* Se deben leer 2 archivos csv.
* Por consola se debe poder visualizar el Grafo generado.
* Por consola se debe poder visualizar el tiempo total de nodo a nodo.
* Por consola se debe poder visualizar el camino más corto entre nodo y nodo.
* Por consola se debe poder ingresar el tamaño del archivo a enviar.

# Librerías
Se están utilizando un total de 8 librerías, las cuales se muestran a continuación.
<div align="center">
    <img src="imagenes/Library.png" alt="Library" width="400" height="200">
    <p>main.cpp</p>
</div>

# Código
A continuación se detallan las funcionas usadas en la creación del taller.

## main
Función de tipo `int`, utilizada para generar por primera vez los archivos csv y mostrar el menú al usuario.
Permite ver el grafo e ingresar el peso del archivo, también permite volver a generar los archivos. 

<div align="center">
    <img src="imagenes/Main.png" alt="Main" width="800" height="350">
    <p>main.cpp</p>
</div>

<p align="right">(<a href="#arriba">Ir a Inicio</a>)</p>

## generateFiles
Función de tipo `int`, utilizada para generar los 2 archivos con valores completamente aleatorios.

<div align="center">
    <img src="imagenes/generateFiles.png" alt="Broad" width="800" height="350">
    <p>files.c</p>
</div>

<p align="right">(<a href="#arriba">Ir a Inicio</a>)</p>

## readFiles

Función de tipo `void`, utilizada para leer el archivo de las conexiones generadas. 

<div align="center">
    <img src="imagenes/readFiles.png" alt="Broad" width="800" height="400">
    <p>files.c</p>
</div>

<p align="right">(<a href="#arriba">Ir a Inicio</a>)</p>

## displayMenu

Función de tipo `int`, donde se invoca toda la lógica de la aplicación: 

* Ver grafo
* Generar nuevos archivos

<div align="center">
    <img src="imagenes/displayMenu.png" alt="Ofimatica" width="800" height="300">
    <p>addons.c</p>
</div>

<p align="right">(<a href="#arriba">Ir a Inicio</a>)</p>

## validateOption

Función de tipo `int`, utilizada para validar que la opción ingresada por el usuario sea válida. 

<div align="center">
    <img src="imagenes/validateOption.png" alt="Produccion" width="850" height="250">
    <p>addons.c</p>
</div>

<p align="right">(<a href="#arriba">Ir a Inicio</a>)</p>

## bellmanFord

Función de tipo `int`, utilizada para obtener el tiempo total de conexión entre un nodo y otro, posteriormente evaluar el camino más corto. 

<div align="center">
    <img src="imagenes/bellmanFord.png" alt="Seguridad" width="850" height="300">
    <p>graph.c</p>
</div>

<p align="right">(<a href="#arriba">Ir a Inicio</a>)</p>

## cargarDesdeCSV

Función de tipo `void`, utilizada para cargar los nodos y aristas del grafo usando los archivos generados.

<div align="center">
    <img src="imagenes/cargarDesdeCSV.png" alt="Social" width="800" height="300">
    <p>graph.c</p>
</div>

<p align="right">(<a href="#arriba">Ir a Inicio</a>)</p>

## logicGraph

Función de tipo `int`, utilizada para invocar todas las demás funciones, a su vez también está mostrando el detalle del grafo y el tiempo de conexión entre nodos agrupados por aristas en común. 

<div align="center">
    <img src="imagenes/logicGraph.png" alt="setListGamesToAdd" width="800" height="300">
    <p>graph.c</p>
</div>

<p align="right">(<a href="#arriba">Ir a Inicio</a>)</p>
