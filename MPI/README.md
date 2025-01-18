## **MPI**

Este documento describe los pasos para compilar y ejecutar los códigos de ejemplo para MPI en una instancia EC2 de AWS.

### **1. Configuración del Entorno**

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

4. **Instalar MPI (mpich):**
   ```bash
   sudo yum install mpich -y
   ```

5. **Agregar MPI al PATH:**
   ```bash
   echo 'export PATH=/usr/lib64/mpich/bin:$PATH' >> ~/.bashrc
   source ~/.bashrc
   ```

6. **Verificar la instalación:**
   ```bash
   mpirun --version
   ```

### **2. Estructura del Proyecto MPI**

Ubicación de los archivos:
```
/home/ec2-user/EJEMPLOS_OpenMP_MPI/MPI/
|-- Paralelo.cpp
|-- Secuencial.cpp
```

### **3. Compilación**

Para compilar los programas:

- **Secuencial:**
  ```bash
  mpic++ -o Secuencial Secuencial.cpp
  ```

- **Paralelo:**
  ```bash
  mpic++ -o Paralelo Paralelo.cpp
  ```

### **4. Ejecución**

Ejecuta los binarios compilados:

- **Secuencial:**
  ```bash
  mpirun -np 1 ./Secuencial
  ```

- **Paralelo:**
  ```bash
  mpirun -np 4 ./Paralelo
  ```

---
