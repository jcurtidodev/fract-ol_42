# 🌀 Fract-ol - Explora los Fractales 🌌

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

## 🖥️ Instalación
⚠️ **IMPORTANTE** ⚠️
Una vez clones `fract-ol`, debes clonar `libft` dentro del repositorio para que funcione.  


📂 fract-ol/
```
git clone https://github.com/jcurtidodev/libft-42.git
```
1. Una vez clonado, compila:
```bash
make
```
2. Ejecuta el fractal de tu elección:
```bash
./fract-ol mandelbrot
```
## 🎮 Uso
Elige entre los diferentes fractales y disfruta. Los parámetros adicionales para **julia** se pasan por la línea de comandos con un espacio como separador.
```bash
./fract-ol julia -0.7 -0.328
```
