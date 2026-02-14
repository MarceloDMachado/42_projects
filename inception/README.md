*This project has been created as part of the 42 curriculum by madias-m.*

# Inception - 42 Project

## Description
O projeto **Inception** consiste na criação de uma infraestrutura de microserviços utilizando **Docker Compose**. O objetivo principal é configurar um ambiente de múltiplos containers (Nginx, MariaDB e WordPress) rodando em uma máquina virtual Debian, garantindo que cada serviço possua seu próprio container dedicado e se comunique de forma segura e isolada através de redes privadas.

Este projeto foca na orquestração de containers, gerenciamento de volumes para persistência de dados e automação de infraestrutura, seguindo os princípios fundamentais de DevOps.

### Design Choices & Comparisons

* **Virtual Machines vs Docker**: 
    Diferente das VMs, que emulam um hardware completo e rodam um Kernel próprio (o que consome muitos recursos), o Docker utiliza **Containers** que compartilham o Kernel do sistema operacional hospedeiro. Isso torna o Inception muito mais leve e rápido para iniciar.
* **Secrets vs Environment Variables**: 
    Variáveis de ambiente são úteis para configurações não sensíveis, mas podem ser expostas via comandos de inspeção. Optamos pelo uso de arquivos `.env` e, idealmente, **Secrets** para dados sensíveis como senhas do banco de dados, garantindo que essas informações não fiquem visíveis no histórico de processos.
* **Docker Network vs Host Network**: 
    Utilizamos **Docker Networks (Bridge)** para criar um isolamento real. Enquanto a *Host Network* compartilha a rede do sistema hospedeiro (removendo o isolamento), a rede interna do Docker permite que os containers se comuniquem via DNS interno (ex: `wordpress` conversa com `mariadb`) sem expor portas desnecessárias ao mundo externo.
* **Docker Volumes vs Bind Mounts**: 
    Para persistência de dados (DB e arquivos do site), utilizamos **Docker Volumes**. Diferente dos *Bind Mounts* (que dependem da estrutura de pastas do host), os volumes são gerenciados pelo Docker, garantindo melhor performance no macOS/Windows e maior isolamento dos dados.

---

## Instructions

### Compilation and Execution
Para rodar o projeto, você deve ter o `docker` e o `docker-compose` instalados em uma máquina Linux (Debian/Ubuntu).

1.  **Configuração de Host**: Adicione `madias-m.42.fr` ao seu arquivo `/etc/hosts` apontando para `127.0.0.1`.
2.  **Preparação**: Certifique-se de que os diretórios de dados existam conforme configurado no seu `.env` (ex: `/home/login/data/`).
3.  **Build e Run**:
    make up
    *Este comando iniciará o Docker Compose em modo detach, baixando as imagens e configurando os containers.*
4.  **Comandos Principais**

    - make stop: Para os containers sem removê-los.
    - make clean: Remove containers e redes.
    - make fclean: Remove containers, redes, imagens e volumes (limpeza total).

---

## Resources

### References
* [Docker Documentation](https://docs.docker.com/): Documentação oficial para criação de Dockerfiles e redes.
* [Nginx TLS Configuration](https://nginx.org/en/docs/http/configuring_https_servers.html): Guia para configuração de certificados SSL/TLS.
* [WordPress CLI](https://make.wordpress.org/cli/handbook/guides/installing/): Utilizado para automatizar a instalação do site sem interface gráfica.

### AI Usage
A Inteligência Artificial (Gemini) foi utilizada neste projeto para:
* **Explicação Teórica**: Esclarecer a diferença técnica entre o isolamento de rede do Docker e do Host.
* **Debugging de Scripts**: Auxílio na identificação de erros de sintaxe em scripts de entrada (`entrypoint.sh`) para o MariaDB.
* **Documentação**: Estruturação inicial deste arquivo README seguindo os padrões solicitados pela 42.

---