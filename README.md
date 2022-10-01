# Proyecto de cloud-CS3P02
## Integrantes
- Carlos Esteban Guerrero Robles

## Aplicación

Sistema de registro de envios a lavandería.

### Características

La aplicación permite registrar varios tipos de prendas que el usuario posea.
A partir de la prendas registradas se permite llevar un manejo de que prendas se han llevado a un servicio de lavandería.

De esta forma se lleva un control de las prendas evitando así perder alguna al usar un servicio externo de lavado.

### Funcionalidad

Actualmente la aplicación se ejecuta mediante un CLI, a través del cual se puede realizar el agregado de nuevas prendas; así como el generado de tickets de registro.

Sin embargo, el sistema actualmente no posee un funcionalidad multiusuario para soportar el ingreso de prendas y tickets de parte de más de una persona.

### Arquitectura

La arquitectura actual de la aplicación es monolítica. Realizando todo el manejo desde la única instancia que posee.   
A continuación se muestra un diagrama de la arquitectura actual:

![monolith_architecture](documentation/app_architecture/monolith/monolith_diagram.drawio.png)

Sin embargo, con el desarrollo de este proyecto se planea también realizar el cambio de arquitectura a una de micro-servicios.  
En este sentido, se planea terminar con una arquitectura como la que muestra el siguiente diagrama:

![microServices_architecture](documentation/app_architecture/microServices/microServices_diagram.drawio.png)

Esto permitirá realizar las pruebas, experimentos y despliegue de la aplicación en tecnologías cloud.

### Instanciación/Ejecución

Dado que actualmente la aplicación se encuentra en una versión monolítica no se puede realizar una instanciación *perce* del sistema.

Sin embargo, se dispone de un archivo [Makefile](Makefile) el cual puede ser ejecutando con el comando bash `make`\.  
Este proceso creara una carpeta target (laundry-shipments-system) donde se encontrará el ejecutable de la aplicación.  
Adicionalmente, para facilitar la "desinstalación" del programa se puede ejecutar `make clean` que se encargara de eliminar la carpeta target y su contenido (tickets y prendas generadas en el uso de la aplicación).
