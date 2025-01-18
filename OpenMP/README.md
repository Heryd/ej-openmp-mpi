## **OpenMP**

Este documento describe los pasos para compilar y ejecutar los códigos de ejemplo para OpenMP en una instancia EC2 de AWS.

### **1. Configuraci�n del Entorno**

1. **Lanzar una instancia EC2 en AWS:**
   - Elige Amazon Linux 2 como sistema operativo.
   - Selecciona un tipo de instancia (recomendado: `t2.micro` o superior).
   - Configura las reglas del grupo de seguridad para permitir SSH (puerto 22).

2. **Conectar a la instancia:**
   ```bash
   ssh -i "clave.pem" ec2-user@<IP_INSTANCIA>
   ```

3. **Actualizar los paquetes:**
   ```bash
   sudo yum update -y
   ```

4. **Instalar GCC con soporte para OpenMP:**
   ```bash
   sudo yum groupinstall "Development Tools" -y
   ```

5. **Verificar la instalaci�n:**
   ```bash
   gcc --version
   ```

### **2. Estructura del Proyecto OpenMP**

Ubicaci�n de los archivos:
```
/home/ec2-user/EJEMPLOS_OpenMP_MPI/OpenMP/
|-- Paralelo.cpp
|-- Secuencial.cpp
```

### **3. Compilaci�n**

Para compilar los programas:

- **Secuencial:**
  ```bash
  g++ -fopenmp -o Secuencial_OpenMP Secuencial.cpp
  ```

- **Paralelo:**
  ```bash
  g++ -fopenmp -o Paralelo_OpenMP Paralelo.cpp
  ```

### **4. Ejecuci�n**

Ejecuta los binarios compilados:

- **Secuencial:**
  ```bash
  ./Secuencial_OpenMP
  ```

- **Paralelo:**
  ```bash
  ./Paralelo_OpenMP
  ```

---