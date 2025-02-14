# 🌀 Fract-ol - Explora los Fractales 🌌
## 📌 Descripción
¡Bienvenido a **fract-ol**! Un programa para explorar la belleza infinita de los fractales. Utilizando la biblioteca MiniLibX, podrás visualizar los conjuntos de fractales más famosos como **Mandelbrot**, **Julia** y **Burning Ship**, con la posibilidad de hacer zoom y experimentar con diferentes esquemas de color.  
¡Disfruta la magia de los fractales! 🎨🔍

## 🎯 Funcionalidades

- **Conjuntos de fractales disponibles:**
  - **Julia**: Explora el conjunto de Julia con parámetros personalizables. 🌊
  - **Mandelbrot**: Sumérgete en el misterioso conjunto de Mandelbrot. 🔮
  - **Burning Ship**: Descubre el enigmático conjunto Burning Ship. 🚢🔥

- **Interactividad:**
  - 🌟 **Zoom infinito** con la rueda del ratón (incluso dentro de los límites de tu ordenador).
  - 🧑‍💻 **Cambio de fractales** a través de la línea de comandos.
  - 🎨 **Esquemas de color psicodélicos** para una experiencia visual única.

- **Controles:**
  - **Esc**: Cerrar la ventana y salir del programa. 🚪
  - **Flechas de dirección**: Mover el lienzo del fractal. 🧭
  - **Barra espaciadora**: Cambiar el esquema de color. 🎨
  - **Cruz en la ventana**: Cerrar la ventana de manera limpia. ❌

## 📦 Requisitos

- **MiniLibX**: Necesitarás la biblioteca MiniLibX para el manejo gráfico.
- **libft**: Este proyecto utiliza la biblioteca `libft` para funciones estándar de C.

## 🖥️ Compilación e Instalación
⚠️ **IMPORTANTE** ⚠️
Una vez clones `fract-ol`, debes clonar `libft` dentro del repositorio y nombrarlo **libft** para que funcione.  


📂 fract-ol/
```
git clone https://github.com/jcurtidodev/libft-42.git
```
Una vez hecho, continua haciendo:
```bash
make
```
Esto generará el ejecutable `fract-ol`.  


Para limpiar archivos objeto y binarios:

```Makefile
make clean      # Elimina archivos objeto
make fclean     # Elimina archivos objeto y ejecutables
make re         # Realiza una recompilación completa
```
## 🚀 Uso
Elige entre los diferentes fractales y disfruta. Los parámetros adicionales para **`julia`** se pasan por la línea de comandos con un espacio como separador.
- **Julia**
```C
./fract-ol julia 0.285 -0.01
```
Otras combinaciones que recomiendo:  
`-0.8 0.15`   
`-0.70176 -0.3842`  
`0.3 0.6`  
- **Mandelbrot**
```C
./fract-ol mandelbrot
```
- **Burning ship**
```C
./fract-ol burning_ship
```
## 🎮 Controles
- **Rueda del ratón:** Zoom in y zoom out.
- **Flechas del teclado:** Mover la vista del fractal.
- **Espacio**: Cambiar esquema de color.
- **Esc** / **X** (ventana): Cerrar el programa.
## 🏗️ Estructura del codigo
```
📂 fractal/
├── 📜 Makefile          # Compilación del proyecto
├── 📜 burning_ship.c    # Código para el fractal Burning Ship
├── 📜 fract-ol.c        # Código principal para renderizado y gestión
├── 📜 events.c          # Gestión de eventos de la ventana
├── 📜 fract_ol.h        # Archivo de cabecera
├── 📜 julia.c           # Código para el fractal Julia
├── 📜 main.c            # Función principal
├── 📜 mandelbrot.c      # Código para el fractal Mandelbrot
├── 📜 utils.c           # Funciones auxiliares
└── 📂 minilibx-linux/   # MiniLibX
```
## 🛠️ Funciones Permitidas
- `open`, `close`, `read`, `write`
- `malloc`, `free`, `perror`
- `strerror`, `exit`
- Todas las funciones de la librería de matemáticas (-lm, man 3 `math`)
- Todas las funciones de la `MiniLibX`
- `ft_printf` y/o cualquier función de **libft**
## 🏆 Reglas y restricciones:
- Se debe utilizar la miniLibX, ya sea la versión disponible en los ordenadores del campus o la que se instale usando sus fuentes originales.
- El Makefile debe compilar los archivos fuente y no debe realizar relink.
- Las variables globales están prohibidas.
- El programa debe ofrecer los conjuntos de Julia y Mandelbrot.
- El programa debe mostrar la imagen en una ventana.
- El manejo de la ventana debe ser fluido (cambio de ventana, minimización, etc.).
- La tecla ESC debe cerrar la ventana y salir del programa de manera limpia.
- Hacer click en la cruz del marco de la ventana debe cerrarla y salir del programa de manera limpia.
- El uso de imágenes de la MiniLibX es obligatorio.
- La rueda del ratón debe permitir hacer zoom in y zoom out (casi infinitamente).
- El programa debe crear un conjunto de Julia diferente mediante parámetros de la CLI.
- Si no se introduce un parámetro o si es inválido, el programa debe mostrar una lista de parámetros disponibles y terminar correctamente.
- Se deben usar colores para representar la profundidad de los fractales.
- Los efectos psicodélicos son recomendables.
## 🤝 Créditos
Proyecto desarrollado por `jcurtidodev` como parte del cursus de **42 School**.
